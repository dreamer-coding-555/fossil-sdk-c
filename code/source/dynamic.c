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
#include "fossil/xalgorithms/dynamic.h"
#include "fossil/xalgorithms/common.h"

fossil_tofu_t* fossil_dynamic_concat_arrays(fossil_tofu_t* array1, fossil_tofu_t* array2) {
    // Check if either array is NULL
    if (!array1 || !array2) {
        return cnullptr;
    }

    // Check if both arrays are of the same type
    if (fossil_tofu_type_getter(array1) != fossil_tofu_type_getter(array2)) {
        return cnullptr;
    }

    // Create a new dynamic array to store the concatenated result
    size_t size1 = fossil_tofu_value_getter(array1).array_type.size;
    size_t size2 = fossil_tofu_value_getter(array2).array_type.size;
    fossil_tofu_t* concatenated = fossil_tofu_create_array(fossil_tofu_type_getter(array1), size1 + size2);
    if (!concatenated) {
        return cnullptr;
    }

    // Copy elements from the first array
    for (size_t i = 0; i < size1; ++i) {
        fossil_tofu_t* element = fossil_tofu_iterator_start(array1, size1).current_key + i;
        fossil_tofu_value_setter(element, concatenated + i);
    }

    // Copy elements from the second array
    for (size_t i = 0; i < size2; ++i) {
        fossil_tofu_t* element = fossil_tofu_iterator_start(array2, size2).current_key + i;
        fossil_tofu_value_setter(element, concatenated + size1 + i);
    }

    return concatenated;
}

fossil_tofu_t* fossil_dynamic_reverse_array(fossil_tofu_t* array) {
    // Check if the array is NULL
    if (!array) {
        return cnullptr;
    }

    // Get the size of the array
    size_t size = fossil_tofu_value_getter(array).array_type.size;

    // Create a new dynamic array to store the reversed result
    fossil_tofu_t* reversed = fossil_tofu_create_array(fossil_tofu_type_getter(array), size);
    if (!reversed) {
        return cnullptr;
    }

    // Copy elements from the original array in reverse order
    for (size_t i = 0; i < size; ++i) {
        fossil_tofu_t* element = fossil_tofu_iterator_start(array, size).current_key + (size - i - 1);
        fossil_tofu_value_setter(element, reversed + i);
    }

    return reversed;
}
