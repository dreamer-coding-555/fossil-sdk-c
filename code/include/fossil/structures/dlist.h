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
#ifndef FOSSIL_STRUCTURES_DLIST_H
#define FOSSIL_STRUCTURES_DLIST_H

/**
 * @brief Doubly Linked List Operations
 * 
 * This library provides functions for working with doubly linked lists.
 * Doubly linked lists are a type of linked list where each node contains
 * pointers to both the next and previous nodes.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup algorithm Algorithm Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/tofu/tofu.h"

// Node structure for the doubly linked list
typedef struct cdlist_node {
    fossil_tofu_t data;
    struct cdlist_node* prev;
    struct cdlist_node* next;
} cdlist_node;

// Doubly linked list structure
typedef struct cdlist {
    cdlist_node* head;
    cdlist_node* tail;
    fossil_tofu_type list_type;  // Type of the linked list
} cdlist;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================

/**
 * Create a new doubly linked list with the specified data type.
 *
 * @param list_type The type of data the doubly linked list will store.
 * @return          The created doubly linked list.
 */
cdlist* fossil_dlist_create(fossil_tofu_type list_type);

/**
 * Erase the contents of the doubly linked list and free allocated memory.
 *
 * @param dlist The doubly linked list to erase.
 */
void fossil_dlist_erase(cdlist* dlist);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * Insert data into the doubly linked list.
 *
 * @param dlist The doubly linked list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dlist_insert(cdlist* dlist, fossil_tofu_t data);

/**
 * Remove data from the doubly linked list.
 *
 * @param dlist The doubly linked list to remove data from.
 * @param data  A pointer to store the removed data.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dlist_remove(cdlist* dlist, fossil_tofu_t* data);

/**
 * Search for data in the doubly linked list.
 *
 * @param dlist The doubly linked list to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dlist_search(const cdlist* dlist, fossil_tofu_t data);

/**
 * Reverse the doubly linked list in the forward direction.
 *
 * @param dlist The doubly linked list to reverse.
 */
void fossil_dlist_reverse_forward(cdlist* dlist);

/**
 * Reverse the doubly linked list in the backward direction.
 *
 * @param dlist The doubly linked list to reverse.
 */
void fossil_dlist_reverse_backward(cdlist* dlist);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the doubly linked list.
 *
 * @param dlist The doubly linked list for which to get the size.
 * @return      The size of the doubly linked list.
 */
size_t fossil_dlist_size(const cdlist* dlist);

/**
 * Get the data from the doubly linked list matching the specified data.
 *
 * @param dlist The doubly linked list from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data.
 */
fossil_tofu_t* fossil_dlist_getter(cdlist* dlist, fossil_tofu_t data);

/**
 * Set data in the doubly linked list.
 *
 * @param dlist The doubly linked list in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dlist_setter(cdlist* dlist, fossil_tofu_t data);

/**
 * Check if the doubly linked list is not empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not empty, false otherwise.
 */
bool fossil_dlist_not_empty(const cdlist* dlist);

/**
 * Check if the doubly linked list is not a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not a null pointer, false otherwise.
 */
bool fossil_dlist_not_cnullptr(const cdlist* dlist);

/**
 * Check if the doubly linked list is empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is empty, false otherwise.
 */
bool fossil_dlist_is_empty(const cdlist* dlist);

/**
 * Check if the doubly linked list is a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is a null pointer, false otherwise.
 */
bool fossil_dlist_is_cnullptr(const cdlist* dlist);

#ifdef __cplusplus
}
#endif

#endif
