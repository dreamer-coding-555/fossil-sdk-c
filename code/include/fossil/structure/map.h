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
#ifndef FOSSIL_STRUCTURES_MAP_H
#define FOSSIL_STRUCTURES_MAP_H

/**
 * @brief Map Data Structure
 * 
 * This library provides functions for working with maps, which are associative containers
 * that store key-value pairs. Maps allow efficient retrieval of values based on their keys.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup lookup Lookup Functions
 * @defgroup modify Modify Functions
 * @defgroup iteration Iteration Functions
 * @defgroup capacity Capacity Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/generic/tofu.h"

// Define a maximum number of key-value pairs that can be stored in the map
#define MAX_MAP_SIZE 100

// Define a structure to represent a fossil_map_t
typedef struct {
    fossil_tofu_t keys[MAX_MAP_SIZE];
    fossil_tofu_t values[MAX_MAP_SIZE];
    size_t size;
    fossil_tofu_type type;
} fossil_map_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================

/**
 * Create a new map with the specified data type.
 *
 * @param list_type The type of data the map will store.
 * @return          The created map.
 */
fossil_map_t* fossil_map_create(fossil_tofu_type list_type);

/**
 * Erase the contents of the map and free allocated memory.
 *
 * @param map The map to erase.
 */
void fossil_map_erase(fossil_map_t* map);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert key-value pair into the map.
 *
 * @param map   The map to insert data into.
 * @param key   The key of the data.
 * @param value The value of the data.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_map_insert(fossil_map_t* map, fossil_tofu_t key, fossil_tofu_t value);

/**
 * Remove key-value pair from the map.
 *
 * @param map The map to remove data from.
 * @param key The key of the data.
 * @return    The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_map_remove(fossil_map_t* map, fossil_tofu_t key);

/**
 * Search for key in the map.
 *
 * @param map The map to search.
 * @param key The key to search for.
 * @return    The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_map_search(fossil_map_t* map, fossil_tofu_t key);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the map.
 *
 * @param map The map for which to get the size.
 * @return    The size of the map.
 */
size_t fossil_map_size(fossil_map_t* map);

/**
 * Get the value from the map matching the specified key.
 *
 * @param map   The map from which to get the value.
 * @param key   The key to search for.
 * @param value A pointer to store the matching value.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_map_getter(fossil_map_t* map, fossil_tofu_t key, fossil_tofu_t* value);

/**
 * Set value in the map with the specified key.
 *
 * @param map   The map in which to set the value.
 * @param key   The key of the data.
 * @param value The value to set.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_map_setter(fossil_map_t* map, fossil_tofu_t key, fossil_tofu_t value);

/**
 * Check if the map is not empty.
 *
 * @param map The map to check.
 * @return    True if the map is not empty, false otherwise.
 */
bool fossil_map_not_empty(fossil_map_t* map);

/**
 * Check if the map is not a null pointer.
 *
 * @param map The map to check.
 * @return    True if the map is not a null pointer, false otherwise.
 */
bool fossil_map_not_cnullptr(fossil_map_t* map);

/**
 * Check if the map is empty.
 *
 * @param map The map to check.
 * @return    True if the map is empty, false otherwise.
 */
bool fossil_map_is_empty(fossil_map_t* map);

/**
 * Check if the map is a null pointer.
 *
 * @param map The map to check.
 * @return    True if the map is a null pointer, false otherwise.
 */
bool fossil_map_is_cnullptr(fossil_map_t* map);

/**
 * Check if the map contains the specified key.
 *
 * @param map The map to check.
 * @param key The key to search for.
 * @return    True if the map contains the key, false otherwise.
 */
bool fossil_map_contains(fossil_map_t* map, fossil_tofu_t key);

// =======================
// ITERATOR FUNCTIONS
// =======================
/**
 * Get the iterator pointing to the start of the map.
 *
 * @param map The map for which to get the iterator.
 * @return    The iterator pointing to the start of the map.
 */
fossil_tofu_iterator fossil_map_iterator_start(fossil_map_t* map);

/**
 * Get the iterator pointing to the end of the map.
 *
 * @param map The map for which to get the iterator.
 * @return    The iterator pointing to the end of the map.
 */
fossil_tofu_iterator fossil_map_iterator_end(fossil_map_t* map);

/**
 * Get the next iterator in the sequence.
 *
 * @param iterator The current iterator.
 * @return         The next iterator in the sequence.
 */
fossil_tofu_iterator fossil_map_iterator_next(fossil_tofu_iterator iterator);

/**
 * Check if there is a next iterator in the sequence.
 *
 * @param iterator The current iterator.
 * @return         True if there is a next iterator, false otherwise.
 */
bool fossil_map_iterator_has_next(fossil_tofu_iterator iterator);

#ifdef __cplusplus
}
#endif

#endif
