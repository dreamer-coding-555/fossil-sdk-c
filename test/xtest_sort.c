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
#include <fossil/xalgorithms/sort.h> // library under test

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

// Test cases for Bubble Sort
XTEST(test_sort_bubble_empty_array) {
    fossil_tofu_t* empty_array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_bubble(empty_array));
    fossil_tofu_erase(empty_array);
}

XTEST(test_sort_bubble_single_element) {
    fossil_tofu_t* single_array = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 42);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_bubble(single_array));
    TEST_ASSUME_EQUAL_INT(42, single_array->data.array_type.elements[0].data.int_type);
    fossil_tofu_erase(single_array);
}

XTEST(test_sort_bubble_multiple_elements) {
    int unsorted_values[] = {5, 3, 7, 2, 8, 1};
    int sorted_values[] = {1, 2, 3, 5, 7, 8};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_INT_TYPE, sizeof(unsorted_values) / sizeof(int), unsorted_values);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_bubble(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        TEST_ASSUME_EQUAL_INT(sorted_values[i], array_to_sort->data.array_type.elements[i].data.int_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// Test cases for Quick Sort
XTEST(test_sort_quick_empty_array) {
    fossil_tofu_t* empty_array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(empty_array));
    fossil_tofu_erase(empty_array);
}

XTEST(test_sort_quick_single_element) {
    fossil_tofu_t* single_array = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 42);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(single_array));
    TEST_ASSUME_EQUAL_INT(42, single_array->data.array_type.elements[0].data.int_type);
    fossil_tofu_erase(single_array);
}

XTEST(test_sort_quick_multiple_elements) {
    int unsorted_values[] = {5, 3, 7, 2, 8, 1};
    int sorted_values[] = {1, 2, 3, 5, 7, 8};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_INT_TYPE, sizeof(unsorted_values) / sizeof(int), unsorted_values);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        TEST_ASSUME_EQUAL_INT(sorted_values[i], array_to_sort->data.array_type.elements[i].data.int_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// Test cases for Merge Sort
XTEST(test_sort_merge_empty_array) {
    fossil_tofu_t* empty_array = fossil_tofu_create_array(TOFU_INT_TYPE, 0);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_merge(empty_array));
    fossil_tofu_erase(empty_array);
}

XTEST(test_sort_merge_single_element) {
    fossil_tofu_t* single_array = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 42);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_merge(single_array));
    TEST_ASSUME_EQUAL_INT(42, single_array->data.array_type.elements[0].data.int_type);
    fossil_tofu_erase(single_array);
}

XTEST(test_sort_merge_multiple_elements) {
    int unsorted_values[] = {5, 3, 7, 2, 8, 1};
    int sorted_values[] = {1, 2, 3, 5, 7, 8};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_INT_TYPE, sizeof(unsorted_values) / sizeof(int), unsorted_values);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_merge(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        TEST_ASSUME_EQUAL_INT(sorted_values[i], array_to_sort->data.array_type.elements[i].data.int_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// Test cases for sorting strings
XTEST(test_sort_strings) {
    char* unsorted_strings[] = {"banana", "apple", "cherry", "date"};
    char* sorted_strings[] = {"apple", "banana", "cherry", "date"};
    fossil_tofu_t* array_to_sort = fossil_tofu_create_array(TOFU_STRING_TYPE, sizeof(unsorted_strings) / sizeof(char*), unsorted_strings);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_sort_quick(array_to_sort));
    for (size_t i = 0; i < array_to_sort->data.array_type.size; i++) {
        TEST_ASSUME_EQUAL_CSTRING(sorted_strings[i], array_to_sort->data.array_type.elements[i].data.string_type);
    }
    fossil_tofu_erase(array_to_sort);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(sort_group) {
    // Run test cases for Bubble Sort
    XTEST_RUN_UNIT(test_sort_bubble_empty_array);
    XTEST_RUN_UNIT(test_sort_bubble_single_element);
    XTEST_RUN_UNIT(test_sort_bubble_multiple_elements);

    // Run test cases for Quick Sort
    XTEST_RUN_UNIT(test_sort_quick_empty_array);
    XTEST_RUN_UNIT(test_sort_quick_single_element);
    XTEST_RUN_UNIT(test_sort_quick_multiple_elements);

    // Run test cases for Merge Sort
    XTEST_RUN_UNIT(test_sort_merge_empty_array);
    XTEST_RUN_UNIT(test_sort_merge_single_element);
    XTEST_RUN_UNIT(test_sort_merge_multiple_elements);

    // Run test case for sorting strings
    XTEST_RUN_UNIT(test_sort_strings);
} // end of fixture
