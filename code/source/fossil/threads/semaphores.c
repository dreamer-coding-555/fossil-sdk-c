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
#include "fossil/threads/semaphores.h"
#include "fossil/common/common.h"

int32_t fossil_sem_create(fossil_xsem_t *sem, uint32_t value) {
    if (!sem) return FOSSIL_ERROR;

    atomic_init(&sem->value, value);
    if (fossil_mutex_create(&sem->mutex) != 0) return FOSSIL_ERROR;
    if (fossil_cond_create(&sem->cond) != 0) {
        fossil_mutex_erase(&sem->mutex);
        return FOSSIL_ERROR;
    }
    return FOSSIL_SUCCESS;
}

int32_t fossil_sem_erase(fossil_xsem_t *sem) {
    if (!sem) return FOSSIL_ERROR;

    fossil_cond_erase(&sem->cond);
    fossil_mutex_erase(&sem->mutex);
    return FOSSIL_SUCCESS;
}

int32_t fossil_sem_wait(fossil_xsem_t *sem) {
    if (!sem) return FOSSIL_ERROR;

    fossil_mutex_lock(&sem->mutex);

    while (atomic_load(&sem->value) <= 0) {
        fossil_cond_wait(&sem->cond, &sem->mutex);
    }

    atomic_fetch_sub(&sem->value, 1);

    fossil_mutex_unlock(&sem->mutex);

    return FOSSIL_SUCCESS;
}

int32_t fossil_sem_post(fossil_xsem_t *sem) {
    if (!sem) return FOSSIL_ERROR;

    fossil_mutex_lock(&sem->mutex);

    atomic_fetch_add(&sem->value, 1);
    fossil_cond_signal(&sem->cond);

    fossil_mutex_unlock(&sem->mutex);

    return FOSSIL_SUCCESS;
}

int32_t fossil_sem_trywait(fossil_xsem_t *sem) {
    if (!sem) return FOSSIL_ERROR;

    fossil_mutex_lock(&sem->mutex);

    if (atomic_load(&sem->value) > 0) {
        atomic_fetch_sub(&sem->value, 1);
        fossil_mutex_unlock(&sem->mutex);
        return FOSSIL_SUCCESS;
    } else {
        fossil_mutex_unlock(&sem->mutex);
        return FOSSIL_ERROR; // Semaphore value is zero, cannot decrement
    }
}
