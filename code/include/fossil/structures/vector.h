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
#ifndef FOSSIL_STRUCTURES_VECT_H
#define FOSSIL_STRUCTURES_VECT_H

/**
 * @brief Vector Data Structure
 * 
 * This library provides functions for working with vectors, which are dynamic arrays
 * that can resize themselves automatically when elements are added or removed.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup access Access Functions
 * @defgroup modify Modify Functions
 * @defgroup capacity Capacity Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/tofu/tofu.h"

#define INITIAL_CAPACITY 10

typedef struct {
    fossil_tofu_t* data;
    size_t size;
    size_t capacity;
    fossil_tofu_type expected_type;
} cvector;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================

/**
 * Create a new vector with the specified expected type.
 *
 * @param expected_type The expected type of elements in the vector.
 * @return              The created vector.
 */
cvector fossil_vector_create(fossil_tofu_type expected_type);

/**
 * Erase the contents of the vector and free allocated memory.
 *
 * @param vector The vector to erase.
 */
void fossil_vector_erase(cvector* vector);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Add an element to the end of the vector.
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_back(cvector* vector, fossil_tofu_t element);

/**
 * Search for a target element in the vector.
 *
 * @param vector The vector to search.
 * @param target The element to search for.
 * @return       The index of the target element, or -1 if not found.
 */
int fossil_vector_search(const cvector* vector, fossil_tofu_t target);

/**
 * Reverse the order of elements in the vector.
 *
 * @param vector The vector to reverse.
 */
void fossil_vector_reverse(cvector* vector);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Check if the vector is a null pointer.
 *
 * @param vector The vector to check.
 * @return       True if the vector is a null pointer, false otherwise.
 */
bool fossil_vector_is_cnullptr(const cvector* vector);

/**
 * Check if the vector is not a null pointer.
 *
 * @param vector The vector to check.
 * @return       True if the vector is not a null pointer, false otherwise.
 */
bool fossil_vector_not_cnullptr(const cvector* vector);

/**
 * Check if the vector is empty.
 *
 * @param vector The vector to check.
 * @return       True if the vector is empty, false otherwise.
 */
bool fossil_vector_is_empty(const cvector* vector);

/**
 * Check if the vector is not empty.
 *
 * @param vector The vector to check.
 * @return       True if the vector is not empty, false otherwise.
 */
bool fossil_vector_not_empty(const cvector* vector);

/**
 * Set the element at the specified index in the vector.
 *
 * @param vector The vector in which to set the element.
 * @param index  The index at which to set the element.
 * @param element The element to set.
 */
void fossil_vector_setter(cvector* vector, size_t index, fossil_tofu_t element);

/**
 * Get the element at the specified index in the vector.
 *
 * @param vector The vector from which to get the element.
 * @param index  The index from which to get the element.
 * @return       The element at the specified index.
 */
fossil_tofu_t fossil_vector_getter(const cvector* vector, size_t index);

/**
 * Get the size of the vector.
 *
 * @param vector The vector for which to get the size.
 * @return       The size of the vector.
 */
size_t fossil_vector_size(const cvector* vector);

/**
 * Display the contents of the vector.
 *
 * @param vector The vector to peek into.
 */
void fossil_vector_peek(const cvector* vector);

#ifdef __cplusplus
}
#endif

#endif
