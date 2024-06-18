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
typedef CONDITION_VARIABLE fossil_xcond_t;
#else
#include <pthread.h>
typedef pthread_cond_t fossil_xcond_t;
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
int32_t fossil_cond_create(fossil_xcond_t *cond);

/**
 * @brief Destroys a condition variable.
 *
 * @param cond Pointer to the condition variable to destroy.
 * @return int32_t 0 if the condition variable is successfully destroyed, -1 otherwise.
 */
int32_t fossil_cond_erase(fossil_xcond_t *cond);

/**
 * @brief Waits for a condition variable to be signaled. The mutex must be locked before calling this function.
 *
 * @param cond Pointer to the condition variable to wait on.
 * @param mutex Pointer to the mutex that is used with the condition variable.
 * @return int32_t 0 if the wait is successful and the condition variable is signaled, -1 otherwise.
 */
int32_t fossil_cond_wait(fossil_xcond_t *cond, fossil_xmutex_t *mutex);

/**
 * @brief Signals a condition variable, waking up one of the threads that are waiting on the condition variable.
 *
 * @param cond Pointer to the condition variable to signal.
 * @return int32_t 0 if the condition variable is successfully signaled, -1 otherwise.
 */
int32_t fossil_cond_signal(fossil_xcond_t *cond);

/**
 * @brief Broadcasts a condition variable, waking up all threads that are waiting on the condition variable.
 *
 * @param cond Pointer to the condition variable to broadcast.
 * @return int32_t 0 if the condition variable is successfully broadcasted, -1 otherwise.
 */
int32_t fossil_cond_broadcast(fossil_xcond_t *cond);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <stdexcept>

namespace fossil {

    class Condition {
    public:
        Condition() {
            int32_t result = fossil_cond_create(&m_cond);
            if (result != 0) {
                throw std::runtime_error("Failed to create condition variable");
            }
        }

        ~Condition() {
            int32_t result = fossil_cond_erase(&m_cond);
            if (result != 0) {
                throw std::runtime_error("Failed to destroy condition variable");
            }
        }

        void wait(Mutex& mutex) {
            int32_t result = fossil_cond_wait(&m_cond, &m_mutex.get());
            if (result != 0) {
                throw std::runtime_error("Failed to wait on condition variable");
            }
        }

        void signal() {
            int32_t result = fossil_cond_signal(&m_cond);
            if (result != 0) {
                throw std::runtime_error("Failed to signal condition variable");
            }
        }

        void broadcast() {
            int32_t result = fossil_cond_broadcast(&m_cond);
            if (result != 0) {
                throw std::runtime_error("Failed to broadcast condition variable");
            }
        }

    private:
        fossil_xcond_t m_cond;
        fossil::Mutex m_mutex;
    };

} // namespace fossil

#endif // __cplusplus

#endif
