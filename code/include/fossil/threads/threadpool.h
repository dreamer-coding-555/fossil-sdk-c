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
#ifndef FOSSIL_THREADS_THREADPOOL_H
#define FOSSIL_THREADS_THREADPOOL_H

#include "thread.h"
#include "mutexs.h"
#include "condition.h"
#include "task.h"
#include <stdatomic.h>
#include <stdint.h>

// Macro for defining a task
#ifdef _WIN32
#define xtask(name) void name(LPVOID arg)
#else
#define xtask(name) void name(void* arg)
#endif

typedef struct {
    fossil_xthread_t *threads;
    int32_t thread_count;
    fossil_xmutex_t queue_mutex;
    fossil_xcond_t queue_cond;
    fossil_xtask_t *task_queue;
    int32_t queue_size;
    int32_t queue_front;
    int32_t queue_rear;
    atomic_int shutdown;
    atomic_int task_count;
} fossil_xthread_pool_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Creates a thread pool with the specified number of threads and task queue size.
 *
 * @param pool Pointer to the thread pool structure to initialize.
 * @param thread_count The number of worker threads to create in the pool.
 * @param queue_size The maximum size of the task queue in the pool.
 * @return int32_t 0 if the thread pool is successfully created, -1 otherwise.
 */
int32_t fossil_thread_pool_create(fossil_xthread_pool_t *pool, int32_t thread_count, int32_t queue_size);

/**
 * @brief Shuts down and deallocates resources associated with a thread pool.
 *
 * @param pool Pointer to the thread pool structure to erase.
 * @return int32_t 0 if the thread pool is successfully erased, -1 otherwise.
 */
int32_t fossil_thread_pool_erase(fossil_xthread_pool_t *pool);

/**
 * @brief Adds a task to the thread pool for execution.
 *
 * @param pool Pointer to the thread pool structure.
 * @param task_func Pointer to the function to execute as a task.
 * @param arg Pointer to the argument to pass to the task function.
 * @return int32_t 0 if the task is successfully added to the pool, -1 if the task queue is full.
 */
int32_t fossil_thread_pool_add_task(fossil_xthread_pool_t *pool, fossil_xtask_func_t task_func, void *arg);

#ifdef __cplusplus
}
#endif

#endif
