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
#ifndef FOSSIL_THREADS_COND_H
#define FOSSIL_THREADS_COND_H

#ifdef _WIN32
#include <windows.h>
typedef CONDITION_VARIABLE xcond_t;
#else
#include <pthread.h>
typedef pthread_cond_t xcond_t;
#endif
#include <stdint.h>

#include "mutexs.h" // for the XMutex type

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Initializes a condition variable.
 *
 * @param cond Pointer to the condition variable to initialize.
 * @return int32_t 0 if the condition variable is successfully initialized, -1 otherwise.
 */
int32_t fossil_cond_create(xcond_t *cond);

/**
 * @brief Destroys a condition variable.
 *
 * @param cond Pointer to the condition variable to destroy.
 * @return int32_t 0 if the condition variable is successfully destroyed, -1 otherwise.
 */
int32_t fossil_cond_erase(xcond_t *cond);

/**
 * @brief Waits for a condition variable to be signaled. The mutex must be locked before calling this function.
 *
 * @param cond Pointer to the condition variable to wait on.
 * @param mutex Pointer to the mutex that is used with the condition variable.
 * @return int32_t 0 if the wait is successful and the condition variable is signaled, -1 otherwise.
 */
int32_t fossil_cond_wait(xcond_t *cond, xmutex_t *mutex);

/**
 * @brief Signals a condition variable, waking up one of the threads that are waiting on the condition variable.
 *
 * @param cond Pointer to the condition variable to signal.
 * @return int32_t 0 if the condition variable is successfully signaled, -1 otherwise.
 */
int32_t fossil_cond_signal(xcond_t *cond);

/**
 * @brief Broadcasts a condition variable, waking up all threads that are waiting on the condition variable.
 *
 * @param cond Pointer to the condition variable to broadcast.
 * @return int32_t 0 if the condition variable is successfully broadcasted, -1 otherwise.
 */
int32_t fossil_cond_broadcast(xcond_t *cond);

#ifdef __cplusplus
}
#endif

#endif
