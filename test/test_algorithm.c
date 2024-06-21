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
#include <fossil/algorithm/dynamic.h>
#include <fossil/algorithm/greedy.h>
#include <fossil/algorithm/search.h>
#include <fossil/algorithm/sort.h>
#include <fossil/algorithm/summary.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts
#include <fossil/mockup/file.h>

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test dynamic algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_dynamic_fixture);
FOSSIL_SETUP(algo_dynamic_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_dynamic_fixture) {
    // Teardown code if needed
}

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
// * Fossil Logic Test greedy algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_greedy_fixture);
FOSSIL_SETUP(algo_greedy_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_greedy_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_fossil_greedy_coin_change) {
    // Test case 1: Standard case
    fossil_tofu_t* coins1 = fossil_tofu_create_array(TOFU_INT_TYPE, 4, 1, 2, 5, 10);
    int result1 = fossil_greedy_coin_change(coins1, 13);
    ASSUME_ITS_EQUAL_I32(3, result1);  // Expected result: 3 coins (10 + 2 + 1)

    // Test case 2: Edge case (no coins required)
    fossil_tofu_t* coins2 = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 1);
    int result2 = fossil_greedy_coin_change(coins2, 0);
    ASSUME_ITS_EQUAL_I32(0, result2);  // Expected result: 0 coins

    // Test case 3: Edge case (large amount)
    fossil_tofu_t* coins3 = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 1);
    int result3 = fossil_greedy_coin_change(coins3, 1000);
    ASSUME_ITS_EQUAL_I32(1000, result3);  // Expected result: 1000 coins (each worth 1)

    // Cleanup
    fossil_tofu_erase_array(coins1);
    fossil_tofu_erase_array(coins2);
    fossil_tofu_erase_array(coins3);
}

FOSSIL_TEST(test_fossil_greedy_fractional_knapsack) {
    // Test case 1: Standard case
    fossil_tofu_t* weights1 = fossil_tofu_create_array(TOFU_DOUBLE_TYPE, 3, 10.0, 20.0, 30.0);
    fossil_tofu_t* values1 = fossil_tofu_create_array(TOFU_DOUBLE_TYPE, 3, 60.0, 100.0, 120.0);
    double result1 = fossil_greedy_fractional_knapsack(weights1, values1, 50);
    ASSUME_ITS_EQUAL_F64(240.0, result1, FOSSIL_TEST_DOUBLE_EPSILON); // Expected result: Maximum value of 240.0

    // Cleanup
    fossil_tofu_erase_array(weights1);
    fossil_tofu_erase_array(values1);
}

FOSSIL_TEST(test_fossil_greedy_interval_scheduling) {
    // Test case 1: Standard case
    fossil_tofu_t* startTimes1 = fossil_tofu_create_array(TOFU_INT_TYPE, 4, 1, 3, 0, 5);
    fossil_tofu_t* endTimes1 = fossil_tofu_create_array(TOFU_INT_TYPE, 4, 2, 4, 6, 7);
    int result1 = fossil_greedy_interval_scheduling(startTimes1, endTimes1);
    ASSUME_ITS_EQUAL_I32(3, result1);  // Expected result: Maximum number of non-overlapping tasks is 3

    // Cleanup
    fossil_tofu_erase_array(startTimes1);
    fossil_tofu_erase_array(endTimes1);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test seach algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_seach_fixture);
