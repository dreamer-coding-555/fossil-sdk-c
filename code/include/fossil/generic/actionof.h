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
#ifndef FOSSIL_TOFU_H
#define FOSSIL_TOFU_H

/**
 * @file tofu.h
 *
 * @brief Header file for the Tofu library, providing versatile data structures and algorithms for managing various data types.
 *
 * The Tofu library offers a comprehensive suite of data structures and algorithms
 * meticulously crafted to efficiently handle a broad spectrum of data types. Its
 * functionalities encompass creating, erasing, searching, sorting, filtering,
 * and iterating through data structures. Moreover, it incorporates robust error
 * handling mechanisms and utilities for copying, setting, and retrieving values.
 *
 * Tofu data structures accommodate a diverse array of data types, including integers,
 * floating-point numbers, strings, characters, arrays, maps, and customizable data
 * types. The library is highly adaptable, empowering users to define their custom
 * data types and operations to suit their specific needs.
 *
 * This header file encompasses declarations for all functions and data types provided
 * by the Tofu library. By including this header file in their projects, users can
 * leverage the extensive functionalities offered by the library.
 */

#include "fossil/common/common.h"
#include "tofu.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * Transforms elements in an array using a given function.
 *
 * @param array The array of elements to be transformed.
 * @param size The size of the array.
 * @param func The function to be applied to each element.
 */
void fossil_tofu_actionof_transform(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t));

/**
 * Accumulates elements in an array using a given function and initial value.
 *
 * @param array The array of elements to be accumulated.
 * @param size The size of the array.
 * @param init The initial value for accumulation.
 * @param func The function to be applied to each element during accumulation.
 * @return The accumulated value.
 */
fossil_tofu_t fossil_tofu_actionof_accumulate(fossil_tofu_t *array, size_t size, fossil_tofu_t init, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Filters elements in an array based on a given predicate function.
 *
 * @param array The array of elements to be filtered.
 * @param size The size of the array.
 * @param pred The predicate function to determine whether an element should be included in the filtered result.
 * @return The number of elements that pass the filter.
 */
size_t fossil_tofu_actionof_filter(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t));

/**
 * Searches for an element in an array using a given key and comparison function.
 *
 * @param array The array of elements to be searched.
 * @param size The size of the array.
 * @param key The key to search for.
 * @param compare The comparison function to determine equality between elements.
 * @return A pointer to the first occurrence of the key in the array, or NULL if not found.
 */
fossil_tofu_t* fossil_tofu_actionof_search(fossil_tofu_t *array, size_t size, fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t));

/**
 * Reverses the order of elements in an array.
 *
 * @param array The array of elements to be reversed.
 * @param size The size of the array.
 */
void fossil_tofu_actionof_reverse(fossil_tofu_t *array, size_t size);

/**
 * Swaps two elements in an array.
 *
 * @param array The array containing the elements to be swapped.
 * @param index1 The index of the first element to be swapped.
 * @param index2 The index of the second element to be swapped.
 */
void fossil_tofu_actionof_swap(fossil_tofu_t *array, size_t index1, size_t index2);

/**
 * Compares two elements.
 *
 * @param a The first element to be compared.
 * @param b The second element to be compared.
 * @return A negative value if a is less than b, a positive value if a is greater than b, or zero if they are equal.
 */
int fossil_tofu_actionof_compare(fossil_tofu_t a, fossil_tofu_t b);

/**
 * Reduces elements in an array using a given function.
 *
 * @param array The array of elements to be reduced.
 * @param size The size of the array.
 * @param func The function to be applied to each pair of elements during reduction.
 * @return The reduced value.
 */
fossil_tofu_t fossil_tofu_actionof_reduce(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Shuffles elements in an array randomly.
 *
 * @param array The array of elements to be shuffled.
 * @param size The size of the array.
 */
void fossil_tofu_actionof_shuffle(fossil_tofu_t *array, size_t size);

/**
 * Applies a function to each element in an array.
 *
 * @param array The array of elements to apply the function to.
 * @param size The size of the array.
 * @param func The function to be applied to each element.
 */
void fossil_tofu_actionof_for_each(fossil_tofu_t *array, size_t size, void (*func)(fossil_tofu_t));

/**
 * Partitions elements in an array based on a given predicate function.
 *
 * @param array The array of elements to be partitioned.
 * @param size The size of the array.
 * @param pred The predicate function to determine the partitioning condition.
 * @return The index of the first element in the second partition.
 */
size_t fossil_tofu_actionof_partition(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t));

/**
 * Calculates the summary of elements in an array using a given function.
 *
 * @param array The array of elements to calculate the summary for.
 * @param size The size of the array.
 * @param func The function to be applied to each pair of elements during calculation.
 * @return The calculated summary.
 */
fossil_tofu_t fossil_tofu_actionof_summary(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Calculates the average of elements in an array.
 *
 * @param array The array of elements to calculate the average for.
 * @param size The size of the array.
 * @return The calculated average.
 */
fossil_tofu_t fossil_tofu_actionof_average(fossil_tofu_t *array, size_t size);

#ifdef __cplusplus
}
#endif

#endif
