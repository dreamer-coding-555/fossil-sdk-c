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
#include "fossil/xstructures/flist.h" // lib source code

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

XTEST(test_flist_create_and_erase) {
    cflist* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Check if the linked list is created with the expected values
    TEST_ASSUME_NOT_CNULLPTR(flist);
    TEST_ASSUME_CNULLPTR(flist->head);
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, flist->list_type);

    fossil_flist_erase(flist);

    // Check if the linked list is erased
    TEST_ASSUME_CNULLPTR(flist->head);
    TEST_ASSUME_CNULLPTR(flist);
}

XTEST(test_flist_insert_and_size) {
    cflist* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element3));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(3, fossil_flist_size(flist));

    fossil_flist_erase(flist);
}

XTEST(test_flist_remove) {
    cflist* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_flist_insert(flist, element1);
    fossil_flist_insert(flist, element2);
    fossil_flist_insert(flist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_flist_remove(flist, &removedElement));

    // Check if the removed element is correct
    TEST_ASSUME_EQUAL_INT(42, removedElement.data.int_type);

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(2, fossil_flist_size(flist));

    fossil_flist_erase(flist);
}

XTEST(test_flist_reverse_forward) {
    cflist* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_flist_insert(flist, element1);
    fossil_flist_insert(flist, element2);
    fossil_flist_insert(flist, element3);

    // Reverse the linked list forward
    fossil_flist_reverse_forward(flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(flist, element3);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(42, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element2);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(10, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element1);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(5, retrievedElement->data.int_type);

    fossil_flist_erase(flist);
}

XTEST(test_flist_reverse_backward) {
    cflist* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_flist_insert(flist, element1);
    fossil_flist_insert(flist, element2);
    fossil_flist_insert(flist, element3);

    // Reverse the linked list backward
    fossil_flist_reverse_backward(flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(flist, element3);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(42, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element2);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(10, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element1);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(5, retrievedElement->data.int_type);

    fossil_flist_erase(flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_flist_group) {
    XTEST_RUN_UNIT(test_flist_create_and_erase);
    XTEST_RUN_UNIT(test_flist_insert_and_size);
    XTEST_RUN_UNIT(test_flist_remove);
    XTEST_RUN_UNIT(test_flist_reverse_forward);
    XTEST_RUN_UNIT(test_flist_reverse_backward);
} // end of func
