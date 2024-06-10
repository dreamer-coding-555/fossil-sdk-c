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
#ifndef FOSSIL_THREADS_H
#define FOSSIL_THREADS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "threads/condition.h"      /**< Include the condition header for thread synchronization */
#include "threads/thread.h"         /**< Include the thread header for creating and managing threads */
#include "threads/threadlocal.h"    /**< Include the threadlocal header for thread-local storage */
#include "threads/threadpool.h"     /**< Include the threadpool header for managing thread pools */
#include "threads/barrier.h"        /**< Include the barrier header for thread synchronization */
#include "threads/task.h"           /**< Include the task header for task-based parallelism */
#include "threads/mutexs.h"         /**< Include the mutexs header for mutual exclusion */
#include "threads/semaphores.h"     /**< Include the semaphores header for synchronization */
#include "threads/spinlocks.h"      /**< Include the spinlocks header for low-level synchronization */

#ifdef __cplusplus
}
#endif

#endif
