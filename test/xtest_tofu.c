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
#include "fossil/xtofu.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
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

// Function to check if an element meets criteria for partitioning
bool even_partition_function(const fossil_tofu_t* element) {
    // Implement your logic here to determine if the element meets the partitioning criteria
    // For example, you could check if the element is even

    if (element == NULL) {
        // Handle NULL pointer
        return false;
    }

    // Example logic: Check if the value of the element is even
    if (element->type == TOFU_INT_TYPE && element->data.int_type % 2 == 0) {
        return true; // Element meets the criteria for partitioning
    }

    return false; // Element does not meet the criteria
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

XTEST(test_create_and_erase) {
    // Test creating and erasing "tofu" structures for each supported type

    // Integer types
    fossil_tofu_t* int_tofu = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 42});
    TEST_ASSUME_NOT_CNULLPTR(int_tofu);
    fossil_tofu_erase(int_tofu);

    fossil_tofu_t* int8_tofu = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 8});
    TEST_ASSUME_NOT_CNULLPTR(int8_tofu);
    fossil_tofu_erase(int8_tofu);

    fossil_tofu_t* int16_tofu = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 16});
    TEST_ASSUME_NOT_CNULLPTR(int16_tofu);
    fossil_tofu_erase(int16_tofu);

    fossil_tofu_t* int32_tofu = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 32});
    TEST_ASSUME_NOT_CNULLPTR(int32_tofu);
    fossil_tofu_erase(int32_tofu);

    fossil_tofu_t* int64_tofu = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 64});
    TEST_ASSUME_NOT_CNULLPTR(int64_tofu);
    fossil_tofu_erase(int64_tofu);

    // Unsigned integer types
    fossil_tofu_t* uint_tofu = fossil_tofu_create(TOFU_UINT_TYPE, &(fossil_tofu_data){.uint_type = 42});
    TEST_ASSUME_NOT_CNULLPTR(uint_tofu);
    fossil_tofu_erase(uint_tofu);

    fossil_tofu_t* uint8_tofu = fossil_tofu_create(TOFU_UINT_TYPE, &(fossil_tofu_data){.uint_type = 8});
    TEST_ASSUME_NOT_CNULLPTR(uint8_tofu);
    fossil_tofu_erase(uint8_tofu);

    fossil_tofu_t* uint16_tofu = fossil_tofu_create(TOFU_UINT_TYPE, &(fossil_tofu_data){.uint_type = 16});
    TEST_ASSUME_NOT_CNULLPTR(uint16_tofu);
    fossil_tofu_erase(uint16_tofu);

    fossil_tofu_t* uint32_tofu = fossil_tofu_create(TOFU_UINT_TYPE, &(fossil_tofu_data){.uint_type = 32});
    TEST_ASSUME_NOT_CNULLPTR(uint32_tofu);
    fossil_tofu_erase(uint32_tofu);

    fossil_tofu_t* uint64_tofu = fossil_tofu_create(TOFU_UINT_TYPE, &(fossil_tofu_data){.uint_type = 64});
    TEST_ASSUME_NOT_CNULLPTR(uint64_tofu);
    fossil_tofu_erase(uint64_tofu);

    // Octal types
    fossil_tofu_t* octal8_tofu = fossil_tofu_create(TOFU_OCTAL_TYPE, &(fossil_tofu_data){.octal_type = 075});
    TEST_ASSUME_NOT_CNULLPTR(octal8_tofu);
    fossil_tofu_erase(octal8_tofu);

    fossil_tofu_t* octal16_tofu = fossil_tofu_create(TOFU_OCTAL_TYPE, &(fossil_tofu_data){.octal_type = 017});
    TEST_ASSUME_NOT_CNULLPTR(octal16_tofu);
    fossil_tofu_erase(octal16_tofu);

    fossil_tofu_t* octal32_tofu = fossil_tofu_create(TOFU_OCTAL_TYPE, &(fossil_tofu_data){.octal_type = 033});
    TEST_ASSUME_NOT_CNULLPTR(octal32_tofu);
    fossil_tofu_erase(octal32_tofu);

    fossil_tofu_t* octal64_tofu = fossil_tofu_create(TOFU_OCTAL_TYPE, &(fossil_tofu_data){.octal_type = 070});
    TEST_ASSUME_NOT_CNULLPTR(octal64_tofu);
    fossil_tofu_erase(octal64_tofu);

    // Hexadecimal types
    fossil_tofu_t* hex8_tofu = fossil_tofu_create(TOFU_HEX_TYPE, &(fossil_tofu_data){.hex_type = 0xA});
    TEST_ASSUME_NOT_CNULLPTR(hex8_tofu);
    fossil_tofu_erase(hex8_tofu);

    fossil_tofu_t* hex16_tofu = fossil_tofu_create(TOFU_HEX_TYPE, &(fossil_tofu_data){.hex_type = 0xABCD});
    TEST_ASSUME_NOT_CNULLPTR(hex16_tofu);
    fossil_tofu_erase(hex16_tofu);

    fossil_tofu_t* hex32_tofu = fossil_tofu_create(TOFU_HEX_TYPE, &(fossil_tofu_data){.hex_type = 0x12345678});
    TEST_ASSUME_NOT_CNULLPTR(hex32_tofu);
    fossil_tofu_erase(hex32_tofu);

    fossil_tofu_t* hex64_tofu = fossil_tofu_create(TOFU_HEX_TYPE, &(fossil_tofu_data){.hex_type = 0x123456789ABCDEF0});
    TEST_ASSUME_NOT_CNULLPTR(hex64_tofu);
    fossil_tofu_erase(hex64_tofu);

    // Floating-point types
    fossil_tofu_t* float_tofu = fossil_tofu_create(TOFU_FLOAT_TYPE, &(fossil_tofu_data){.float_type = 3.14f});
    TEST_ASSUME_NOT_CNULLPTR(float_tofu);
    fossil_tofu_erase(float_tofu);

    fossil_tofu_t* double_tofu = fossil_tofu_create(TOFU_DOUBLE_TYPE, &(fossil_tofu_data){.double_type = 2.71828});
    TEST_ASSUME_NOT_CNULLPTR(double_tofu);
    fossil_tofu_erase(double_tofu);

    // Character type
    fossil_tofu_t* char_tofu = fossil_tofu_create(TOFU_CHAR_TYPE, &(fossil_tofu_data){.char_type = 'A'});
    TEST_ASSUME_NOT_CNULLPTR(char_tofu);
    fossil_tofu_erase(char_tofu);

    // Boolean type
    fossil_tofu_t* bool_tofu = fossil_tofu_create(TOFU_BOOLEAN_TYPE, &(fossil_tofu_data){.boolean_type = true});
    TEST_ASSUME_NOT_CNULLPTR(bool_tofu);
    fossil_tofu_erase(bool_tofu);

    // String type
    fossil_tofu_t* string_tofu = fossil_tofu_create(TOFU_STRING_TYPE, &(fossil_tofu_data){.string_type = "Hello"});
    TEST_ASSUME_NOT_CNULLPTR(string_tofu);
    fossil_tofu_erase(string_tofu);

    // Null pointer type
    fossil_tofu_t* nullptr_tofu = fossil_tofu_create(TOFU_NULLPTR_TYPE, &(fossil_tofu_data){.nullptr_type = NULL});
    TEST_ASSUME_NOT_CNULLPTR(nullptr_tofu);
    fossil_tofu_erase(nullptr_tofu);

    // Array type
    fossil_tofu_t* array_tofu = fossil_tofu_create_array(TOFU_ARRAY_TYPE, 3, int_tofu, char_tofu, bool_tofu);
    TEST_ASSUME_NOT_CNULLPTR(array_tofu);
    fossil_tofu_erase_array(array_tofu);

    // Map type
    fossil_tofu_t* map_tofu = fossil_tofu_create(TOFU_MAP_TYPE, &(fossil_tofu_data){.map_type = {
        .key = int_tofu,
        .value = bool_tofu,
        .size = 1
    }});
    TEST_ASSUME_NOT_CNULLPTR(map_tofu);
    fossil_tofu_erase(map_tofu);
}

