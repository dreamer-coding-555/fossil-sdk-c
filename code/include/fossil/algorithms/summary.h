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
#ifndef FOSSIL_ALGORITHM_SUM_H
#define FOSSIL_ALGORITHM_SUM_H

/**
 * @brief Summary statistics functions for "tofu" arrays
 *
 * This library provides functions to compute summary statistics such as sum, mean, and median
 * for "tofu" arrays. The "tofu" arrays are structures representing numerical data in a custom format,
 * and the functions here are designed to operate specifically on these arrays.
 *
 * @see fossil_tofu_t, fossil_tofu_error_t
 *
 * @brief Computes the sum of elements in a "tofu" array.
 * 
 * This function calculates the sum of all elements in the provided "tofu" array.
 * 
 * @param array The "tofu" array whose elements to sum.
 * @param sum Pointer to a "tofu" structure where the result will be stored.
 * @return Error code indicating the success or failure of the operation.
 * 
 * @brief Computes the mean (average) of elements in a "tofu" array.
 * 
 * This function calculates the mean (average) of all elements in the provided "tofu" array.
 * 
 * @param array The "tofu" array whose elements to average.
 * @param mean Pointer to a "tofu" structure where the result will be stored.
 * @return Error code indicating the success or failure of the operation.
 * 
 * @brief Computes the median of elements in a "tofu" array.
 * 
 * This function calculates the median of all elements in the provided "tofu" array.
 * 
 * @param array The "tofu" array whose elements to find the median of.
 * @param median Pointer to a "tofu" structure where the result will be stored.
 * @return Error code indicating the success or failure of the operation.
 */

#include "fossil/tofu/tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Computes the sum of elements in a "tofu" array.
 *
 * This function calculates the sum of all elements in the provided "tofu" array.
 *
 * @param array The "tofu" array whose elements to sum.
 * @param sum Pointer to a "tofu" structure where the result will be stored.
 * @return Error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_summary_sum(const fossil_tofu_t* array, fossil_tofu_t* sum);

/**
 * @brief Computes the mean (average) of elements in a "tofu" array.
 *
 * This function calculates the mean (average) of all elements in the provided "tofu" array.
 *
 * @param array The "tofu" array whose elements to average.
 * @param mean Pointer to a "tofu" structure where the result will be stored.
 * @return Error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_summary_mean(const fossil_tofu_t* array, fossil_tofu_t* mean);

/**
 * @brief Computes the median of elements in a "tofu" array.
 *
 * This function calculates the median of all elements in the provided "tofu" array.
 *
 * @param array The "tofu" array whose elements to find the median of.
 * @param median Pointer to a "tofu" structure where the result will be stored.
 * @return Error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_summary_median(const fossil_tofu_t* array, fossil_tofu_t* median);

#ifdef __cplusplus
}
#endif

#endif
