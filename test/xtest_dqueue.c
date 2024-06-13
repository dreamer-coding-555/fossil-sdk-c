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
#include "fossil/structures/dqueue.h" // lib source code

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

FOSSIL_TEST(test_dqueue_create_and_erase) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Check if the deque is created with the expected values
    ASSUME_NOT_CNULL(dqueue);
    ASSUME_ITS_CNULL(dqueue->front);
    ASSUME_ITS_CNULL(dqueue->rear);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, dqueue->list_type);

    fossil_dqueue_erase(dqueue);

    // Check if the deque is erased
    ASSUME_ITS_CNULL(dqueue->front);
    ASSUME_ITS_CNULL(dqueue->rear);
    ASSUME_ITS_CNULL(dqueue);
}

FOSSIL_TEST(test_dqueue_insert_and_size) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_dqueue_size(dqueue));

    fossil_dqueue_erase(dqueue);
}

FOSSIL_TEST(test_dqueue_remove) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dqueue_insert(dqueue, element1);
    fossil_dqueue_insert(dqueue, element2);
    fossil_dqueue_insert(dqueue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_remove(dqueue, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_dqueue_size(dqueue));

    fossil_dqueue_erase(dqueue);
}

FOSSIL_TEST(test_dqueue_getter_and_setter) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element));

    // Get the value for an element
    fossil_tofu_t* retrievedElement = fossil_dqueue_getter(dqueue, element);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    // Update the value for an element
    fossil_tofu_t updatedElement = { TOFU_INT_TYPE, { .int_type = 50 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_setter(dqueue, updatedElement));

    // Get the updated value for the element
    retrievedElement = fossil_dqueue_getter(dqueue, updatedElement);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(50, retrievedElement->data.int_type);

    fossil_dqueue_erase(dqueue);
}

FOSSIL_TEST(test_dqueue_not_empty_and_is_empty) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(dqueue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(dqueue));
    ASSUME_ITS_FALSE(fossil_dqueue_is_empty(dqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_remove(dqueue, &removedElement));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(dqueue));

    fossil_dqueue_erase(dqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_dqueue_group) {
    ADD_TEST(test_dqueue_create_and_erase);
    ADD_TEST(test_dqueue_insert_and_size);
    ADD_TEST(test_dqueue_remove);
    ADD_TEST(test_dqueue_getter_and_setter);
    ADD_TEST(test_dqueue_not_empty_and_is_empty);
} // end of func
