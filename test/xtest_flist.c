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
#include "fossil/structures/flist.h" // lib source code

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

FOSSIL_TEST(test_flist_create_and_erase) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Check if the linked list is created with the expected values
    ASSUME_NOT_CNULL(flist);
    ASSUME_ITS_CNULL(flist->head);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, flist->list_type);

    fossil_flist_erase(flist);

    // Check if the linked list is erased
    ASSUME_ITS_CNULL(flist->head);
    ASSUME_ITS_CNULL(flist);
}

FOSSIL_TEST(test_flist_insert_and_size) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_flist_size(flist));

    fossil_flist_erase(flist);
}

FOSSIL_TEST(test_flist_remove) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_flist_insert(flist, element1);
    fossil_flist_insert(flist, element2);
    fossil_flist_insert(flist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_remove(flist, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_flist_size(flist));

    fossil_flist_erase(flist);
}

FOSSIL_TEST(test_flist_reverse_forward) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

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
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->data.int_type);

    fossil_flist_erase(flist);
}

FOSSIL_TEST(test_flist_reverse_backward) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

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
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->data.int_type);

    fossil_flist_erase(flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_flist_group) {
    ADD_TEST(test_flist_create_and_erase);
    ADD_TEST(test_flist_insert_and_size);
    ADD_TEST(test_flist_remove);
    ADD_TEST(test_flist_reverse_forward);
    ADD_TEST(test_flist_reverse_backward);
} // end of func
