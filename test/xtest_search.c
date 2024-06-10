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
#include <fossil/xalgorithms/search.h> // library under test

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

XTEST(test_fossil_search_linear_key_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 20 });

    // Perform search
    int result = fossil_search_linear(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(2, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_linear_key_not_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 35 });

    // Perform search
    int result = fossil_search_linear(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_linear_empty_array) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 10 });

    // Perform search
    int result = fossil_search_linear(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_binary_key_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 20 });

    // Perform search
    int result = fossil_search_binary(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(2, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_binary_key_not_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 35 });

    // Perform search
    int result = fossil_search_binary(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_binary_empty_array) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 10 });

    // Perform search
    int result = fossil_search_binary(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_interpolation_key_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 20 });

    // Perform search
    int result = fossil_search_interpolation(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(2, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_interpolation_key_not_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 35 });

    // Perform search
    int result = fossil_search_interpolation(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

XTEST(test_fossil_search_interpolation_empty_array) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 10 });

    // Perform search
    int result = fossil_search_interpolation(array, key);

    // Check result
    TEST_ASSUME_EQUAL_INT(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(search_group) {
    // Run test cases for linear search
    XTEST_RUN_UNIT(test_fossil_search_linear_key_found);
    XTEST_RUN_UNIT(test_fossil_search_linear_key_not_found);
    XTEST_RUN_UNIT(test_fossil_search_linear_empty_array);

    // Run test cases for binary search
    XTEST_RUN_UNIT(test_fossil_search_binary_key_found);
    XTEST_RUN_UNIT(test_fossil_search_binary_key_not_found);
    XTEST_RUN_UNIT(test_fossil_search_binary_empty_array);

    // Run test cases for interpolation search
    XTEST_RUN_UNIT(test_fossil_search_interpolation_key_found);
    XTEST_RUN_UNIT(test_fossil_search_interpolation_key_not_found);
    XTEST_RUN_UNIT(test_fossil_search_interpolation_empty_array);
} // end of fixture
