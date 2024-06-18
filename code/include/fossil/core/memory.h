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
#ifndef FOSSIL_TOOL_MEMORY_H
#define FOSSIL_TOOL_MEMORY_H

/**
 * @brief Memory manipulation functions for allocating, reallocating, freeing, copying, and setting memory.
 *
 * This file provides functions for memory allocation, reallocation, freeing, copying, and setting.
 * These functions are useful for dynamic memory management and memory manipulation operations.
 * They handle error conditions such as failed allocation or invalid pointers by throwing an error
 * message and exiting the program.
 *
 * Usage:
 *  1. Include "fossil/core/memory.h" in your source code.
 *  2. Use fossil_memory_alloc() to allocate memory of a specified size.
 *  3. Use fossil_memory_realloc() to reallocate memory to a new size, preserving data if possible.
 *  4. Use fossil_memory_free() to free previously allocated memory.
 *  5. Use fossil_memory_copy() to copy data from a source to a destination memory.
 *  6. Use fossil_memory_set() to set a specified value to a block of memory.
 *
 * Example:
 * ```c
 * #include "fossil/core/memory.h"
 * #include <stdio.h>
 *
 * int main() {
 *     // Allocate memory
 *     fossil_memory_t ptr = fossil_memory_alloc(10 * sizeof(int));
 *     if (ptr == NULL) {
 *         fprintf(stderr, "Memory allocation failed\n");
 *         return 1;
 *     }
 *
 *     // Set memory
 *     fossil_memory_set(ptr, 0, 10 * sizeof(int));
 *
 *     // Free memory
 *     fossil_memory_free(ptr);
 *     return 0;
 * }
 * ```
 *
 */

#include "fossil/common/common.h"

// Define fossil_memory_t as void*
typedef void* fossil_memory_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalable functions
// =================================================================

/**
 * Allocate memory.
 *
 * @param size The size of the memory to allocate.
 * @return A pointer to the allocated memory.
 * @throws Error message and exits if allocation fails.
 */
fossil_memory_t fossil_memory_alloc(size_t size);

/**
 * Reallocate memory.
 *
 * @param ptr A pointer to the previously allocated memory.
 * @param size The new size of the memory to allocate.
 * @return A pointer to the reallocated memory.
 * @throws Error message and exits if reallocation fails or if the pointer is NULL.
 */
fossil_memory_t fossil_memory_realloc(fossil_memory_t ptr, size_t size);

/**
 * Free memory.
 *
 * @param ptr A pointer to the memory to free.
 * @throws Error message and exits if the pointer is NULL.
 */
void fossil_memory_free(fossil_memory_t ptr);

/**
 * Copy memory.
 *
 * @param dest A pointer to the destination memory.
 * @param src A pointer to the source memory.
 * @param size The size of the memory to copy.
 * @return A pointer to the destination memory.
 * @throws Error message and exits if copying fails or if either source or destination is NULL.
 */
fossil_memory_t fossil_memory_copy(fossil_memory_t dest, const fossil_memory_t src, size_t size);

/**
 * Set memory.
 *
 * @param ptr A pointer to the memory to set.
 * @param value The value to set.
 * @param size The size of the memory to set.
 * @return A pointer to the memory.
 * @throws Error message and exits if setting fails or if the pointer is NULL.
 */
fossil_memory_t fossil_memory_set(fossil_memory_t ptr, int32_t value, size_t size);

#ifdef __cplusplus
}
#endif

#endif
