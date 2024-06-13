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
#include "fossil/threads/condition.h"
#include "fossil/common/common.h"

#ifdef _WIN32
// Ensure we are targeting Windows Vista or later
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#elif _WIN32_WINNT < 0x0600
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <windows.h> // Include Windows-specific header for condition variables
#include <synchapi.h>
#endif


int32_t fossil_cond_create(fossil_xcond_t *cond) {
    if (!cond) return FOSSIL_ERROR;

#ifdef _WIN32
    InitializeConditionVariable(cond);
    return FOSSIL_SUCCESS;
#else
    return pthread_cond_init(cond, cnullptr);
#endif
}

int32_t fossil_cond_erase(fossil_xcond_t *cond) {
    if (!cond) return FOSSIL_ERROR;

#ifdef _WIN32
    // Windows does not require cleanup for CONDITION_VARIABLE
    return FOSSIL_SUCCESS;
#else
    return pthread_cond_destroy(cond);
#endif
}

int32_t fossil_cond_wait(fossil_xcond_t *cond, fossil_xmutex_t *mutex) {
    if (!cond || !mutex) return FOSSIL_ERROR;

#ifdef _WIN32
    // On Windows, we need to pass the actual CRITICAL_SECTION pointer to the condition variable wait function
    SleepConditionVariableCS(cond, *mutex, INFINITE);
    return FOSSIL_SUCCESS;
#else
    return pthread_cond_wait(cond, mutex);
#endif
}

int32_t fossil_cond_signal(fossil_xcond_t *cond) {
    if (!cond) return FOSSIL_ERROR;

#ifdef _WIN32
    WakeConditionVariable(cond);
    return FOSSIL_SUCCESS;
#else
    return pthread_cond_signal(cond);
#endif
}

int32_t fossil_cond_broadcast(fossil_xcond_t *cond) {
    if (!cond) return FOSSIL_ERROR;

#ifdef _WIN32
    WakeAllConditionVariable(cond);
    return FOSSIL_SUCCESS;
#else
    return pthread_cond_broadcast(cond);
#endif
}
