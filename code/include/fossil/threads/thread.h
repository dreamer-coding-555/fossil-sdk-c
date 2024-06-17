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
#ifndef FOSSIL_THREADS_THREAD_H
#define FOSSIL_THREADS_THREAD_H

#ifdef _WIN32
#include <windows.h>
typedef HANDLE fossil_xthread_t;
#else
#include <pthread.h>
typedef pthread_t fossil_xthread_t;
#endif
#include "task.h"
#include <stdint.h>

#ifdef _WIN32
typedef struct {
    DWORD stack_size;
    int32_t detach_state;
} fossil_xthread_attr_t;
#else
#include <pthread.h>
typedef pthread_attr_t fossil_xthread_attr_t;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Creates a new thread with the specified attributes and starts execution at the specified task function.
 *
 * @param thread Pointer to store the created thread ID.
 * @param attr Pointer to the thread attributes, or NULL for default attributes.
 * @param task Pointer to the task to be executed by the thread.
 * @return int32_t 0 if the thread is successfully created, -1 otherwise.
 */
int32_t fossil_thread_create(fossil_xthread_t *thread, fossil_xthread_attr_t *attr, fossil_xtask_t task);

/**
 * @brief Waits for the specified thread to terminate and retrieves the thread's exit status.
 *
 * @param thread The thread ID to wait for.
 * @param retval Pointer to store the thread's exit status.
 * @return int32_t 0 if successful, -1 otherwise.
 */
int32_t fossil_thread_join(fossil_xthread_t thread, void **retval);

/**
 * @brief Detaches the specified thread, allowing its resources to be automatically reclaimed when it exits.
 *
 * @param thread The thread ID to detach.
 * @return int32_t 0 if successful, -1 otherwise.
 */
int32_t fossil_thread_detach(fossil_xthread_t thread);

/**
 * @brief Creates thread attributes with default values.
 *
 * @param attr Pointer to store the created thread attributes.
 * @return int32_t 0 if successful, -1 otherwise.
 */
int32_t fossil_thread_attr_create(fossil_xthread_attr_t *attr);

/**
 * @brief Destroys the specified thread attributes and reclaims any resources associated with them.
 *
 * @param attr Pointer to the thread attributes to destroy.
 * @return int32_t 0 if successful, -1 otherwise.
 */
int32_t fossil_thread_attr_erase(fossil_xthread_attr_t *attr);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace fossil
{
    class Thread
    {
    public:
        Thread(fossil_xthread_attr_t *attr, fossil_xtask_t task)
        {
            fossil_thread_create(&m_thread, attr, task);
        }

        ~Thread()
        {
            fossil_thread_detach(m_thread);
        }

        int32_t join(void **retval)
        {
            return fossil_thread_join(m_thread, retval);
        }

    private:
        fossil_xthread_t m_thread;
    };
}

#endif

#endif
