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
#include "fossil/algorithms/sort.h"
#include "fossil/common/common.h"

// Bubble Sort Algorithm
fossil_tofu_error_t fossil_sort_bubble(fossil_tofu_t* array) {
    if (array == cnullptr || array->type != TOFU_ARRAY_TYPE || array->data.array_type.elements == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }
    
    size_t n = array->data.array_type.size;
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            fossil_tofu_t* current = &array->data.array_type.elements[j];
            fossil_tofu_t* next = &array->data.array_type.elements[j + 1];
            if (fossil_tofu_compare(current, next) == FOSSIL_TOFU_ERROR_OK) {
                fossil_tofu_swap(current, next);
            }
        }
    }
    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

// Quick Sort Algorithm - Partition Function
size_t fossil_quick_sort_partition(fossil_tofu_t* array, size_t low, size_t high) {
    fossil_tofu_t pivot = array->data.array_type.elements[high];
    size_t i = low - 1;

    for (size_t j = low; j < high; j++) {
        fossil_tofu_t* current = &array->data.array_type.elements[j];
        if (fossil_tofu_compare(current, &pivot) != FOSSIL_TOFU_ERROR_OK) {
            i++;
            fossil_tofu_swap(&array->data.array_type.elements[i], current);
        }
    }
    fossil_tofu_swap(&array->data.array_type.elements[i + 1], &array->data.array_type.elements[high]);
    return i + 1;
}

// Quick Sort Algorithm - Recursive Function
void fossil_quick_sort_recursive(fossil_tofu_t* array, size_t low, size_t high) {
    if (low < high) {
        size_t pi = fossil_quick_sort_partition(array, low, high);
        fossil_quick_sort_recursive(array, low, pi - 1);
        fossil_quick_sort_recursive(array, pi + 1, high);
    }
}

// Quick Sort Algorithm - Wrapper Function
fossil_tofu_error_t fossil_sort_quick(fossil_tofu_t* array) {
    if (array == cnullptr || array->type != TOFU_ARRAY_TYPE || array->data.array_type.elements == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }
    size_t n = array->data.array_type.size;
    fossil_quick_sort_recursive(array, 0, n - 1);
    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

// Merge Function for Merge Sort
void fossil_merge(fossil_tofu_t* array, size_t left, size_t mid, size_t right) {
    size_t i, j, k;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    // Create temporary arrays
    fossil_tofu_t L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = array->data.array_type.elements[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array->data.array_type.elements[mid + 1 + j];
    }

    // Merge the temporary arrays back into array[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (fossil_tofu_compare(&L[i], &R[j]) != FOSSIL_TOFU_ERROR_OK) {
            array->data.array_type.elements[k] = L[i];
            i++;
        } else {
            array->data.array_type.elements[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array->data.array_type.elements[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        array->data.array_type.elements[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort Algorithm - Recursive Function
void fossil_merge_sort_recursive(fossil_tofu_t* array, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        // Sort first and second halves
        fossil_merge_sort_recursive(array, left, mid);
        fossil_merge_sort_recursive(array, mid + 1, right);

        // Merge the sorted halves
        fossil_merge(array, left, mid, right);
    }
}

// Merge Sort Algorithm - Wrapper Function
fossil_tofu_error_t fossil_sort_merge(fossil_tofu_t* array) {
    if (array == cnullptr || array->type != TOFU_ARRAY_TYPE || array->data.array_type.elements == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }
    size_t n = array->data.array_type.size;
    fossil_merge_sort_recursive(array, 0, n - 1);
    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}
