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
#include "fossil/xstructures/dlist.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST(test_dlist_create_and_erase) {
    cdlist* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Check if the doubly linked list is created with the expected values
    TEST_ASSUME_NOT_CNULLPTR(dlist);
    TEST_ASSUME_CNULLPTR(dlist->head);
    TEST_ASSUME_CNULLPTR(dlist->tail);
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, dlist->list_type);

    fossil_dlist_erase(dlist);

    // Check if the doubly linked list is erased
    TEST_ASSUME_CNULLPTR(dlist->head);
    TEST_ASSUME_CNULLPTR(dlist->tail);
    TEST_ASSUME_CNULLPTR(dlist);
}

XTEST(test_dlist_insert_and_size) {
    cdlist* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dlist_insert(dlist, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dlist_insert(dlist, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dlist_insert(dlist, element3));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(3, fossil_dlist_size(dlist));

    fossil_dlist_erase(dlist);
}

XTEST(test_dlist_remove) {
    cdlist* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dlist_insert(dlist, element1);
    fossil_dlist_insert(dlist, element2);
    fossil_dlist_insert(dlist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_dlist_remove(dlist, &removedElement));

    // Check if the removed element is correct
    TEST_ASSUME_EQUAL_INT(42, removedElement.data.int_type);

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(2, fossil_dlist_size(dlist));

    fossil_dlist_erase(dlist);
}

XTEST(test_dlist_reverse_forward) {
    cdlist* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dlist_insert(dlist, element1);
    fossil_dlist_insert(dlist, element2);
    fossil_dlist_insert(dlist, element3);

    // Reverse the doubly linked list forward
    fossil_dlist_reverse_forward(dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(dlist, element3);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(42, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element2);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(10, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element1);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(5, retrievedElement->data.int_type);

    fossil_dlist_erase(dlist);
}

XTEST(test_dlist_reverse_backward) {
    cdlist* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dlist_insert(dlist, element1);
    fossil_dlist_insert(dlist, element2);
    fossil_dlist_insert(dlist, element3);

    // Reverse the doubly linked list backward
    fossil_dlist_reverse_backward(dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(dlist, element3);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(42, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element2);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(10, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element1);
    TEST_ASSUME_NOT_CNULLPTR(retrievedElement);
    TEST_ASSUME_EQUAL_INT(5, retrievedElement->data.int_type);

    fossil_dlist_erase(dlist);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(test_dlist_group) {
    XTEST_RUN_UNIT(test_dlist_create_and_erase);
    XTEST_RUN_UNIT(test_dlist_insert_and_size);
    XTEST_RUN_UNIT(test_dlist_remove);
    XTEST_RUN_UNIT(test_dlist_reverse_forward);
    XTEST_RUN_UNIT(test_dlist_reverse_backward);
} // end of func
