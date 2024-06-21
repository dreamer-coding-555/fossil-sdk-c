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
#include "fossil/algorithm/search.h"

int fossil_search_linear(fossil_tofu_arrayof_t array, fossil_tofu_t* key) {
    if (array.array == NULL || key == NULL || array.size == 0) {
        return -1; // Return -1 if array is empty or key is NULL
    }

    for (size_t i = 0; i < array.size; ++i) {
        if (fossil_tofu_equals(array.array[i], *key)) {
            return i; // Return the index if key is found
        }
    }

    return -1; // Return -1 if key is not found
}

int fossil_search_binary(fossil_tofu_arrayof_t array, fossil_tofu_t* key) {
    if (array.array == NULL || key == NULL || array.size == 0) {
        return -1; // Return -1 if array is empty or key is NULL
    }

    size_t low = 0;
    size_t high = array.size - 1;

    while (low <= high) {
        size_t mid = low + (high - low) / 2;

        if (fossil_tofu_equals(array.array[mid], *key)) {
            return mid; // Return the index if key is found
        } else if (fossil_tofu_equals(array.array[mid], *key) < 0) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Return -1 if key is not found
}

int fossil_search_interpolation(fossil_tofu_arrayof_t array, fossil_tofu_t* key) {
    if (array.array == NULL || key == NULL || array.size == 0) {
        return -1; // Return -1 if array is empty or key is NULL
    }

    size_t low = 0;
    size_t high = array.size - 1;

    while (low <= high && fossil_tofu_compare(&array.array[low], key) <= 0 && fossil_tofu_compare(&array.array[high], key) >= 0) {
        if (low == high) {
            if (fossil_tofu_equals(array.array[low], *key)) {
                return low; // Return the index if key is found
            }
            return -1; // Return -1 if key is not found
        }
    
        size_t pos = low + ((double)(high - low) / (fossil_tofu_compare(&array.array[high], &array.array[low]))) * (fossil_tofu_compare(key, &array.array[high]));

        if (fossil_tofu_equals(array.array[pos], *key)) {
            return pos; // Return the index if key is found
        } else if (fossil_tofu_compare(&array.array[pos], key) < 0) {
            low = pos + 1; // Search the right side
        } else {
            high = pos - 1; // Search the left side
        }
    }

    return -1; // Return -1 if key is not found
}
