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
#ifndef FOSSIL_THREADS_THREADLOCAL_H
#define FOSSIL_THREADS_THREADLOCAL_H

#ifdef _WIN32
#include <windows.h>
typedef DWORD fossil_xthread_local_t;
#else
#include <pthread.h>
typedef pthread_key_t fossil_xthread_local_t;
#endif
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Creates a thread-local storage key.
 *
 * @param key Pointer to store the created thread-local storage key.
 * @param destructor Pointer to the destructor function called when a thread exits, or NULL if no destructor is needed.
 * @return int32_t 0 if successful, -1 otherwise.
 */
int32_t fossil_thread_local_create(fossil_xthread_local_t *key, void (*destructor)(void*));

/**
 * @brief Erases a thread-local storage key.
 *
 * @param key The thread-local storage key to erase.
 * @return int32_t 0 if successful, -1 otherwise.
 */
int32_t fossil_thread_local_erase(fossil_xthread_local_t key);

/**
 * @brief Retrieves the value associated with a thread-local storage key for the current thread.
 *
 * @param key The thread-local storage key.
 * @return void* The value associated with the key for the current thread, or NULL if no value is set.
 */
void* fossil_thread_local_get(fossil_xthread_local_t key);

/**
 * @brief Sets the value associated with a thread-local storage key for the current thread.
 *
 * @param key The thread-local storage key.
 * @param value Pointer to the value to associate with the key for the current thread.
 * @return int32_t 0 if successful, -1 otherwise.
 */
int32_t fossil_thread_local_set(fossil_xthread_local_t key, const void *value);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <stdexcept>

namespace fossil {

class ThreadLocal {
public:
    ThreadLocal(void (*destructor)(void*) = nullptr) {
        if (fossil_thread_local_create(&key_, destructor) != 0) {
            throw std::runtime_error("Failed to create thread-local storage key");
        }
    }

    ~ThreadLocal() {
        if (fossil_thread_local_erase(key_) != 0) {
            throw std::runtime_error("Failed to erase thread-local storage key");
        }
    }

    void* get() const {
        return fossil_thread_local_get(key_);
    }

    void set(const void* value) {
        if (fossil_thread_local_set(key_, value) != 0) {
            throw std::runtime_error("Failed to set thread-local storage value");
        }
    }

private:
    fossil_xthread_local_t key_;
};

} // namespace fossil

#endif // __cplusplus

#endif
