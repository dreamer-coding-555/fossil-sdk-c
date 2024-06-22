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
#ifndef FOSSIL_TOFU_MAPOF_H
#define FOSSIL_TOFU_MAPOF_H

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

// Struct for map
typedef struct {
    fossil_tofu_t *keys;
    fossil_tofu_t *values;
    size_t size;
    size_t capacity;
} fossil_tofu_mapof_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Creates a new map with the specified capacity.
 *
 * @param capacity The initial capacity of the map.
 * @return The newly created map.
 */
fossil_tofu_mapof_t fossil_tofu_mapof_create(size_t capacity);

/**
 * @brief Adds a key-value pair to the map.
 *
 * @param map The map to add the key-value pair to.
 * @param key The key to add.
 * @param value The value to add.
 */
void fossil_tofu_mapof_add(fossil_tofu_mapof_t *map, fossil_tofu_t key, fossil_tofu_t value);

/**
 * @brief Gets the value associated with the specified key from the map.
 *
 * @param map The map to get the value from.
 * @param key The key to get the value for.
 * @return The value associated with the key, or NULL if the key is not found.
 */
fossil_tofu_t fossil_tofu_mapof_get(fossil_tofu_mapof_t *map, fossil_tofu_t key);

/**
 * @brief Checks if the specified key exists in the map.
 *
 * @param map The map to check.
 * @param key The key to check for.
 * @return true if the key exists in the map, false otherwise.
 */
bool fossil_tofu_mapof_contains(fossil_tofu_mapof_t *map, fossil_tofu_t key);

/**
 * @brief Removes the key-value pair with the specified key from the map.
 *
 * @param map The map to remove the key-value pair from.
 * @param key The key to remove.
 */
void fossil_tofu_mapof_remove(fossil_tofu_mapof_t *map, fossil_tofu_t key);

/**
 * @brief Gets the number of key-value pairs in the map.
 *
 * @param map The map to get the size of.
 * @return The number of key-value pairs in the map.
 */
size_t fossil_tofu_mapof_size(fossil_tofu_mapof_t *map);

/**
 * @brief Checks if the map is empty.
 *
 * @param map The map to check.
 * @return true if the map is empty, false otherwise.
 */
bool fossil_tofu_mapof_is_empty(fossil_tofu_mapof_t *map);

/**
 * @brief Clears all key-value pairs from the map.
 *
 * @param map The map to clear.
 */
void fossil_tofu_mapof_clear(fossil_tofu_mapof_t *map);

/**
 * @brief Destroys the map and frees the allocated memory.
 *
 * @param map The map to destroy.
 */
void fossil_tofu_mapof_erase(fossil_tofu_mapof_t *map);

/**
 * @brief Prints the contents of the map.
 *
 * @param map The map to print.
 */
void fossil_tofu_mapof_print(fossil_tofu_mapof_t *map);

#ifdef __cplusplus
}
#endif

#endif
