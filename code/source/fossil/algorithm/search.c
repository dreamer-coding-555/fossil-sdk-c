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
#include "fossil/common/common.h"

int fossil_search_linear(fossil_tofu_t* array, fossil_tofu_t* key) {
    if (array == cnullptr || key == cnullptr) {
        return -1;
    }

    for (size_t i = 0; i < array->data.array_type.size; ++i) {
        if (fossil_tofu_compare(&array->data.array_type.elements[i], key) == FOSSIL_TOFU_ERROR_OK) {
            return (int)i; // Key found, return index
        }
    }

    return -1; // Key not found
}

static int binary_search_recursive(fossil_tofu_t* array, fossil_tofu_t* key, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp_result = fossil_tofu_compare(&array->data.array_type.elements[mid], key);
        if (cmp_result == FOSSIL_TOFU_ERROR_OK) {
            return mid; // Key found, return index
        } else if (cmp_result < 0) {
            return binary_search_recursive(array, key, mid + 1, right);
        } else {
            return binary_search_recursive(array, key, left, mid - 1);
        }
    }

    return -1; // Key not found
}

int fossil_search_binary(fossil_tofu_t* array, fossil_tofu_t* key) {
    if (array == cnullptr || key == cnullptr) {
        return -1;
    }

    return binary_search_recursive(array, key, 0, (int)array->data.array_type.size - 1);
}

int fossil_search_interpolation(fossil_tofu_t* array, fossil_tofu_t* key) {
    if (array == cnullptr || key == cnullptr) {
        return -1;
    }

    int left = 0;
    int right = (int)array->data.array_type.size - 1;

    while (left <= right && fossil_tofu_compare(&array->data.array_type.elements[left], key) <= 0 &&
           fossil_tofu_compare(&array->data.array_type.elements[right], key) >= 0) {
        if (left == right) {
            if (fossil_tofu_compare(&array->data.array_type.elements[left], key) == FOSSIL_TOFU_ERROR_OK) {
                return left;
            } else {
                return -1;
            }
        }

        int pos = left + (((double)(right - left) /
                          (fossil_tofu_compare(&array->data.array_type.elements[right], &array->data.array_type.elements[left]))) *
                          (fossil_tofu_compare(key, &array->data.array_type.elements[left])));

        int cmp_result = fossil_tofu_compare(&array->data.array_type.elements[pos], key);

        if (cmp_result == FOSSIL_TOFU_ERROR_OK) {
            return pos; // Key found, return index
        } else if (cmp_result < 0) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1; // Key not found
}
