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
#include "fossil/threads/mutexs.h"
#include "fossil/common/common.h"

int32_t fossil_mutex_create(fossil_xmutex_t *mutex) {
    if (!mutex) return FOSSIL_ERROR;

#ifdef _WIN32
    *mutex = CreateMutex(cnullptr, FALSE, cnullptr);
    if (*mutex == cnullptr) return FOSSIL_ERROR;
    return FOSSIL_SUCCESS;
#else
    return pthread_mutex_init(mutex, cnullptr);
#endif
}

int32_t fossil_mutex_erase(fossil_xmutex_t *mutex) {
    if (!mutex) return FOSSIL_ERROR;

#ifdef _WIN32
    CloseHandle(*mutex);
    return FOSSIL_SUCCESS;
#else
    return pthread_mutex_destroy(mutex);
#endif
}

int32_t fossil_mutex_lock(fossil_xmutex_t *mutex) {
    if (!mutex) return FOSSIL_ERROR;

#ifdef _WIN32
    DWORD result = WaitForSingleObject(*mutex, INFINITE);
    if (result == WAIT_OBJECT_0 || result == WAIT_ABANDONED) {
        return FOSSIL_SUCCESS;
    } else {
        return FOSSIL_ERROR;
    }
#else
    return pthread_mutex_lock(mutex);
#endif
}

int32_t fossil_mutex_unlock(fossil_xmutex_t *mutex) {
    if (!mutex) return FOSSIL_ERROR;

#ifdef _WIN32
    return ReleaseMutex(*mutex) ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#else
    return pthread_mutex_unlock(mutex);
#endif
}

int32_t fossil_mutex_trylock(fossil_xmutex_t *mutex) {
    if (!mutex) return FOSSIL_ERROR;

#ifdef _WIN32
    DWORD result = WaitForSingleObject(*mutex, 0);
    if (result == WAIT_OBJECT_0) {
        return FOSSIL_SUCCESS;
    } else if (result == WAIT_TIMEOUT) {
        return FOSSIL_ERROR;
    } else {
        return FOSSIL_ERROR;
    }
#else
    return pthread_mutex_trylock(mutex);
#endif
}
