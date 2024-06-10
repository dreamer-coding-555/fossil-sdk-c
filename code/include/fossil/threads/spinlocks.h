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
#ifndef FOSSIL_THREADS_SPINLOCKS_H
#define FOSSIL_THREADS_SPINLOCKS_H

#ifdef _WIN32
#include <windows.h>
typedef CRITICAL_SECTION xspinlock_t;
#else
#include <pthread.h>
#include <stdatomic.h>
typedef atomic_flag xspinlock_t;
#endif
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Initializes a spinlock.
 *
 * @param lock Pointer to the spinlock to initialize.
 * @return int32_t 0 if the spinlock is successfully initialized, -1 otherwise.
 */
int32_t fossil_spinlock_create(xspinlock_t *lock);

/**
 * @brief Destroys a spinlock.
 *
 * @param lock Pointer to the spinlock to destroy.
 * @return int32_t 0 if the spinlock is successfully destroyed, -1 otherwise.
 */
int32_t fossil_spinlock_erase(xspinlock_t *lock);

/**
 * @brief Acquires a spinlock, blocking if necessary until the lock is available.
 *
 * @param lock Pointer to the spinlock to acquire.
 * @return int32_t 0 if the spinlock is successfully acquired, -1 otherwise.
 */
int32_t fossil_spinlock_lock(xspinlock_t *lock);

/**
 * @brief Releases a spinlock.
 *
 * @param lock Pointer to the spinlock to release.
 * @return int32_t 0 if the spinlock is successfully released, -1 otherwise.
 */
int32_t fossil_spinlock_unlock(xspinlock_t *lock);

/**
 * @brief Attempts to acquire a spinlock without blocking.
 *
 * @param lock Pointer to the spinlock to acquire.
 * @return int32_t 0 if the spinlock is successfully acquired, -1 otherwise.
 */
int32_t fossil_spinlock_trylock(xspinlock_t *lock);

#ifdef __cplusplus
}
#endif

#endif
