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
#ifndef FOSSIL_ALGORITHM_SORT_H
#define FOSSIL_ALGORITHM_SORT_H

/**
 * @brief Sorting algorithms for "tofu" arrays
 *
 * This library provides functions to sort "tofu" arrays using different sorting algorithms
 * such as Bubble Sort, Quick Sort, and Merge Sort. The "tofu" arrays are structures representing
 * numerical data in a custom format, and the functions here are designed to operate specifically
 * on these arrays.
 *
 * @see fossil_tofu_t, fossil_tofu_error_t
 *
 * @brief Sorts a "tofu" array using the Bubble Sort algorithm.
 *
 * This function sorts the elements of the provided "tofu" array in ascending order using the Bubble Sort algorithm.
 *
 * @param array The "tofu" array to be sorted.
 * @return Error code indicating the success or failure of the operation.
 * 
 * @brief Sorts a "tofu" array using the Quick Sort algorithm.
 *
 * This function sorts the elements of the provided "tofu" array in ascending order using the Quick Sort algorithm.
 *
 * @param array The "tofu" array to be sorted.
 * @return Error code indicating the success or failure of the operation.
 * 
 * @brief Sorts a "tofu" array using the Merge Sort algorithm.
 *
 * This function sorts the elements of the provided "tofu" array in ascending order using the Merge Sort algorithm.
 *
 * @param array The "tofu" array to be sorted.
 * @return Error code indicating the success or failure of the operation.
 */

#include "fossil/generic/tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Sorts a "tofu" array using the Bubble Sort algorithm.
 *
 * This function sorts the elements of the provided "tofu" array in ascending order using the Bubble Sort algorithm.
 *
 * @param array The "tofu" array to be sorted.
 * @return Error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_sort_bubble(fossil_tofu_t* array);

/**
 * @brief Sorts a "tofu" array using the Quick Sort algorithm.
 *
 * This function sorts the elements of the provided "tofu" array in ascending order using the Quick Sort algorithm.
 *
 * @param array The "tofu" array to be sorted.
 * @return Error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_sort_quick(fossil_tofu_t* array);

/**
 * @brief Sorts a "tofu" array using the Merge Sort algorithm.
 *
 * This function sorts the elements of the provided "tofu" array in ascending order using the Merge Sort algorithm.
 *
 * @param array The "tofu" array to be sorted.
 * @return Error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_sort_merge(fossil_tofu_t* array);

#ifdef __cplusplus
}
#endif

#endif
