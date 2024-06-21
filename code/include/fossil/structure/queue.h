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

#include "fossil/generic/tofu.h"
#include "fossil/generic/actionof.h"

// Node structure for the queue
typedef struct fossil_queue_node_t {
    fossil_tofu_t data;
    struct fossil_queue_node_t* next;
} fossil_queue_node_t;

// Queue structure
typedef struct fossil_queue_t {
    fossil_queue_node_t* front;
    fossil_queue_node_t* rear;
    char* type;
} fossil_queue_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Create a new queue with the specified data type.
 *
 * @param list_type The type of data the queue will store.
 * @return          The created queue.
 */
fossil_queue_t* fossil_queue_create(char* type);

/**
 * Erase the contents of the queue and free allocated memory.
 *
 * @param queue The queue to erase.
 */
void fossil_queue_erase(fossil_queue_t* queue);

/**
 * Insert data into the queue.
 *
 * @param queue The queue to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
int32_t fossil_queue_insert(fossil_queue_t* queue, fossil_tofu_t data);

/**
 * Remove data from the queue.
 *
 * @param queue The queue to remove data from.
 * @param data  The data to remove.
 * @return      The error code indicating the success or failure of the operation.
 */
int32_t fossil_queue_remove(fossil_queue_t* queue, fossil_tofu_t* data);

/**
 * Search for data in the queue.
 *
 * @param queue The queue to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
int32_t fossil_queue_search(const fossil_queue_t* queue, fossil_tofu_t data);

/**
 * Get the size of the queue.
 *
 * @param queue The queue for which to get the size.
 * @return      The size of the queue.
 */
size_t fossil_queue_size(const fossil_queue_t* queue);

/**
 * Get the data from the queue matching the specified data.
 *
 * @param queue The queue from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data, or NULL if not found.
 */
fossil_tofu_t* fossil_queue_getter(fossil_queue_t* queue, fossil_tofu_t data);

/**
 * Set data in the queue.
 *
 * @param queue The queue in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
int32_t fossil_queue_setter(fossil_queue_t* queue, fossil_tofu_t data);

/**
 * Check if the queue is not empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not empty, false otherwise.
 */
bool fossil_queue_not_empty(const fossil_queue_t* queue);

/**
 * Check if the queue is not a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not a null pointer, false otherwise.
 */
bool fossil_queue_not_cnullptr(const fossil_queue_t* queue);

/**
 * Check if the queue is empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is empty, false otherwise.
 */
bool fossil_queue_is_empty(const fossil_queue_t* queue);

/**
 * Check if the queue is a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is a null pointer, false otherwise.
 */
bool fossil_queue_is_cnullptr(const fossil_queue_t* queue);

#ifdef __cplusplus
}
#endif

#endif
