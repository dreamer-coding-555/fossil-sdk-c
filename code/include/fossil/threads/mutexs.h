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
#ifndef FOSSIL_THREADS_MUTEXS_H
#define FOSSIL_THREADS_MUTEXS_H

#ifdef _WIN32
#include <windows.h>
typedef CRITICAL_SECTION *fossil_xmutex_t;
#else
#include <pthread.h>
typedef pthread_mutex_t fossil_xmutex_t;
#endif
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Initializes a mutex.
 *
 * @param mutex Pointer to the mutex to initialize.
 * @return int32_t 0 if the mutex is successfully initialized, -1 otherwise.
 */
int32_t fossil_mutex_create(fossil_xmutex_t *mutex);

/**
 * @brief Destroys a mutex.
 *
 * @param mutex Pointer to the mutex to destroy.
 * @return int32_t 0 if the mutex is successfully destroyed, -1 otherwise.
 */
int32_t fossil_mutex_erase(fossil_xmutex_t *mutex);

/**
 * @brief Locks a mutex, blocking if necessary until the mutex is available.
 *
 * @param mutex Pointer to the mutex to lock.
 * @return int32_t 0 if the mutex is successfully locked, -1 otherwise.
 */
int32_t fossil_mutex_lock(fossil_xmutex_t *mutex);

/**
 * @brief Unlocks a mutex.
 *
 * @param mutex Pointer to the mutex to unlock.
 * @return int32_t 0 if the mutex is successfully unlocked, -1 otherwise.
 */
int32_t fossil_mutex_unlock(fossil_xmutex_t *mutex);

/**
 * @brief Attempts to lock a mutex without blocking.
 *
 * @param mutex Pointer to the mutex to attempt to lock.
 * @return int32_t 0 if the mutex is successfully locked, -1 otherwise.
 */
int32_t fossil_mutex_trylock(fossil_xmutex_t *mutex);

#ifdef __cplusplus
}
#endif

#endif
