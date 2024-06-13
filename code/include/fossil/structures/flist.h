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
#ifndef FOSSIL_STRUCTURES_FLIST_H
#define FOSSIL_STRUCTURES_FLIST_H

/**
 * @brief Forward List Data Structure
 * 
 * This library provides functions for working with forward lists, which are linear data structures
 * similar to singly linked lists. Forward lists allow efficient insertion and removal of elements
 * at the beginning and after specified positions.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup insert_erase Insert and Erase Functions
 * @defgroup lookup Lookup Functions
 * @defgroup iteration Iteration Functions
 * @defgroup capacity Capacity Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/tofu/tofu.h"

// Node structure for the linked list
typedef struct fossil_flist_node_t {
    fossil_tofu_t data;
    struct fossil_flist_node_t* next;
} fossil_flist_node_t;

// Linked list structure
typedef struct fossil_flist_t {
    fossil_flist_node_t* head;
    fossil_tofu_type list_type;  // Type of the linked list
} fossil_flist_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================

/**
 * Create a new forward list with the specified data type.
 *
 * @param list_type The type of data the forward list will store.
 * @return          The created forward list.
 */
fossil_flist_t* fossil_flist_create(fossil_tofu_type list_type);

/**
 * Erase the contents of the forward list and free allocated memory.
 *
 * @param flist The forward list to erase.
 */
void fossil_flist_erase(fossil_flist_t* flist);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the forward list.
 *
 * @param flist The forward list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_flist_insert(fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Remove data from the forward list.
 *
 * @param flist The forward list to remove data from.
 * @param data  A pointer to store the removed data.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_flist_remove(fossil_flist_t* flist, fossil_tofu_t* data);

/**
 * Search for data in the forward list.
 *
 * @param flist The forward list to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_flist_search(const fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Reverse the forward list in the forward direction.
 *
 * @param flist The forward list to reverse.
 */
void fossil_flist_reverse_forward(fossil_flist_t* flist);

/**
 * Reverse the forward list in the backward direction.
 *
 * @param flist The forward list to reverse.
 */
void fossil_flist_reverse_backward(fossil_flist_t* flist);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the forward list.
 *
 * @param flist The forward list for which to get the size.
 * @return      The size of the forward list.
 */
size_t fossil_flist_size(const fossil_flist_t* flist);

/**
 * Get the data from the forward list matching the specified data.
 *
 * @param flist The forward list from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data.
 */
fossil_tofu_t* fossil_flist_getter(fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Set data in the forward list.
 *
 * @param flist The forward list in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_flist_setter(fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Check if the forward list is not empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not empty, false otherwise.
 */
bool fossil_flist_not_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is not a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not a null pointer, false otherwise.
 */
bool fossil_flist_not_cnullptr(const fossil_flist_t* flist);

/**
 * Check if the forward list is empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is empty, false otherwise.
 */
bool fossil_flist_is_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is a null pointer, false otherwise.
 */
bool fossil_flist_is_cnullptr(const fossil_flist_t* flist);

#ifdef __cplusplus
}
#endif

#endif
