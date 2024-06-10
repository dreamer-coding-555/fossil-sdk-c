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
#include "fossil/threads/spinlocks.h"
#include "fossil/common/common.h"

int32_t fossil_spinlock_create(xspinlock_t *lock) {
    if (!lock) return FOSSIL_ERROR;

#ifdef _WIN32
    InitializeCriticalSection(lock);
    return FOSSIL_SUCCESS;
#else
    atomic_flag_clear(lock);
    return FOSSIL_SUCCESS;
#endif
}

int32_t fossil_spinlock_erase(xspinlock_t *lock) {
    if (!lock) return FOSSIL_ERROR;

#ifdef _WIN32
    DeleteCriticalSection(lock);
    return FOSSIL_SUCCESS;
#else
    // Nothing to do for erasing spinlock on POSIX systems
    return FOSSIL_SUCCESS;
#endif
}

int32_t fossil_spinlock_lock(xspinlock_t *lock) {
    if (!lock) return FOSSIL_ERROR;

#ifdef _WIN32
    EnterCriticalSection(lock);
    return FOSSIL_SUCCESS;
#else
    while (atomic_flag_test_and_set(lock)) {
        // Spin until the lock is acquired
    }
    return FOSSIL_SUCCESS;
#endif
}

int32_t fossil_spinlock_unlock(xspinlock_t *lock) {
    if (!lock) return FOSSIL_ERROR;

#ifdef _WIN32
    LeaveCriticalSection(lock);
    return FOSSIL_SUCCESS;
#else
    atomic_flag_clear(lock);
    return FOSSIL_SUCCESS;
#endif
}

int32_t fossil_spinlock_trylock(xspinlock_t *lock) {
    if (!lock) return FOSSIL_ERROR;

#ifdef _WIN32
    // Windows does not have a trylock function for CRITICAL_SECTION
    return FOSSIL_ERROR;
#else
    if (atomic_flag_test_and_set(lock)) {
        return FOSSIL_ERROR; // Lock was not acquired
    } else {
        return FOSSIL_SUCCESS; // Lock acquired successfully
    }
#endif
}
