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
#ifndef FOSSIL_STRUCTURES_DQUEUE_H
#define FOSSIL_STRUCTURES_DQUEUE_H

/**
 * @brief Double-ended Queue Data Structure
 * 
 * This library provides functions for working with double-ended queues (deques), which are
 * linear data structures that allow insertion and deletion of elements from both ends.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup push_pop Push and Pop Functions
 * @defgroup front_back Front and Back Functions
 * @defgroup capacity Capacity Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/tofu/tofu.h"

// Node structure for the double-ended queue
typedef struct cdqueue_node {
    fossil_tofu_t data;
    struct cdqueue_node* prev;
    struct cdqueue_node* next;
} cdqueue_node;

// Double-ended queue structure
typedef struct cdqueue {
    cdqueue_node* front;
    cdqueue_node* rear;
    fossil_tofu_type list_type;  // Type of the deque
} cdqueue;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new dynamic queue with the specified data type.
 *
 * @param list_type The type of data the dynamic queue will store.
 * @return          The created dynamic queue.
 */
cdqueue* fossil_dqueue_create(fossil_tofu_type list_type);

/**
 * Erase the contents of the dynamic queue and free allocated memory.
 *
 * @param dqueue The dynamic queue to erase.
 */
void fossil_dqueue_erase(cdqueue* dqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the dynamic queue.
 *
 * @param dqueue The dynamic queue to insert data into.
 * @param data   The data to insert.
 * @return       The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dqueue_insert(cdqueue* dqueue, fossil_tofu_t data);

/**
 * Remove data from the dynamic queue.
 *
 * @param dqueue The dynamic queue to remove data from.
 * @param data   A pointer to store the removed data.
 * @return       The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dqueue_remove(cdqueue* dqueue, fossil_tofu_t* data);

/**
 * Search for data in the dynamic queue.
 *
 * @param dqueue The dynamic queue to search.
 * @param data   The data to search for.
 * @return       The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dqueue_search(const cdqueue* dqueue, fossil_tofu_t data);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the dynamic queue.
 *
 * @param dqueue The dynamic queue for which to get the size.
 * @return       The size of the dynamic queue.
 */
size_t fossil_dqueue_size(const cdqueue* dqueue);

/**
 * Get the data from the dynamic queue matching the specified data.
 *
 * @param dqueue The dynamic queue from which to get the data.
 * @param data   The data to search for.
 * @return       A pointer to the matching data.
 */
fossil_tofu_t* fossil_dqueue_getter(cdqueue* dqueue, fossil_tofu_t data);

/**
 * Set data in the dynamic queue.
 *
 * @param dqueue The dynamic queue in which to set the data.
 * @param data   The data to set.
 * @return       The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_dqueue_setter(cdqueue* dqueue, fossil_tofu_t data);

/**
 * Check if the dynamic queue is not empty.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is not empty, false otherwise.
 */
bool fossil_dqueue_not_empty(const cdqueue* dqueue);

/**
 * Check if the dynamic queue is not a null pointer.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is not a null pointer, false otherwise.
 */
bool fossil_dqueue_not_cnullptr(const cdqueue* dqueue);

/**
 * Check if the dynamic queue is empty.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is empty, false otherwise.
 */
bool fossil_dqueue_is_empty(const cdqueue* dqueue);

/**
 * Check if the dynamic queue is a null pointer.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is a null pointer, false otherwise.
 */
bool fossil_dqueue_is_cnullptr(const cdqueue* dqueue);

#ifdef __cplusplus
}
#endif

#endif