FOSSIL_SETUP(algo_seach_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_seach_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_fossil_search_linear_key_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 20 });

    // Perform search
    int result = fossil_search_linear(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(2, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_linear_key_not_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 35 });

    // Perform search
    int result = fossil_search_linear(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_linear_empty_array) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 10 });

    // Perform search
    int result = fossil_search_linear(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_binary_key_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 20 });

    // Perform search
    int result = fossil_search_binary(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(2, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_binary_key_not_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 35 });

    // Perform search
    int result = fossil_search_binary(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_binary_empty_array) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 10 });

    // Perform search
    int result = fossil_search_binary(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_interpolation_key_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 20 });

    // Perform search
    int result = fossil_search_interpolation(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(2, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_interpolation_key_not_found) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 10, 20, 30, 40, 50);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 35 });

    // Perform search
    int result = fossil_search_interpolation(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

FOSSIL_TEST(test_fossil_search_interpolation_empty_array) {
    // Define test data
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){ .int_type = 10 });

    // Perform search
    int result = fossil_search_interpolation(array, key);

    // Check result
    ASSUME_ITS_EQUAL_I32(-1, result);

    // Clean up
    fossil_tofu_erase_array(array);
    fossil_tofu_erase(key);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test sort algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_sort_fixture);
FOSSIL_SETUP(algo_sort_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_sort_fixture) {
    // Teardown code if needed
}

// Test cases for Bubble Sort
FOSSIL_TEST(test_sort_bubble_empty_array) {
    fossil_tofu_t* empty_array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_bubble(empty_array));
    fossil_tofu_erase(empty_array);
}

FOSSIL_TEST(test_sort_bubble_single_element) {
    fossil_tofu_t* single_array = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 42);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_bubble(single_array));
    ASSUME_ITS_EQUAL_I32(42, single_array->data.array_type.elements[0].data.int_type);
    fossil_tofu_erase(single_array);
}

FOSSIL_TEST(test_sort_bubble_multiple_elements) {
    int unsorted_values[] = {5, 3, 7, 2, 8, 1};
    int sorted_values[] = {1, 2, 3, 5, 7, 8};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_INT_TYPE, sizeof(unsorted_values) / sizeof(int), unsorted_values);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_bubble(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        ASSUME_ITS_EQUAL_I32(sorted_values[i], array_to_sort->data.array_type.elements[i].data.int_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// Test cases for Quick Sort
FOSSIL_TEST(test_sort_quick_empty_array) {
    fossil_tofu_t* empty_array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(empty_array));
    fossil_tofu_erase(empty_array);
}

FOSSIL_TEST(test_sort_quick_single_element) {
    fossil_tofu_t* single_array = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 42);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(single_array));
    ASSUME_ITS_EQUAL_I32(42, single_array->data.array_type.elements[0].data.int_type);
    fossil_tofu_erase(single_array);
}

FOSSIL_TEST(test_sort_quick_multiple_elements) {
    int unsorted_values[] = {5, 3, 7, 2, 8, 1};
    int sorted_values[] = {1, 2, 3, 5, 7, 8};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_INT_TYPE, sizeof(unsorted_values) / sizeof(int), unsorted_values);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        ASSUME_ITS_EQUAL_I32(sorted_values[i], array_to_sort->data.array_type.elements[i].data.int_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// Test cases for Merge Sort
FOSSIL_TEST(test_sort_merge_empty_array) {
    fossil_tofu_t* empty_array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_merge(empty_array));
    fossil_tofu_erase(empty_array);
}

FOSSIL_TEST(test_sort_merge_single_element) {
    fossil_tofu_t* single_array = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 42);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_merge(single_array));
    ASSUME_ITS_EQUAL_I32(42, single_array->data.array_type.elements[0].data.int_type);
    fossil_tofu_erase(single_array);
}

