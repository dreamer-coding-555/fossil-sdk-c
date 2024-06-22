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
#ifndef FOSSIL_TOFU_ITER_H
#define FOSSIL_TOFU_ITER_H

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

// Struct for iterator
typedef struct {
    fossil_tofu_t *array;
    size_t size;
    size_t current_index;
} fossil_tofu_iteratorof_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Function to create a new iterator for an array of tofu.
 *
 * This function creates a new iterator for the given array of tofu with the specified size.
 *
 * @param array The array of tofu.
 * @param size The size of the array.
 * @return The created iterator.
 */
fossil_tofu_iteratorof_t fossil_tofu_iteratorof_create(fossil_tofu_t *array, size_t size);

/**
 * @brief Function to check if the iterator has more elements.
 *
 * This function checks if the iterator has more elements to iterate over.
 *
 * @param iterator The iterator to check.
 * @return true if the iterator has more elements, false otherwise.
 */
bool fossil_tofu_iteratorof_has_next(fossil_tofu_iteratorof_t *iterator);

/**
 * @brief Function to get the next element in the iterator.
 *
 * This function returns the next element in the iterator and advances the iterator to the next position.
 *
 * @param iterator The iterator.
 * @return The next element in the iterator.
 */
fossil_tofu_t fossil_tofu_iteratorof_next(fossil_tofu_iteratorof_t *iterator);

/**
 * @brief Function to reset the iterator to the beginning.
 *
 * This function resets the iterator to the beginning, allowing iteration from the start again.
 *
 * @param iterator The iterator to reset.
 */
void fossil_tofu_iteratorof_reset(fossil_tofu_iteratorof_t *iterator);

#ifdef __cplusplus
}
#endif

#endif
