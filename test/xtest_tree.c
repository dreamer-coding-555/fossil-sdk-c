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
#include "fossil/xstructures/tree.h" // lib source code

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

XTEST(test_tree_create_and_erase) {
    ctree* tree = fossil_tree_create(TOFU_INT_TYPE);
    
    // Check if the tree is created with the expected values
    TEST_ASSUME_NOT_CNULLPTR(tree);
    TEST_ASSUME_CNULLPTR(tree->root);
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, tree->tree);

    fossil_tree_erase(tree);

    // Check if the tree is erased
    TEST_ASSUME_CNULLPTR(tree->root);
    TEST_ASSUME_CNULLPTR(tree);
}

XTEST(test_tree_insert_and_search) {
    ctree* tree = fossil_tree_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_insert(tree, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_insert(tree, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_insert(tree, element3));

    // Search for elements
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_search(tree, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_search(tree, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_search(tree, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS, fossil_tree_search(tree, nonExistingElement));

    fossil_tree_erase(tree);
}

XTEST(test_tree_remove) {
    ctree* tree = fossil_tree_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_tree_insert(tree, element1);
    fossil_tree_insert(tree, element2);
    fossil_tree_insert(tree, element3);

    // Remove an element
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_remove(tree, element2));

    // Search for removed and remaining elements
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS, fossil_tree_search(tree, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_search(tree, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_tree_search(tree, element3));

    fossil_tree_erase(tree);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_tree_group) {
    XTEST_RUN_UNIT(test_tree_create_and_erase);
    XTEST_RUN_UNIT(test_tree_insert_and_search);
    XTEST_RUN_UNIT(test_tree_remove);
} // end of func
