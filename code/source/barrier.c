/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/threads/barrier.h"
#include "fossil/common/common.h"

// Implement barrier functions
int32_t fossil_barrier_create(xbarrier_t *barrier, uint32_t count) {
    if (!barrier) return FOSSIL_ERROR;

#ifdef _WIN32
    // Initialize the barrier using CreateEvent
    barrier->semaphore = CreateSemaphore(cnullptr, 0, count, cnullptr);
    if (barrier->semaphore == cnullptr) return FOSSIL_ERROR;
    barrier->count = ATOMIC_VAR_INIT(0);
    barrier->total = ATOMIC_VAR_INIT(count);
    InitializeCriticalSection(&barrier->mutex);
#else
    // Initialize the barrier using pthread_mutex_init and pthread_cond_init
    if (pthread_mutex_init(&(barrier->mutex), cnullptr) != 0) return FOSSIL_ERROR;
    if (pthread_cond_init(&(barrier->cond), cnullptr) != 0) {
        pthread_mutex_destroy(&(barrier->mutex));
        return FOSSIL_ERROR;
    }
    atomic_init(&(barrier->count), 0);
    atomic_init(&(barrier->total), count);
#endif

    return FOSSIL_SUCCESS;
}

int32_t fossil_barrier_erase(xbarrier_t *barrier) {
    if (!barrier) return FOSSIL_ERROR;

#ifdef _WIN32
    // Destroy the barrier using CloseHandle and DeleteCriticalSection
    CloseHandle(barrier->semaphore);
    DeleteCriticalSection(&barrier->mutex);
#else
    // Destroy the barrier using pthread_mutex_destroy and pthread_cond_destroy
    pthread_mutex_destroy(&(barrier->mutex));
    pthread_cond_destroy(&(barrier->cond));
#endif

    return FOSSIL_SUCCESS;
}

int32_t fossil_barrier_wait(xbarrier_t *barrier) {
    if (!barrier) return FOSSIL_ERROR;

#ifdef _WIN32
    // Wait on the barrier using WaitForSingleObject
    WaitForSingleObject(barrier->semaphore, INFINITE);
    EnterCriticalSection(&barrier->mutex);
    int count = atomic_fetch_add(&(barrier->count), 1) + 1;
    LeaveCriticalSection(&barrier->mutex);
    if (count >= atomic_load(&(barrier->total))) {
        for (int i = 0; i < count - 1; ++i) {
            ReleaseSemaphore(barrier->semaphore, 1, cnullptr);
        }
        atomic_store(&(barrier->count), 0);
        return FOSSIL_SUCCESS; // Barrier was passed without tripping
    }
    else {
        WaitForSingleObject(barrier->semaphore, INFINITE);
        return FOSSIL_FAILURE; // Barrier was tripped
    }
#else
    // Wait on the barrier using pthread_mutex_lock and pthread_cond_wait
    pthread_mutex_lock(&(barrier->mutex));
    atomic_fetch_add(&(barrier->count), 1);
    if (atomic_load(&(barrier->count)) >= atomic_load(&(barrier->total))) {
        pthread_cond_broadcast(&(barrier->cond));
        atomic_store(&(barrier->count), 0);
        pthread_mutex_unlock(&(barrier->mutex));
        return FOSSIL_SUCCESS; // Barrier was passed without tripping
    } else {
        pthread_cond_wait(&(barrier->cond), &(barrier->mutex));
        pthread_mutex_unlock(&(barrier->mutex));
        return FOSSIL_FAILURE; // Barrier was tripped
    }
#endif
}
