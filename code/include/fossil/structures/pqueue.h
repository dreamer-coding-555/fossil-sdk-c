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
#ifndef FOSSIL_STRUCTURES_PQUEUE_H
#define FOSSIL_STRUCTURES_PQUEUE_H

/**
 * @brief Priority Queue Data Structure
 * 
 * This library provides functions for working with priority queues, which are data structures
 * that store elements based on their priority. Elements with higher priority are dequeued first.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup push_pop Push and Pop Functions
 * @defgroup front Front Function
 * @defgroup capacity Capacity Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/tofu/tofu.h"

typedef struct fossil_pqueue_node_t {
    fossil_tofu_t data;
    int priority;
    struct fossil_pqueue_node_t* next;
} fossil_pqueue_node_t;

typedef struct fossil_pqueue_t {
    fossil_pqueue_node_t* front;
    fossil_tofu_type queue_type;
} fossil_pqueue_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new priority queue with the specified data type.
 *
 * @param queue_type The type of data the priority queue will store.
 * @return           The created priority queue.
 */
fossil_pqueue_t* fossil_pqueue_create(fossil_tofu_type queue_type);

/**
 * Erase the contents of the priority queue and free allocated memory.
 *
 * @param pqueue The priority queue to erase.
 */
void fossil_pqueue_erase(fossil_pqueue_t* pqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue to insert data into.
 * @param data     The data to insert.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority);

/**
 * Remove data from the priority queue.
 *
 * @param pqueue   The priority queue to remove data from.
 * @param data     The data to remove.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, fossil_tofu_t* data, int* priority);

/**
 * Search for data in the priority queue.
 *
 * @param pqueue   The priority queue to search.
 * @param data     The data to search for.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_pqueue_search(const fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the priority queue.
 *
 * @param pqueue The priority queue for which to get the size.
 * @return       The size of the priority queue.
 */
size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue);

/**
 * Get the data from the priority queue matching the specified data and priority.
 *
 * @param pqueue   The priority queue from which to get the data.
 * @param data     The data to search for.
 * @param priority The priority of the data.
 * @return         A pointer to the matching data, or NULL if not found.
 */
fossil_tofu_t* fossil_pqueue_getter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority);

/**
 * Set data in the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue in which to set the data.
 * @param data     The data to set.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_pqueue_setter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority);

/**
 * Check if the priority queue is not empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not empty, false otherwise.
 */
bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is not a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not a null pointer, false otherwise.
 */
bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is empty, false otherwise.
 */
bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is a null pointer, false otherwise.
 */
bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue);

#ifdef __cplusplus
}
#endif

#endif