XTEST(test_create_array_all_types) {
    // Test creating and erasing for each supported type

    // Integer array type
    fossil_tofu_t* int_array_tofu = fossil_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSUME_NOT_CNULLPTR(int_array_tofu);
    fossil_tofu_erase(int_array_tofu);

    // 8-bit Integer array type
    fossil_tofu_t* int8_array_tofu = fossil_tofu_create_array(TOFU_INT_TYPE, 3, 8, 16, 32);
    TEST_ASSUME_NOT_CNULLPTR(int8_array_tofu);
    fossil_tofu_erase(int8_array_tofu);

    // 16-bit Integer array type
    fossil_tofu_t* int16_array_tofu = fossil_tofu_create_array(TOFU_INT_TYPE, 3, 16, 32, 64);
    TEST_ASSUME_NOT_CNULLPTR(int16_array_tofu);
    fossil_tofu_erase(int16_array_tofu);

    // 32-bit Integer array type
    fossil_tofu_t* int32_array_tofu = fossil_tofu_create_array(TOFU_INT_TYPE, 3, 32, 64, 128);
    TEST_ASSUME_NOT_CNULLPTR(int32_array_tofu);
    fossil_tofu_erase(int32_array_tofu);

    // 64-bit Integer array type
    fossil_tofu_t* int64_array_tofu = fossil_tofu_create_array(TOFU_INT_TYPE, 3, 64, 128, 256);
    TEST_ASSUME_NOT_CNULLPTR(int64_array_tofu);
    fossil_tofu_erase(int64_array_tofu);

    // Unsigned Integer array type
    fossil_tofu_t* uint_array_tofu = fossil_tofu_create_array(TOFU_UINT_TYPE, 3, 42, 84, 168);
    TEST_ASSUME_NOT_CNULLPTR(uint_array_tofu);
    fossil_tofu_erase(uint_array_tofu);

    // 8-bit Unsigned Integer array type
    fossil_tofu_t* uint8_array_tofu = fossil_tofu_create_array(TOFU_UINT_TYPE, 3, 8, 16, 32);
    TEST_ASSUME_NOT_CNULLPTR(uint8_array_tofu);
    fossil_tofu_erase(uint8_array_tofu);

    // 16-bit Unsigned Integer array type
    fossil_tofu_t* uint16_array_tofu = fossil_tofu_create_array(TOFU_UINT_TYPE, 3, 16, 32, 64);
    TEST_ASSUME_NOT_CNULLPTR(uint16_array_tofu);
    fossil_tofu_erase(uint16_array_tofu);

    // 32-bit Unsigned Integer array type
    fossil_tofu_t* uint32_array_tofu = fossil_tofu_create_array(TOFU_UINT_TYPE, 3, 32, 64, 128);
    TEST_ASSUME_NOT_CNULLPTR(uint32_array_tofu);
    fossil_tofu_erase(uint32_array_tofu);

    // 64-bit Unsigned Integer array type
    fossil_tofu_t* uint64_array_tofu = fossil_tofu_create_array(TOFU_UINT_TYPE, 3, 64, 128, 256);
    TEST_ASSUME_NOT_CNULLPTR(uint64_array_tofu);
    fossil_tofu_erase(uint64_array_tofu);

    // Octal 8-bit array type
    fossil_tofu_t* octal8_array_tofu = fossil_tofu_create_array(TOFU_OCTAL_TYPE, 3, 075, 064, 055);
    TEST_ASSUME_NOT_CNULLPTR(octal8_array_tofu);
    fossil_tofu_erase(octal8_array_tofu);

    // Octal 16-bit array type
    fossil_tofu_t* octal16_array_tofu = fossil_tofu_create_array(TOFU_OCTAL_TYPE, 3, 0755, 0755, 0755);
    TEST_ASSUME_NOT_CNULLPTR(octal16_array_tofu);
    fossil_tofu_erase(octal16_array_tofu);

    // Octal 32-bit array type
    fossil_tofu_t* octal32_array_tofu = fossil_tofu_create_array(TOFU_OCTAL_TYPE, 3, 0755, 0755, 0755);
    TEST_ASSUME_NOT_CNULLPTR(octal32_array_tofu);
    fossil_tofu_erase(octal32_array_tofu);

    // Octal 64-bit array type
    fossil_tofu_t* octal64_array_tofu = fossil_tofu_create_array(TOFU_OCTAL_TYPE, 3, 0755, 0755, 0755);
    TEST_ASSUME_NOT_CNULLPTR(octal64_array_tofu);
    fossil_tofu_erase(octal64_array_tofu);

    // Hexadecimal 8-bit array type
    fossil_tofu_t* hex8_array_tofu = fossil_tofu_create_array(TOFU_HEX_TYPE, 3, 0x1F, 0x2A, 0x3C);
    TEST_ASSUME_NOT_CNULLPTR(hex8_array_tofu);
    fossil_tofu_erase(hex8_array_tofu);

    // Hexadecimal 16-bit array type
    fossil_tofu_t* hex16_array_tofu = fossil_tofu_create_array(TOFU_HEX_TYPE, 3, 0x1F2A, 0x2A3C, 0x3C1F);
    TEST_ASSUME_NOT_CNULLPTR(hex16_array_tofu);
    fossil_tofu_erase(hex16_array_tofu);

    // Hexadecimal 32-bit array type
    fossil_tofu_t* hex32_array_tofu = fossil_tofu_create_array(TOFU_HEX_TYPE, 3, 0x1F2A3C4D, 0x2A3C4D5E, 0x3C4D5E6F);
    TEST_ASSUME_NOT_CNULLPTR(hex32_array_tofu);
    fossil_tofu_erase(hex32_array_tofu);

    // Hexadecimal 64-bit array type
    fossil_tofu_t* hex64_array_tofu = fossil_tofu_create_array(TOFU_HEX_TYPE, 3, 0x1F2A3C4D5E6F7A8B, 0x2A3C4D5E6F7A8B9C, 0x3C4D5E6F7A8B9C0D);
    TEST_ASSUME_NOT_CNULLPTR(hex64_array_tofu);
    fossil_tofu_erase(hex64_array_tofu);

    // Floating-point array type (double)
    fossil_tofu_t* double_array_tofu = fossil_tofu_create_array(TOFU_DOUBLE_TYPE, 3, 3.14, 2.71, 1.618);
    TEST_ASSUME_NOT_CNULLPTR(double_array_tofu);
    fossil_tofu_erase(double_array_tofu);

    // Floating-point array type (float)
    fossil_tofu_t* float_array_tofu = fossil_tofu_create_array(TOFU_FLOAT_TYPE, 3, 3.14f, 2.71f, 1.618f);
    TEST_ASSUME_NOT_CNULLPTR(float_array_tofu);
    fossil_tofu_erase(float_array_tofu);

    // String array type
    fossil_tofu_t* string_array_tofu = fossil_tofu_create_array(TOFU_STRING_TYPE, 3, "apple", "banana", "cherry");
    TEST_ASSUME_NOT_CNULLPTR(string_array_tofu);
    fossil_tofu_erase(string_array_tofu);

    // Character array type
    fossil_tofu_t* char_array_tofu = fossil_tofu_create_array(TOFU_CHAR_TYPE, 3, 'A', 'B', 'C');
    TEST_ASSUME_NOT_CNULLPTR(char_array_tofu);
    fossil_tofu_erase(char_array_tofu);

    // Boolean array type
    fossil_tofu_t* boolean_array_tofu = fossil_tofu_create_array(TOFU_BOOLEAN_TYPE, 3, true, false, true);
    TEST_ASSUME_NOT_CNULLPTR(boolean_array_tofu);
    fossil_tofu_erase(boolean_array_tofu);

    // Null pointer array type
    fossil_tofu_t* nullptr_array_tofu = fossil_tofu_create_array(TOFU_NULLPTR_TYPE, 3, NULL, NULL, NULL);
    TEST_ASSUME_NOT_CNULLPTR(nullptr_array_tofu);
    fossil_tofu_erase(nullptr_array_tofu);

    // Invalid array type (Unknown type)
    fossil_tofu_t* invalid_array_tofu = fossil_tofu_create_array(TOFU_INVALID_TYPE, 3, NULL, NULL, NULL);
    TEST_ASSUME_CNULLPTR(invalid_array_tofu);

    // Unknown array type
    fossil_tofu_t* unknown_array_tofu = fossil_tofu_create_array(TOFU_UNKNOWN_TYPE, 3, NULL, NULL, NULL);
    TEST_ASSUME_CNULLPTR(unknown_array_tofu);

    // Fixed point array type
    fossil_tofu_t* fixed_array_tofu = fossil_tofu_create_array(TOFU_FIXED_TYPE, 3, 3.14, 2.71, 1.618);
    TEST_ASSUME_NOT_CNULLPTR(fixed_array_tofu);
}

