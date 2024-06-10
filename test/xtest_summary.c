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
#include <fossil/xalgorithms/summary.h> // library under test

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

XTEST(test_fossil_summary_sum) {
    fossil_tofu_error_t error;
    fossil_tofu_t array;
    fossil_tofu_t sum;

    // Case 1: Empty array
    array.type = TOFU_INT_TYPE;
    array.data.int_type = 0;
    error = fossil_summary_sum(&array, &sum);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(0, sum.data.int_type);

    // Case 2: Array with positive integers
    int int_values[] = {1, 2, 3, 4, 5};
    array.type = TOFU_ARRAY_TYPE;
    array.data.array_type.size = 5;
    array.data.array_type.elements = (fossil_tofu_t*)malloc(5 * sizeof(fossil_tofu_t));
    for (size_t i = 0; i < 5; i++) {
        array.data.array_type.elements[i].type = TOFU_INT_TYPE;
        array.data.array_type.elements[i].data.int_type = int_values[i];
    }
    error = fossil_summary_sum(&array, &sum);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(15, sum.data.int_type);
    free(array.data.array_type.elements);

    // Case 3: Array with negative integers
    int neg_values[] = {-1, -2, -3, -4, -5};
    array.type = TOFU_ARRAY_TYPE;
    array.data.array_type.size = 5;
    array.data.array_type.elements = (fossil_tofu_t*)malloc(5 * sizeof(fossil_tofu_t));
    for (size_t i = 0; i < 5; i++) {
        array.data.array_type.elements[i].type = TOFU_INT_TYPE;
        array.data.array_type.elements[i].data.int_type = neg_values[i];
    }
    error = fossil_summary_sum(&array, &sum);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(-15, sum.data.int_type);
    free(array.data.array_type.elements);
}

XTEST(test_fossil_summary_mean) {
    fossil_tofu_error_t error;
    fossil_tofu_t array;
    fossil_tofu_t mean;

    // Case 1: Empty array
    array.type = TOFU_INT_TYPE;
    array.data.int_type = 0;
    error = fossil_summary_mean(&array, &mean);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(0, mean.data.int_type);

    // Case 2: Array with positive integers
    int int_values[] = {1, 2, 3, 4, 5};
    array.type = TOFU_ARRAY_TYPE;
    array.data.array_type.size = 5;
    array.data.array_type.elements = (fossil_tofu_t*)malloc(5 * sizeof(fossil_tofu_t));
    for (size_t i = 0; i < 5; i++) {
        array.data.array_type.elements[i].type = TOFU_INT_TYPE;
        array.data.array_type.elements[i].data.int_type = int_values[i];
    }
    error = fossil_summary_mean(&array, &mean);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(3, mean.data.int_type);
    free(array.data.array_type.elements);

    // Case 3: Array with negative integers
    int neg_values[] = {-1, -2, -3, -4, -5};
    array.type = TOFU_ARRAY_TYPE;
    array.data.array_type.size = 5;
    array.data.array_type.elements = (fossil_tofu_t*)malloc(5 * sizeof(fossil_tofu_t));
    for (size_t i = 0; i < 5; i++) {
        array.data.array_type.elements[i].type = TOFU_INT_TYPE;
        array.data.array_type.elements[i].data.int_type = neg_values[i];
    }
    error = fossil_summary_mean(&array, &mean);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(-3, mean.data.int_type);
    free(array.data.array_type.elements);
}

XTEST(test_fossil_summary_median) {
    fossil_tofu_error_t error;
    fossil_tofu_t array;
    fossil_tofu_t median;

    // Case 1: Empty array
    array.type = TOFU_INT_TYPE;
    array.data.int_type = 0;
    error = fossil_summary_median(&array, &median);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS, error);

    // Case 2: Array with odd number of elements
    int odd_values[] = {1, 3, 2, 5, 4};
    array.type = TOFU_ARRAY_TYPE;
    array.data.array_type.size = 5;
    array.data.array_type.elements = (fossil_tofu_t*)malloc(5 * sizeof(fossil_tofu_t));
    for (size_t i = 0; i < 5; i++) {
        array.data.array_type.elements[i].type = TOFU_INT_TYPE;
        array.data.array_type.elements[i].data.int_type = odd_values[i];
    }
    error = fossil_summary_median(&array, &median);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(3, median.data.int_type);
    free(array.data.array_type.elements);

    // Case 3: Array with even number of elements
    int even_values[] = {1, 3, 2, 4};
    array.type = TOFU_ARRAY_TYPE;
    array.data.array_type.size = 4;
    array.data.array_type.elements = (fossil_tofu_t*)malloc(4 * sizeof(fossil_tofu_t));
    for (size_t i = 0; i < 4; i++) {
        array.data.array_type.elements[i].type = TOFU_INT_TYPE;
        array.data.array_type.elements[i].data.int_type = even_values[i];
    }
    error = fossil_summary_median(&array, &median);
    TEST_ASSUME_EQUAL_INT(FOSSIL_TOFU_ERROR_OK, error);
    TEST_ASSUME_EQUAL_INT(2, median.data.int_type);
    free(array.data.array_type.elements);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(summary_group) {
    XTEST_RUN_UNIT(test_fossil_summary_sum);
    XTEST_RUN_UNIT(test_fossil_summary_mean);
    XTEST_RUN_UNIT(test_fossil_summary_median);
} // end of fixture
