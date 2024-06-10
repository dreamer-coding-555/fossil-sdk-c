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
#include "fossil/xstructures/dqueue.h" // lib source code

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

XTEST(test_dqueue_create_and_erase) {
    cdqueue* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Check if the deque is created with the expected values
    TEST_ASSUME_NOT_CNULLPTR(dqueue);
    TEST_ASSUME_CNULLPTR(dqueue->front);
    TEST_ASSUME_CNULLPTR(dqueue->rear);
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, dqueue->list_type);

    fossil_dqueue_erase(dqueue);

    // Check if the deque is erased
    TEST_ASSUME_CNULLPTR(dqueue->front);
    TEST_ASSUME_CNULLPTR(dqueue->rear);
    TEST_ASSUME_CNULLPTR(dqueue);
}

XTEST(test_dqueue_insert_and_size) {
    cdqueue* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element3));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(3, fossil_dqueue_size(dqueue));

    fossil_dqueue_erase(dqueue);
}

XTEST(test_dqueue_remove) {
    cdqueue* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dqueue_insert(dqueue, element1);
    fossil_dqueue_insert(dqueue, element2);
    fossil_dqueue_insert(dqueue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_remove(dqueue, &removedElement));

    // Check if the removed element is correct
    TEST_ASSUME_EQUAL_INT(42, removedElement.data.int_type);

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(2, fossil_dqueue_size(dqueue));

    fossil_dqueue_erase(dqueue);
}

XTEST(test_dqueue_getter_and_setter) {
    cdqueue* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element));

    // Get the value for an element
    fossil_tofu_t* retrievedElement = fossil_dqueue_getter(dqueue, element);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(42, retrievedElement->data.int_type);

    // Update the value for an element
    fossil_tofu_t updatedElement = { TOFU_INT_TYPE, { .int_type = 50 } };
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_setter(dqueue, updatedElement));

    // Get the updated value for the element
    retrievedElement = fossil_dqueue_getter(dqueue, updatedElement);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(50, retrievedElement->data.int_type);

    fossil_dqueue_erase(dqueue);
}

XTEST(test_dqueue_not_empty_and_is_empty) {
    cdqueue* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    TEST_ASSUME_FALSE(fossil_dqueue_not_empty(dqueue));
    TEST_ASSUME_TRUE(fossil_dqueue_is_empty(dqueue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element));

    // Check not empty after insertion
    TEST_ASSUME_TRUE(fossil_dqueue_not_empty(dqueue));
    TEST_ASSUME_FALSE(fossil_dqueue_is_empty(dqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_remove(dqueue, &removedElement));

    // Check empty after removal
    TEST_ASSUME_FALSE(fossil_dqueue_not_empty(dqueue));
    TEST_ASSUME_TRUE(fossil_dqueue_is_empty(dqueue));

    fossil_dqueue_erase(dqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_dqueue_group) {
    XTEST_RUN_UNIT(test_dqueue_create_and_erase);
    XTEST_RUN_UNIT(test_dqueue_insert_and_size);
    XTEST_RUN_UNIT(test_dqueue_remove);
    XTEST_RUN_UNIT(test_dqueue_getter_and_setter);
    XTEST_RUN_UNIT(test_dqueue_not_empty_and_is_empty);
} // end of func
