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
#ifndef FOSSIL_THREADS_BARRIER_H
#define FOSSIL_THREADS_BARRIER_H

#include <stdint.h>
#include <stdatomic.h>

#ifdef _WIN32
// Windows-specific headers
#include <windows.h>
#else
// POSIX-specific headers
#include <pthread.h>
#endif

// Define the barrier structure
typedef struct {
#ifdef _WIN32
    HANDLE semaphore;   /**< Windows semaphore handle. */
    atomic_int count;   /**< Count of threads that have reached the barrier. */
    atomic_int total;   /**< Total number of threads expected to reach the barrier. */
    CRITICAL_SECTION mutex; /**< Windows critical section for synchronization. */
#else
    pthread_mutex_t mutex;  /**< POSIX mutex for synchronization. */
    pthread_cond_t cond;    /**< POSIX condition variable for signaling. */
    atomic_int count;       /**< Count of threads that have reached the barrier. */
    atomic_int total;       /**< Total number of threads expected to reach the barrier. */
#endif
} xbarrier_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Initializes a barrier with the specified count.
 *
 * @param barrier Pointer to the barrier to initialize.
 * @param count The count of threads required to reach the barrier.
 * @return int32_t 0 if the barrier is successfully initialized, -1 otherwise.
 */
int32_t fossil_barrier_create(xbarrier_t *barrier, uint32_t count);

/**
 * @brief Destroys a barrier.
 *
 * @param barrier Pointer to the barrier to destroy.
 * @return int32_t 0 if the barrier is successfully destroyed, -1 otherwise.
 */
int32_t fossil_barrier_erase(xbarrier_t *barrier);

/**
 * @brief Waits for all threads to reach the barrier.
 *
 * @param barrier Pointer to the barrier to wait on.
 * @return int32_t 0 if all threads successfully reach the barrier, -1 otherwise.
 */
int32_t fossil_barrier_wait(xbarrier_t *barrier);

#ifdef __cplusplus
}
#endif

#endif