XTEST(test_type_mismatch) {
    // Create a "tofu" structure with one type
    fossil_tofu_t* tofu = fossil_tofu_create(TOFU_INT_TYPE, NULL);
    TEST_ASSUME_NOT_CNULLPTR(tofu);

    // Try to apply an operation with a different type
    fossil_tofu_t* wrong_type = fossil_tofu_create(TOFU_FLOAT_TYPE, NULL);
    fossil_tofu_error_t result = fossil_tofu_compare(tofu, wrong_type);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_INVALID_OPERATION, result);

    // Clean up
    fossil_tofu_erase(tofu);
    fossil_tofu_erase(wrong_type);
}

XTEST(test_accumulate) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test accumulate
    fossil_tofu_error_t accumulate_result = fossil_tofu_accumulate(array);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, accumulate_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_transform) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test transform
    fossil_tofu_error_t transform_result = fossil_tofu_transform(array, square_transform_function);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, transform_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_sort) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test sort
    fossil_tofu_error_t sort_result = fossil_tofu_sort(array);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, sort_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_search) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test search
    fossil_tofu_t* key = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 8});
    fossil_tofu_error_t search_result = fossil_tofu_search(array, key);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, search_result);
    fossil_tofu_erase(key);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_filter) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test filter
    fossil_tofu_error_t filter_result = fossil_tofu_filter(array, even_filter_function);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, filter_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_reverse) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test reverse
    fossil_tofu_error_t reverse_result = fossil_tofu_reverse(array);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, reverse_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_swap) {
    // Create two "tofu" structures with initial values
    fossil_tofu_t* tofu1 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 5});
    fossil_tofu_t* tofu2 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 8});

    // Test swap
    fossil_tofu_error_t swap_result = fossil_tofu_swap(tofu1, tofu2);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, swap_result);

    // Clean up
    fossil_tofu_erase(tofu1);
    fossil_tofu_erase(tofu2);
}

