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
#ifndef FOSSIL_ALGORITHM_DYNAMIC_H
#define FOSSIL_ALGORITHM_DYNAMIC_H

/**
 * @brief Dynamic array operations
 *
 * This library provides functions for performing operations on dynamic arrays.
 * Dynamic arrays can grow or shrink in size dynamically during program execution.
 * The functions in this library include concatenation and reversal of dynamic arrays.
 *
 * @see fossil_tofu_t
 *
 * @brief Concatenates two dynamic arrays.
 *
 * @param array1 The first dynamic array.
 * @param array2 The second dynamic array.
 * @return The concatenated dynamic array, or NULL on failure.
 * 
 * @brief Reverses a dynamic array.
 *
 * @param array The dynamic array to reverse.
 * @return The reversed dynamic array, or NULL on failure.
 */

#include "fossil/tofu/tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Concatenates two dynamic arrays.
 *
 * @param array1 The first dynamic array.
 * @param array2 The second dynamic array.
 * @return The concatenated dynamic array, or NULL on failure.
 */
fossil_tofu_t* fossil_dynamic_concat_arrays(fossil_tofu_t* array1, fossil_tofu_t* array2);

/**
 * Reverses a dynamic array.
 *
 * @param array The dynamic array to reverse.
 * @return The reversed dynamic array, or NULL on failure.
 */
fossil_tofu_t* fossil_dynamic_reverse_array(fossil_tofu_t* array);

#ifdef __cplusplus
}
#endif

#endif
