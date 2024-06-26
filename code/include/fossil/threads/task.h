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
#ifndef FOSSIL_THREADS_TASK_H
#define FOSSIL_THREADS_TASK_H

// Define the task function type
#ifdef _WIN32
#include <windows.h>
typedef LPVOID fossil_xtask_arg_t;
typedef void (*fossil_xtask_func_t)(LPVOID arg);
#else
typedef void *fossil_xtask_arg_t;
typedef void (*fossil_xtask_func_t)(void* arg);
#endif

typedef struct {
    fossil_xtask_func_t task_func;
    fossil_xtask_arg_t arg;
} fossil_xtask_t;

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Macro to define a task function with a platform-independent argument type.
 *
 * @param task_name The name of the task function.
 * @param arg_name The name of the argument for the task function.
 */
#define XTASK(task_name, arg_name) \
    void task_name(fossil_xtask_arg_t arg_name)

/**
 * @brief Inline function to provide platform-independent task delay by seconds.
 *
 * @param seconds The number of seconds to delay.
 */
static inline void fossil_task_delay_seconds(uint32_t seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

/**
 * @brief Inline function to provide platform-independent task delay by minutes.
 *
 * @param minutes The number of minutes to delay.
 */
static inline void fossil_task_delay_minutes(uint32_t minutes) {
    fossil_task_delay_seconds(minutes * 60);
}

/**
 * @brief Inline function to provide platform-independent task delay by milliseconds.
 *
 * @param milliseconds The number of milliseconds to delay.
 */
static inline void fossil_task_delay_milliseconds(uint32_t milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    sleep(milliseconds * 1000);
#endif
}

#ifdef __cplusplus
}
#endif

// C++ interface
#ifdef __cplusplus

namespace fossil {

/**
 * @brief Inline function to provide platform-independent task delay by seconds.
 *
 * @param seconds The number of seconds to delay.
 */
static inline void task_delay_seconds(uint32_t seconds) {
    fossil_task_delay_seconds(seconds);
}

/**
 * @brief Inline function to provide platform-independent task delay by minutes.
 *
 * @param minutes The number of minutes to delay.
 */
static inline void task_delay_minutes(uint32_t minutes) {
    task_delay_seconds(minutes * 60);
}

/**
 * @brief Inline function to provide platform-independent task delay by milliseconds.
 *
 * @param milliseconds The number of milliseconds to delay.
 */
static inline void task_delay_milliseconds(uint32_t milliseconds) {
    fossil_task_delay_milliseconds(milliseconds);
}

} // namespace fossil

#endif // __cplusplus

#endif
