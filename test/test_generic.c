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
#include <fossil/generic/tofu.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Helper functions for algorithms
int square_transform_function(int value) {
    return value * value;
}

bool even_filter_function(const fossil_tofu_data* element) {
    return (element->int_type % 2) == 0;
}

// Function to calculate the sum of elements in an array
fossil_tofu_t sum_reduce_function(const fossil_tofu_t* element, const fossil_tofu_t* accumulator) {
    // Ensure both elements are integers
    if (element->type != TOFU_INT_TYPE || accumulator->type != TOFU_INT_TYPE) {
        fossil_tofu_t error_result;
        error_result.type = TOFU_UNKNOWN_TYPE;
        return error_result;
    }

    // Calculate the sum
    int sum = accumulator->data.int_type + element->data.int_type;

    // Create a fossil_tofu_t with the sum and return it
    fossil_tofu_t result;
    result.type = TOFU_INT_TYPE;
    result.data.int_type = sum;
    return result;
}

// // Function to check if an element meets criteria for partitioning
// bool even_partition_function(const fossil_tofu_t* element) {
//     // Implement your logic here to determine if the element meets the partitioning criteria
//     // For example, you could check if the element is even

//     if (element == NULL) {
//         // Handle NULL pointer
//         return false;
//     }

//     // Example logic: Check if the value of the element is even
//     if (element->type == TOFU_INT_TYPE && element->data.int_type % 2 == 0) {
//         return true; // Element meets the criteria for partitioning
//     }

//     return false; // Element does not meet the criteria
// }

// Function to check if an element meets criteria for partitioning
bool even_partition_function(const fossil_tofu_t* element) {
    if (element == NULL || element->type != TOFU_INT_TYPE) {
        return false;
    }

    return (element->data.int_type % 2 == 0);
}

// Function to print each element of an array
void out_element_function(fossil_tofu_t* element) {
    // Ensure the element is an integer
    if (element->type != TOFU_INT_TYPE) {
        return;
    }

    // Print the element
    printf("%lld ", (long long)element->data.int_type);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test classic string
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_tofu_fixture);
FOSSIL_SETUP(c_tofu_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_tofu_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_type_mismatch) {
    // Create a "tofu" structure with an integer type
    fossil_tofu_t* tofu = fossil_tofu_create(TOFU_INT_TYPE, NULL);
    ASSUME_NOT_CNULL(tofu);

    // Create a "tofu" structure with a float type
    fossil_tofu_t* wrong_type = fossil_tofu_create(TOFU_FLOAT_TYPE, NULL);
    ASSUME_NOT_CNULL(wrong_type);

    // Try to compare the two different types
    fossil_tofu_error_t result = fossil_tofu_compare(tofu, wrong_type);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_INVALID_OPERATION, result);

    // Clean up
    fossil_tofu_erase(tofu);
    fossil_tofu_erase(wrong_type);
}

FOSSIL_TEST(test_accumulate) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test accumulation operation
    fossil_tofu_error_t accumulate_result = fossil_tofu_accumulate(array);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, accumulate_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_transform) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test transform operation (e.g., squaring each element)
    fossil_tofu_error_t transform_result = fossil_tofu_transform(array, square_transform_function);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, transform_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_sort) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test sorting operation
    fossil_tofu_error_t sort_result = fossil_tofu_sort(array);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, sort_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_search) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Create a key to search for
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 8});
    ASSUME_NOT_CNULL(key);

    // Test search operation
    fossil_tofu_error_t search_result = fossil_tofu_search(array, key);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, search_result);

    // Clean up
    fossil_tofu_erase(key);
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_filter) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test filter operation (e.g., keeping even elements)
    fossil_tofu_error_t filter_result = fossil_tofu_filter(array, even_filter_function);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, filter_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_reverse) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test reverse operation
    fossil_tofu_error_t reverse_result = fossil_tofu_reverse(array);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, reverse_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_swap) {
    // Create two "tofu" structures with initial values
    fossil_tofu_t* tofu1 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 5});
    ASSUME_NOT_CNULL(tofu1);
    fossil_tofu_t* tofu2 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 8});
    ASSUME_NOT_CNULL(tofu2);

    // Test swap operation
    fossil_tofu_error_t swap_result = fossil_tofu_swap(tofu1, tofu2);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, swap_result);

    // Clean up
    fossil_tofu_erase(tofu1);
    fossil_tofu_erase(tofu2);
}

