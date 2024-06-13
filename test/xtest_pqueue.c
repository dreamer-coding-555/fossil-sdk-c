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
#include "fossil/structures/pqueue.h" // lib source code

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST(test_pqueue_create_and_erase) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Check if the priority queue is created with the expected values
    ASSUME_NOT_CNULL(pqueue);
    ASSUME_ITS_CNULL(pqueue->front);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, pqueue->queue_type);

    fossil_pqueue_erase(pqueue);

    // Check if the priority queue is erased
    ASSUME_ITS_CNULL(pqueue->front);
    ASSUME_ITS_CNULL(pqueue);
}

FOSSIL_TEST(test_pqueue_insert_and_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element1, 2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element2, 1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element3, 3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_pqueue_size(pqueue));

    fossil_pqueue_erase(pqueue);
}

FOSSIL_TEST(test_pqueue_remove) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_pqueue_insert(pqueue, element1, 2);
    fossil_pqueue_insert(pqueue, element2, 1);
    fossil_pqueue_insert(pqueue, element3, 3);

    // Remove an element
    fossil_tofu_t removedElement;
    int removedPriority;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check if the removed element and priority are correct
    ASSUME_ITS_EQUAL_I32(10, removedElement.data.int_type);
    ASSUME_ITS_EQUAL_I32(1, removedPriority);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_pqueue_size(pqueue));

    fossil_pqueue_erase(pqueue);
}

FOSSIL_TEST(test_pqueue_not_empty_and_is_empty) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element, 2));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue));
    ASSUME_ITS_FALSE(fossil_pqueue_is_empty(pqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    int removedPriority;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue));

    fossil_pqueue_erase(pqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_pqueue_group) {
    ADD_TEST(test_pqueue_create_and_erase);
    ADD_TEST(test_pqueue_insert_and_size);
    ADD_TEST(test_pqueue_remove);
    ADD_TEST(test_pqueue_not_empty_and_is_empty);
} // end of func
