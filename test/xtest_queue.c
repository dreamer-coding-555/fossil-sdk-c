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
#include "fossil/xstructures/queue.h" // lib source code

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

FOSSIL_TEST(test_queue_create_and_erase) {
    cqueue* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Check if the queue is created with the expected values
    ASSUME_NOT_CNULL(queue);
    ASSUME_ITS_CNULL(queue->front);
    ASSUME_ITS_CNULL(queue->rear);
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, queue->queue_type);

    fossil_queue_erase(queue);

    // Check if the queue is erased
    ASSUME_ITS_CNULL(queue->front);
    ASSUME_ITS_CNULL(queue->rear);
    ASSUME_ITS_CNULL(queue);
}

FOSSIL_TEST(test_queue_insert_and_size) {
    cqueue* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element3));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(3, fossil_queue_size(queue));

    fossil_queue_erase(queue);
}

FOSSIL_TEST(test_queue_remove) {
    cqueue* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_queue_insert(queue, element1);
    fossil_queue_insert(queue, element2);
    fossil_queue_insert(queue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_queue_remove(queue, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.data.int_type);

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(2, fossil_queue_size(queue));

    fossil_queue_erase(queue);
}

FOSSIL_TEST(test_queue_not_empty_and_is_empty) {
    cqueue* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Check initially not empty
    TEST_ASSUME_FALSE(fossil_queue_not_empty(queue));
    TEST_ASSUME_TRUE(fossil_queue_is_empty(queue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element));

    // Check not empty after insertion
    TEST_ASSUME_TRUE(fossil_queue_not_empty(queue));
    TEST_ASSUME_FALSE(fossil_queue_is_empty(queue));

    // Remove the element
    fossil_tofu_t removedElement;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_queue_remove(queue, &removedElement));

    // Check empty after removal
    TEST_ASSUME_FALSE(fossil_queue_not_empty(queue));
    TEST_ASSUME_TRUE(fossil_queue_is_empty(queue));

    fossil_queue_erase(queue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_queue_group) {
    ADD_TEST(test_queue_create_and_erase);
    ADD_TEST(test_queue_insert_and_size);
    ADD_TEST(test_queue_remove);
    ADD_TEST(test_queue_not_empty_and_is_empty);
} // end of func