FOSSIL_TEST(test_sort_merge_multiple_elements) {
    int unsorted_values[] = {5, 3, 7, 2, 8, 1};
    int sorted_values[] = {1, 2, 3, 5, 7, 8};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_INT_TYPE, sizeof(unsorted_values) / sizeof(int), unsorted_values);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_merge(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        ASSUME_ITS_EQUAL_I32(sorted_values[i], array_to_sort->data.array_type.elements[i].data.int_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// Test cases for sorting strings
FOSSIL_TEST(test_sort_strings) {
    char* unsorted_strings[] = {"banana", "apple", "cherry", "date"};
    char* sorted_strings[] = {"apple", "banana", "cherry", "date"};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_STRING_TYPE, sizeof(unsorted_strings) / sizeof(char*), unsorted_strings);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        ASSUME_ITS_EQUAL_CSTR(sorted_strings[i], array_to_sort->data.array_type.elements[i].data.string_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test summary algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_summary_fixture);
FOSSIL_SETUP(algo_summary_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_summary_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_fossil_summary_sum) {
    fossil_tofu_error_t error;
    fossil_tofu_t array;
    fossil_tofu_t sum;

    // Case 1: Empty array
    array.type = TOFU_INT_TYPE;
    array.data.int_type = 0;
    error = fossil_summary_sum(&array, &sum);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(0, sum.data.int_type);

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
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(15, sum.data.int_type);
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
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(-15, sum.data.int_type);
    free(array.data.array_type.elements);
}

FOSSIL_TEST(test_fossil_summary_mean) {
    fossil_tofu_error_t error;
    fossil_tofu_t array;
    fossil_tofu_t mean;

    // Case 1: Empty array
    array.type = TOFU_INT_TYPE;
    array.data.int_type = 0;
    error = fossil_summary_mean(&array, &mean);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(0, mean.data.int_type);

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
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(3, mean.data.int_type);
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
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(-3, mean.data.int_type);
    free(array.data.array_type.elements);
}

FOSSIL_TEST(test_fossil_summary_median) {
    fossil_tofu_error_t error;
    fossil_tofu_t array;
    fossil_tofu_t median;

    // Case 1: Empty array
    array.type = TOFU_INT_TYPE;
    array.data.int_type = 0;
    error = fossil_summary_median(&array, &median);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS, error);

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
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(3, median.data.int_type);
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
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, error);
    ASSUME_ITS_EQUAL_I32(2, median.data.int_type);
    free(array.data.array_type.elements);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_algorithm_tests) {    
    // Dynamic Algorithm Fixture
    // ADD_TESTF(test_fossil_concat_arrays, algo_dynamic_fixture);
    // ADD_TESTF(test_fossil_reverse_array, algo_dynamic_fixture);

    // Greedy Algorithm Fixture
    // ADD_TESTF(test_fossil_greedy_coin_change, algo_greedy_fixture);
    // ADD_TESTF(test_fossil_greedy_fractional_knapsack, algo_greedy_fixture);
    // ADD_TESTF(test_fossil_greedy_interval_scheduling, algo_greedy_fixture);

    // Search Algorithm Fixture
    // ADD_TESTF(test_fossil_search_linear_key_found, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_linear_key_not_found, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_linear_empty_array, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_binary_key_found, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_binary_key_not_found, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_binary_empty_array, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_interpolation_key_found, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_interpolation_key_not_found, algo_seach_fixture);
    // ADD_TESTF(test_fossil_search_interpolation_empty_array, algo_seach_fixture);

    // // Sort Algorithm Fixture
    // ADD_TESTF(test_sort_bubble_empty_array, algo_sort_fixture);
    // ADD_TESTF(test_sort_bubble_single_element, algo_sort_fixture);
    // ADD_TESTF(test_sort_bubble_multiple_elements, algo_sort_fixture);
    // ADD_TESTF(test_sort_quick_empty_array, algo_sort_fixture);
    // ADD_TESTF(test_sort_quick_single_element, algo_sort_fixture);
    // ADD_TESTF(test_sort_quick_multiple_elements, algo_sort_fixture);
    // ADD_TESTF(test_sort_merge_empty_array, algo_sort_fixture);
    // ADD_TESTF(test_sort_merge_single_element, algo_sort_fixture);
    // ADD_TESTF(test_sort_merge_multiple_elements, algo_sort_fixture);
    // ADD_TESTF(test_sort_strings, algo_sort_fixture);

    // Summary Algorithm Fixture
    // ADD_TESTF(test_fossil_summary_sum, algo_summary_fixture);
    // ADD_TESTF(test_fossil_summary_mean, algo_summary_fixture);
    // ADD_TESTF(test_fossil_summary_median, algo_summary_fixture);
} // end of tests
