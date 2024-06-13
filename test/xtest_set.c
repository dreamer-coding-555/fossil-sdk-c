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
#include "fossil/structures/set.h" // lib source code

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

FOSSIL_TEST(test_set_create_and_erase) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Check if the set is created with the expected values
    ASSUME_NOT_CNULL(set);
    ASSUME_ITS_CNULL(set->head);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, set->set_type);

    fossil_set_erase(set);

    // Check if the set is erased
    ASSUME_ITS_CNULL(set->head);
    ASSUME_ITS_CNULL(set);
}

FOSSIL_TEST(test_set_insert_and_size) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_insert(set, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_insert(set, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_insert(set, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_set_size(set));

    fossil_set_erase(set);
}

FOSSIL_TEST(test_set_remove) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_set_insert(set, element1);
    fossil_set_insert(set, element2);
    fossil_set_insert(set, element3);

    // Remove an element
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_remove(set, element2));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_set_size(set));

    fossil_set_erase(set);
}

FOSSIL_TEST(test_set_contains) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_set_insert(set, element1);
    fossil_set_insert(set, element2);
    fossil_set_insert(set, element3);

    // Check if elements are contained in the set
    ASSUME_ITS_TRUE(fossil_set_contains(set, element1));
    ASSUME_ITS_TRUE(fossil_set_contains(set, element3));

    // Check for non-existing element
    fossil_tofu_t nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    ASSUME_ITS_FALSE(fossil_set_contains(set, nonExistingElement));

    fossil_set_erase(set);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_set_group) {
    ADD_TEST(test_set_create_and_erase);
    ADD_TEST(test_set_insert_and_size);
    ADD_TEST(test_set_remove);
    ADD_TEST(test_set_contains);
} // end of func
