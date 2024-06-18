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
#ifndef FOSSIL_TOOL_SMARTPTR_H
#define FOSSIL_TOOL_SMARTPTR_H

/**
 * @brief Smart Pointer Library
 * 
 * This library provides an implementation of smart pointers in C, which helps
 * manage dynamic memory and prevent memory leaks. The smart pointer maintains
 * a reference count to ensure that the managed object is only freed when there
 * are no remaining references to it. This implementation includes functions to
 * create, acquire, release, and access the raw pointer managed by the smart pointer.
 * 
 * Key Features:
 * - Automatic memory management with reference counting.
 * - Custom deleter support for specialized cleanup.
 * - Simple and clear API for managing smart pointers.
 * 
 * Usage:
 * 
 * 1. Initialize a smart pointer:
 *    @code
 *    fossil_smartptr sp;
 *    int *data = malloc(sizeof(int));
 *    *data = 42;
 *    if (!fossil_smartptr_create(&sp, data, free)) {
 *        // Handle error
 *    }
 *    @endcode
 * 
 * 2. Access the managed pointer:
 *    @code
 *    int *raw_ptr = (int *)fossil_smartptr_get(&sp);
 *    if (raw_ptr) {
 *        // Use the pointer
 *    }
 *    @endcode
 * 
 * 3. Acquire additional references:
 *    @code
 *    if (!fossil_smartptr_acquire(&sp)) {
 *        // Handle error
 *    }
 *    @endcode
 * 
 * 4. Release references:
 *    @code
 *    if (!fossil_smartptr_erase(&sp)) {
 *        // Handle error
 *    }
 *    @endcode
 * 
 */

#include "fossil/common/common.h"

typedef struct {
    void *ptr;
    int32_t *ref_count;
    void (*deleter)(void *);
} fossil_smartptr_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalable functions
// =================================================================

/**
 * @brief Initializes a smart pointer with a given pointer and deleter function.
 * 
 * This function sets up the smart pointer to manage the specified raw pointer.
 * It initializes the reference count to 1 and assigns the custom deleter function.
 * 
 * @param sp Pointer to the smart pointer structure to initialize.
 * @param ptr Raw pointer to be managed by the smart pointer.
 * @param deleter Custom deleter function to be called when the reference count reaches zero.
 * 
 * @return true on successful initialization, false if either `sp` or `ptr` is NULL
 *         or if memory allocation for the reference count fails.
 */
fossil_bool_t fossil_smartptr_create(fossil_smartptr_t *sp, void *ptr, void (*deleter)(void *));

/**
 * @brief Increments the reference count of the smart pointer.
 * 
 * This function increases the reference count of the smart pointer, indicating
 * that an additional owner is now managing the raw pointer. This prevents the
 * pointer from being freed until all owners have released it.
 * 
 * @param sp Pointer to the smart pointer whose reference count is to be incremented.
 * 
 * @return true if the reference count was successfully incremented, false if `sp` or its reference count is NULL.
 */
fossil_bool_t fossil_smartptr_acquire(fossil_smartptr_t *sp);

/**
 * @brief Decrements the reference count and frees the managed pointer if it reaches zero.
 * 
 * This function decreases the reference count of the smart pointer. If the reference
 * count reaches zero, the managed pointer is freed using the custom deleter function,
 * if provided, or `free` otherwise. It also cleans up the reference count.
 * 
 * @param sp Pointer to the smart pointer whose reference count is to be decremented.
 * 
 * @return true if the reference count was successfully decremented (and the pointer freed if count reaches zero),
 *         false if `sp` or its reference count is NULL.
 */
fossil_bool_t fossil_smartptr_erase(fossil_smartptr_t *sp);

/**
 * @brief Retrieves the raw pointer managed by the smart pointer.
 * 
 * This function returns the raw pointer that is currently managed by the smart pointer.
 * It can be used to access the underlying data directly. 
 * 
 * @param sp Pointer to the smart pointer from which to retrieve the raw pointer.
 * 
 * @return The raw pointer if successful, NULL if `sp` or its raw pointer is NULL.
 */
void *fossil_smartptr_get(fossil_smartptr_t *sp);

#ifdef __cplusplus
}
#endif

#endif
