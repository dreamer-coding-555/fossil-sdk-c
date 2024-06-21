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

#include "fossil/generic/arrayof.h"
#include "fossil/generic/iterator.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Concatenates two dynamic arrays.
 *
 * This function concatenates the elements of two dynamic arrays, array1 and array2,
 * into a new dynamic array. The resulting array contains elements from array1 followed
 * by elements from array2. Memory for the concatenated array is allocated dynamically.
 *
 * @param array1 The first dynamic array to concatenate.
 * @param array2 The second dynamic array to concatenate.
 * @return The concatenated dynamic array, or NULL if memory allocation fails or if any
 *         of the input arrays are NULL.
 */
fossil_tofu_arrayof_t fossil_dynamic_concat_arrays(fossil_tofu_arrayof_t array1, fossil_tofu_arrayof_t array2);

/**
 * Reverses a dynamic array.
 *
 * This function reverses the order of elements in a dynamic array. The original array
 * remains unchanged, and a new dynamic array is created to hold the reversed elements.
 * Memory for the reversed array is allocated dynamically.
 *
 * @param array The dynamic array to reverse.
 * @return The reversed dynamic array, or NULL if memory allocation fails or if the input
 *         array is NULL.
 */
fossil_tofu_arrayof_t fossil_dynamic_reverse_array(fossil_tofu_arrayof_t array);

/**
 * Filters elements in a dynamic array based on a predicate function.
 *
 * This function filters elements in the given dynamic array based on the predicate
 * function `predicate`. Elements for which `predicate` returns true are included in
 * the resulting array; others are excluded.
 *
 * @param array The dynamic array to filter.
 * @param size The number of elements in the dynamic array.
 * @param predicate The predicate function that takes a fossil_tofu_t element and returns
 *                  true if the element should be included, false otherwise.
 * @return The filtered dynamic array containing elements that satisfy the predicate,
 *         or NULL if memory allocation fails or if the input array is NULL.
 */
fossil_tofu_arrayof_t fossil_dynamic_filter_array(fossil_tofu_arrayof_t array, bool (*predicate)(fossil_tofu_t));

/**
 * Applies a transformation function to each element in a dynamic array.
 *
 * This function applies the transformation function `transform` to each element
 * in the given dynamic array `array`. The transformed elements are stored in a
 * new dynamic array allocated dynamically.
 *
 * @param array The dynamic array to transform.
 * @param size The number of elements in the dynamic array.
 * @param transform The transformation function that takes a fossil_tofu_t element
 *                  and returns the transformed fossil_tofu_t element.
 * @return The transformed dynamic array, or NULL if memory allocation fails or if the
 *         input array is NULL.
 */
fossil_tofu_arrayof_t fossil_dynamic_map_array(fossil_tofu_arrayof_t array, fossil_tofu_t (*transform)(fossil_tofu_t));

/**
 * Sorts elements in a dynamic array in ascending order.
 *
 * This function sorts the elements in the given dynamic array `array` in ascending
 * order based on a specified comparison function `compare`.
 *
 * @param array The dynamic array to sort.
 * @param size The number of elements in the dynamic array.
 * @param compare The comparison function that returns a negative value if the first
 *                element is less than the second, zero if they are equal, or a positive
 *                value if the first element is greater than the second.
 */
void fossil_dynamic_sort_array(fossil_tofu_arrayof_t array, int (*compare)(const void *, const void *));

/**
 * Shuffles elements in a dynamic array randomly.
 *
 * This function shuffles the elements in the given dynamic array `array` randomly.
 * The shuffling is done in-place.
 *
 * @param array The dynamic array to shuffle.
 * @param size The number of elements in the dynamic array.
 */
void fossil_dynamic_shuffle_array(fossil_tofu_arrayof_t array);

#ifdef __cplusplus
}
#endif

#endif