XTEST(test_compare) {
    // Create two "tofu" structures with initial values
    fossil_tofu_t* tofu1 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 5});
    fossil_tofu_t* tofu2 = fossil_tofu_create(TOFU_INT_TYPE, &(fossil_tofu_data){.int_type = 8});

    // Test compare
    fossil_tofu_error_t compare_result = fossil_tofu_compare(tofu1, tofu2);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, compare_result);

    // Clean up
    fossil_tofu_erase(tofu1);
    fossil_tofu_erase(tofu2);
}

XTEST(test_reduce) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test reduce
    fossil_tofu_error_t reduce_result = fossil_tofu_reduce(array, sum_reduce_function);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, reduce_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_shuffle) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test shuffle
    fossil_tofu_error_t shuffle_result = fossil_tofu_shuffle(array);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, shuffle_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_for_each) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test for_each
    fossil_tofu_error_t for_each_result = fossil_tofu_for_each(array, out_element_function);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, for_each_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

XTEST(test_partition) {
    // Create a "tofu" array with initial values
    fossil_tofu_t* array = fossil_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test partition
    fossil_tofu_t* partitionedResults[2];
    fossil_tofu_error_t partition_result = fossil_tofu_partition(array, even_partition_function, partitionedResults);
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, partition_result);

    // Clean up
    fossil_tofu_erase_array(array);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(tofu_type_group) {
    XTEST_RUN_UNIT(test_create_and_erase);
    XTEST_RUN_UNIT(test_create_array_all_types);
    XTEST_RUN_UNIT(test_type_mismatch);
    XTEST_RUN_UNIT(test_accumulate);
    XTEST_RUN_UNIT(test_transform);
    XTEST_RUN_UNIT(test_sort);
    XTEST_RUN_UNIT(test_search);
    XTEST_RUN_UNIT(test_filter);
    XTEST_RUN_UNIT(test_reverse);
    XTEST_RUN_UNIT(test_swap);
    XTEST_RUN_UNIT(test_compare);
    XTEST_RUN_UNIT(test_reduce);
    XTEST_RUN_UNIT(test_shuffle);
    XTEST_RUN_UNIT(test_for_each);
    XTEST_RUN_UNIT(test_partition);

} // end of xdata_test_tofu_group
