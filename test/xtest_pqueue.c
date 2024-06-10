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
#include "fossil/xstructures/pqueue.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
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
XTEST(test_pqueue_create_and_erase) {
    cpqueue* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Check if the priority queue is created with the expected values
    TEST_ASSUME_NOT_CNULLPTR(pqueue);
    TEST_ASSUME_CNULLPTR(pqueue->front);
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, pqueue->queue_type);

    fossil_pqueue_erase(pqueue);

    // Check if the priority queue is erased
    TEST_ASSUME_CNULLPTR(pqueue->front);
    TEST_ASSUME_CNULLPTR(pqueue);
}

XTEST(test_pqueue_insert_and_size) {
    cpqueue* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element1, 2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element2, 1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element3, 3));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(3, fossil_pqueue_size(pqueue));

    fossil_pqueue_erase(pqueue);
}

XTEST(test_pqueue_remove) {
    cpqueue* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

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
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check if the removed element and priority are correct
    TEST_ASSUME_EQUAL_INT(10, removedElement.data.int_type);
    TEST_ASSUME_EQUAL_INT(1, removedPriority);

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(2, fossil_pqueue_size(pqueue));

    fossil_pqueue_erase(pqueue);
}

XTEST(test_pqueue_not_empty_and_is_empty) {
    cpqueue* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    TEST_ASSUME_FALSE(fossil_pqueue_not_empty(pqueue));
    TEST_ASSUME_TRUE(fossil_pqueue_is_empty(pqueue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element, 2));

    // Check not empty after insertion
    TEST_ASSUME_TRUE(fossil_pqueue_not_empty(pqueue));
    TEST_ASSUME_FALSE(fossil_pqueue_is_empty(pqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    int removedPriority;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check empty after removal
    TEST_ASSUME_FALSE(fossil_pqueue_not_empty(pqueue));
    TEST_ASSUME_TRUE(fossil_pqueue_is_empty(pqueue));

    fossil_pqueue_erase(pqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_pqueue_group) {
    XTEST_RUN_UNIT(test_pqueue_create_and_erase);
    XTEST_RUN_UNIT(test_pqueue_insert_and_size);
    XTEST_RUN_UNIT(test_pqueue_remove);
    XTEST_RUN_UNIT(test_pqueue_not_empty_and_is_empty);
} // end of func
