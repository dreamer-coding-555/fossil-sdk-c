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
#ifndef FOSSIL_STRUCTURES_QUEUE_H
#define FOSSIL_STRUCTURES_QUEUE_H

/**
 * @brief Queue Data Structure
 * 
 * This library provides functions for working with queues, which are linear data structures
 * that follow the First-In-First-Out (FIFO) principle.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup enqueue_enqueue Enqueue and Dequeue Functions
 * @defgroup front_back Front and Back Functions
 * @defgroup capacity Capacity Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/tofu/tofu.h"

// Node structure for the queue
typedef struct cqueue_node {
    fossil_tofu_t data;
    struct cqueue_node* next;
} cqueue_node;

// Queue structure
typedef struct cqueue {
    cqueue_node* front;
    cqueue_node* rear;
    fossil_tofu_type queue_type;  // Type of the queue
} cqueue;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new queue with the specified data type.
 *
 * @param list_type The type of data the queue will store.
 * @return          The created queue.
 */
cqueue* fossil_queue_create(fossil_tofu_type list_type);

/**
 * Erase the contents of the queue and free allocated memory.
 *
 * @param queue The queue to erase.
 */
void fossil_queue_erase(cqueue* queue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the queue.
 *
 * @param queue The queue to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_queue_insert(cqueue* queue, fossil_tofu_t data);

/**
 * Remove data from the queue.
 *
 * @param queue The queue to remove data from.
 * @param data  The data to remove.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_queue_remove(cqueue* queue, fossil_tofu_t* data);

/**
 * Search for data in the queue.
 *
 * @param queue The queue to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_queue_search(const cqueue* queue, fossil_tofu_t data);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the queue.
 *
 * @param queue The queue for which to get the size.
 * @return      The size of the queue.
 */
size_t fossil_queue_size(const cqueue* queue);

/**
 * Get the data from the queue matching the specified data.
 *
 * @param queue The queue from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data, or NULL if not found.
 */
fossil_tofu_t* fossil_queue_getter(cqueue* queue, fossil_tofu_t data);

/**
 * Set data in the queue.
 *
 * @param queue The queue in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_queue_setter(cqueue* queue, fossil_tofu_t data);

/**
 * Check if the queue is not empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not empty, false otherwise.
 */
bool fossil_queue_not_empty(const cqueue* queue);

/**
 * Check if the queue is not a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not a null pointer, false otherwise.
 */
bool fossil_queue_not_cnullptr(const cqueue* queue);

/**
 * Check if the queue is empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is empty, false otherwise.
 */
bool fossil_queue_is_empty(const cqueue* queue);

/**
 * Check if the queue is a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is a null pointer, false otherwise.
 */
bool fossil_queue_is_cnullptr(const cqueue* queue);

#ifdef __cplusplus
}
#endif

#endif
