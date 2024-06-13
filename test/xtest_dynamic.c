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
#include <fossil/xalgorithms/dynamic.h> // library under test

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

// Test case for concatenating two dynamic arrays
FOSSIL_TEST(test_fossil_concat_arrays) {
    // Create two dynamic arrays
    fossil_tofu_t* array1 = fossil_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    fossil_tofu_t* array2 = fossil_tofu_create_array(TOFU_INT_TYPE, 2, 4, 5);

    // Concatenate arrays
    fossil_tofu_t* result = fossil_dynamic_concat_arrays(array1, array2);

    // Check if result is not NULL
    ASSUME_NOT_CNULL(result);

    // Check if result is correct
    ASSUME_ITS_EQUAL_I32(1, fossil_tofu_iterator_start(result, 5).current_key->data.int_type);
    ASSUME_ITS_EQUAL_I32(2, fossil_tofu_iterator_start(result, 5).current_key[1].data.int_type);
    ASSUME_ITS_EQUAL_I32(3, fossil_tofu_iterator_start(result, 5).current_key[2].data.int_type);
    ASSUME_ITS_EQUAL_I32(4, fossil_tofu_iterator_start(result, 5).current_key[3].data.int_type);
    ASSUME_ITS_EQUAL_I32(5, fossil_tofu_iterator_start(result, 5).current_key[4].data.int_type);

    // Erase dynamic arrays
    fossil_tofu_erase_array(array1);
    fossil_tofu_erase_array(array2);
    fossil_tofu_erase_array(result);
}

// Test case for reversing a dynamic array
FOSSIL_TEST(test_fossil_reverse_array) {
    // Create a dynamic array
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 1, 2, 3, 4, 5);

    // Reverse the array
    fossil_tofu_t* reversed = fossil_dynamic_reverse_array(array);

    // Check if reversed is not NULL
    ASSUME_NOT_CNULL(reversed);

    // Check if reversed is correct
    ASSUME_ITS_EQUAL_I32(5, fossil_tofu_iterator_start(reversed, 5).current_key->data.int_type);
    ASSUME_ITS_EQUAL_I32(4, fossil_tofu_iterator_start(reversed, 5).current_key[1].data.int_type);
    ASSUME_ITS_EQUAL_I32(3, fossil_tofu_iterator_start(reversed, 5).current_key[2].data.int_type);
    ASSUME_ITS_EQUAL_I32(2, fossil_tofu_iterator_start(reversed, 5).current_key[3].data.int_type);
    ASSUME_ITS_EQUAL_I32(1, fossil_tofu_iterator_start(reversed, 5).current_key[4].data.int_type);

    // Erase dynamic arrays
    fossil_tofu_erase_array(array);
    fossil_tofu_erase_array(reversed);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(dynamic_group) {
    ADD_TEST(test_fossil_concat_arrays);
    ADD_TEST(test_fossil_reverse_array);
} // end of fixture
