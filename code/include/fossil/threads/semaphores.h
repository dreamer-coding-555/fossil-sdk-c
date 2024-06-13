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
#ifndef FOSSIL_THREADS_SEMAPHORES_H
#define FOSSIL_THREADS_SEMAPHORES_H

#include <stdatomic.h>
#include "mutexs.h"
#include "condition.h"
#include <stdint.h>

typedef struct {
    atomic_int value;
    fossil_xmutex_t mutex;
    fossil_xcond_t cond;
} fossil_xsem_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Initializes a semaphore with the specified initial value.
 *
 * @param sem Pointer to the semaphore to initialize.
 * @param value The initial value of the semaphore.
 * @return int32_t 0 if the semaphore is successfully initialized, -1 otherwise.
 */
int32_t fossil_sem_create(fossil_xsem_t *sem, uint32_t value);

/**
 * @brief Destroys a semaphore.
 *
 * @param sem Pointer to the semaphore to destroy.
 * @return int32_t 0 if the semaphore is successfully destroyed, -1 otherwise.
 */
int32_t fossil_sem_erase(fossil_xsem_t *sem);

/**
 * @brief Decrements (locks) the semaphore. If the semaphore's value is greater
 * than zero, the decrement proceeds, and the function returns immediately. If
 * the semaphore's value is zero, the function blocks until the semaphore's value
 * is greater than zero and the decrement can proceed.
 *
 * @param sem Pointer to the semaphore to lock.
 * @return int32_t 0 if the semaphore is successfully locked, -1 otherwise.
 */
int32_t fossil_sem_wait(fossil_xsem_t *sem);

/**
 * @brief Increments (unlocks) the semaphore. If the semaphore's value is zero and
 * a thread is waiting, the waiting thread is unblocked.
 *
 * @param sem Pointer to the semaphore to unlock.
 * @return int32_t 0 if the semaphore is successfully unlocked, -1 otherwise.
 */
int32_t fossil_sem_post(fossil_xsem_t *sem);

/**
 * @brief Attempts to decrement (lock) the semaphore. If the semaphore's value is
 * greater than zero, the decrement proceeds, and the function returns immediately.
 * If the semaphore's value is zero, the function returns immediately with a value
 * of -1.
 *
 * @param sem Pointer to the semaphore to try to lock.
 * @return int32_t 0 if the semaphore is successfully locked, -1 otherwise.
 */
int32_t fossil_sem_trywait(fossil_xsem_t *sem);


#ifdef __cplusplus
}
#endif

#endif