FOSSIL_TEST(test_compare) {
    // Create two "tofu" structures with initial values
    fossil_tofu_t* tofu1 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 5});
    ASSUME_NOT_CNULL(tofu1);
    fossil_tofu_t* tofu2 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 8});
    ASSUME_NOT_CNULL(tofu2);

    // Test compare operation
    fossil_tofu_error_t compare_result = fossil_tofu_compare(tofu1, tofu2);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_INVALID_OPERATION, compare_result);

    // Clean up
    fossil_tofu_erase(tofu1);
    fossil_tofu_erase(tofu2);
}

FOSSIL_TEST(test_reduce) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test reduce operation (e.g., summing the elements)
    fossil_tofu_error_t reduce_result = fossil_tofu_reduce(array, sum_reduce_function);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, reduce_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_shuffle) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test shuffle operation
    fossil_tofu_error_t shuffle_result = fossil_tofu_shuffle(array);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, shuffle_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_for_each) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test for_each operation (e.g., printing each element)
    fossil_tofu_error_t for_each_result = fossil_tofu_for_each(array, out_element_function);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, for_each_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

FOSSIL_TEST(test_partition) {
    // Create a "tofu" array with initial integer values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);
    ASSUME_NOT_CNULL(array);

    // Test partition operation (e.g., partitioning even and odd elements)
    fossil_tofu_t* partitionedResults[2] = {NULL, NULL};
    fossil_tofu_error_t partition_result = fossil_tofu_partition(array, even_partition_function, partitionedResults);

    // Check partition results and validate
    if (partition_result == FOSSIL_TOFU_ERROR_OK) {
        if (partitionedResults[0] != NULL) {
            // Validate partitioned results (even numbers)
            for (size_t i = 0; i < partitionedResults[0]->data.array_type.size; ++i) {
                ASSUME_ITS_TRUE(partitionedResults[0]->data.array_type.elements[i].data.int_type % 2 == 0);
            }
            fossil_tofu_erase(partitionedResults[0]);
        }
        if (partitionedResults[1] != NULL) {
            // Validate partitioned results (odd numbers)
            for (size_t i = 0; i < partitionedResults[1]->data.array_type.size; ++i) {
                ASSUME_ITS_TRUE(partitionedResults[1]->data.array_type.elements[i].data.int_type % 2 != 0);
            }
            fossil_tofu_erase(partitionedResults[1]);
        }
    }

    // Clean up
    fossil_tofu_erase_array(array);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_generic_tests) {    
    // Generic ToFu Fixture
    ADD_TESTF(test_accumulate, c_tofu_fixture);
    ADD_TESTF(test_transform, c_tofu_fixture);
    ADD_TESTF(test_sort, c_tofu_fixture);
    ADD_TESTF(test_search, c_tofu_fixture);
    ADD_TESTF(test_filter, c_tofu_fixture);
    ADD_TESTF(test_reverse, c_tofu_fixture);
    ADD_TESTF(test_swap, c_tofu_fixture);
    ADD_TESTF(test_compare, c_tofu_fixture);
    ADD_TESTF(test_reduce, c_tofu_fixture);
    ADD_TESTF(test_shuffle, c_tofu_fixture);
    ADD_TESTF(test_for_each, c_tofu_fixture);
    ADD_TESTF(test_partition, c_tofu_fixture);
} // end of tests
