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
#ifndef FOSSIL_ALGORITHM_SEARCH_H
#define FOSSIL_ALGORITHM_SEARCH_H

/**
 * @brief Search algorithms for "tofu" arrays
 *
 * This library provides functions to perform linear search, binary search, and interpolation search
 * on "tofu" arrays. These search algorithms are useful for finding elements within the arrays efficiently.
 *
 * @see fossil_tofu_t
 *
 * @brief Performs linear search on a "tofu" array to find the specified key.
 *
 * This function performs a linear search on the provided "tofu" array to find the specified key.
 * It traverses the array sequentially and returns the index of the first occurrence of the key, if found.
 *
 * @param array The "tofu" array to be searched.
 * @param key The key to search for within the array.
 * @return The index of the first occurrence of the key in the array, or -1 if the key is not found.
 * 
 * @brief Performs binary search on a sorted "tofu" array to find the specified key.
 *
 * This function performs a binary search on the provided sorted "tofu" array to find the specified key.
 * It divides the array into halves and repeatedly compares the key with the middle element,
 * narrowing down the search space until the key is found or the search space is empty.
 *
 * @param array The sorted "tofu" array to be searched.
 * @param key The key to search for within the array.
 * @return The index of the key in the array, or -1 if the key is not found.
 * 
 * @brief Performs interpolation search on a sorted "tofu" array to find the specified key.
 *
 * This function performs interpolation search on the provided sorted "tofu" array to find the specified key.
 * It estimates the position of the key by linearly interpolating between the values at the beginning and end
 * of the search range, narrowing down the search space based on the estimated position.
 *
 * @param array The sorted "tofu" array to be searched.
 * @param key The key to search for within the array.
 * @return The index of the key in the array, or -1 if the key is not found.
 */

#include "fossil/generic/arrayof.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Performs linear search on a "tofu" array to find the specified key.
 *
 * This function performs a linear search on the provided "tofu" array to find the specified key.
 * It traverses the array sequentially and returns the index of the first occurrence of the key, if found.
 *
 * @param array The "tofu" array to be searched.
 * @param key The key to search for within the array.
 * @return The index of the first occurrence of the key in the array, or -1 if the key is not found.
 */
int fossil_search_linear(fossil_tofu_arrayof_t array, fossil_tofu_t* key);

/**
 * @brief Performs binary search on a sorted "tofu" array to find the specified key.
 *
 * This function performs a binary search on the provided sorted "tofu" array to find the specified key.
 * It divides the array into halves and repeatedly compares the key with the middle element,
 * narrowing down the search space until the key is found or the search space is empty.
 *
 * @param array The sorted "tofu" array to be searched.
 * @param key The key to search for within the array.
 * @return The index of the key in the array, or -1 if the key is not found.
 */
int fossil_search_binary(fossil_tofu_arrayof_t array, fossil_tofu_t* key);

/**
 * @brief Performs interpolation search on a sorted "tofu" array to find the specified key.
 *
 * This function performs interpolation search on the provided sorted "tofu" array to find the specified key.
 * It estimates the position of the key by linearly interpolating between the values at the beginning and end
 * of the search range, narrowing down the search space based on the estimated position.
 *
 * @param array The sorted "tofu" array to be searched.
 * @param key The key to search for within the array.
 * @return The index of the key in the array, or -1 if the key is not found.
 */
int fossil_search_interpolation(fossil_tofu_arrayof_t array, fossil_tofu_t* key);

#ifdef __cplusplus
}
#endif

#endif
