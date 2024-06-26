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
#ifndef FOSSIL_STRUCTURES_SET_H
#define FOSSIL_STRUCTURES_SET_H

/**
 * @brief Set Data Structure
 * 
 * This library provides functions for working with sets, which are collections of unique elements.
 * Sets offer operations for adding, removing, and testing for membership of elements.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup insert_erase Insert and Erase Functions
 * @defgroup lookup Lookup Functions
 * @defgroup capacity Capacity Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/generic/tofu.h"
#include "fossil/generic/iterator.h"
#include "fossil/generic/actionof.h"

// Node structure for the set
typedef struct fossil_set_node_t {
    fossil_tofu_t data;
    struct fossil_set_node_t* next;
} fossil_set_node_t;

// Set structure
typedef struct fossil_set_t {
    fossil_set_node_t* head;
    char* type;
} fossil_set_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Create a new set with the specified data type.
 *
 * @param list_type The type of data the set will store.
 * @return          The created set.
 */
fossil_set_t* fossil_set_create(char* type);

/**
 * Erase the contents of the set and free allocated memory.
 *
 * @param set The set to erase.
 */
void fossil_set_erase(fossil_set_t* set);

/**
 * Insert data into the set.
 *
 * @param set  The set to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_insert(fossil_set_t* set, fossil_tofu_t data);

/**
 * Remove data from the set.
 *
 * @param set  The set to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_remove(fossil_set_t* set, fossil_tofu_t data);

/**
 * Search for data in the set.
 *
 * @param set  The set to search.
 * @param data The data to search for.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_search(const fossil_set_t* set, fossil_tofu_t data);

/**
 * Get the size of the set.
 *
 * @param set The set for which to get the size.
 * @return    The size of the set.
 */
size_t fossil_set_size(const fossil_set_t* set);

/**
 * Get the data from the set matching the specified data.
 *
 * @param set  The set from which to get the data.
 * @param data The data to search for.
 * @return     A pointer to the matching data, or NULL if not found.
 */
fossil_tofu_t* fossil_set_getter(fossil_set_t* set, fossil_tofu_t data);

/**
 * Set data in the set.
 *
 * @param set  The set in which to set the data.
 * @param data The data to set.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_setter(fossil_set_t* set, fossil_tofu_t data);

/**
 * Check if the set is not empty.
 *
 * @param set The set to check.
 * @return    True if the set is not empty, false otherwise.
 */
bool fossil_set_not_empty(const fossil_set_t* set);

/**
 * Check if the set is not a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is not a null pointer, false otherwise.
 */
bool fossil_set_not_cnullptr(const fossil_set_t* set);

/**
 * Check if the set is empty.
 *
 * @param set The set to check.
 * @return    True if the set is empty, false otherwise.
 */
bool fossil_set_is_empty(const fossil_set_t* set);

/**
 * Check if the set is a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is a null pointer, false otherwise.
 */
bool fossil_set_is_cnullptr(const fossil_set_t* set);

/**
 * Check if the set contains a specific element.
 *
 * @param set  The set to check.
 * @param data The data to search for.
 * @return     True if the set contains the element, false otherwise.
 */
int32_t fossil_set_contains(const fossil_set_t* set, fossil_tofu_t data);

#ifdef __cplusplus
}
#endif

#endif
