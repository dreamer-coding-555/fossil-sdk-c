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
#include "fossil/algorithm/sort.h"
#include "fossil/generic/actionof.h"

// Sorts a "tofu" array using the Bubble Sort algorithm
int_least16_t fossil_sort_bubble(fossil_tofu_arrayof_t array) {
    if (array.array == NULL || array.size == 0) {
        return -1; // Error: Invalid array
    }

    for (size_t i = 0; i < array.size - 1; ++i) {
        for (size_t j = 0; j < array.size - i - 1; ++j) {
            if (fossil_tofu_actionof_compare(array.array[j], array.array[j + 1]) > 0) {
                fossil_tofu_actionof_swap(array.array, j, j + 1);
            }
        }
    }

    return 0; // Success
}

// Helper function for Quick Sort
static void fossil_sort_quick_recursive(fossil_tofu_t *array, int_least16_t left, int_least16_t right) {
    if (left < right) {
        fossil_tofu_t pivot = array[right];
        int_least16_t i = left - 1;

        for (int_least16_t j = left; j <= right - 1; ++j) {
            if (fossil_tofu_actionof_compare(array[j], pivot) < 0) {
                ++i;
                fossil_tofu_actionof_swap(array, i, j);
            }
        }
        fossil_tofu_actionof_swap(array, i + 1, right);

        int_least16_t pivot_index = i + 1;

        fossil_sort_quick_recursive(array, left, pivot_index - 1);
        fossil_sort_quick_recursive(array, pivot_index + 1, right);
    }
}

// Sorts a "tofu" array using the Quick Sort algorithm
int fossil_sort_quick(fossil_tofu_arrayof_t array) {
    if (array.array == NULL || array.size == 0) {
        return -1; // Error: Invalid array
    }

    fossil_sort_quick_recursive(array.array, 0, array.size - 1);

    return 0; // Success
}

// Helper function for Merge Sort
static void fossil_sort_merge_arrays(fossil_tofu_t *array, int_least16_t left, int_least16_t mid, int_least16_t right) {
    int_least16_t n1 = mid - left + 1;
    int_least16_t n2 = right - mid;

    fossil_tofu_t L[n1], R[n2];

    for (int_least16_t i = 0; i < n1; ++i) {
        L[i] = array[left + i];
    }
    for (int_least16_t j = 0; j < n2; ++j) {
        R[j] = array[mid + 1 + j];
    }

    int_least16_t i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (fossil_tofu_actionof_compare(L[i], R[j]) <= 0) {
            array[k] = L[i];
            ++i;
        } else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }
}

// Helper function for Merge Sort
static void fossil_sort_merge_recursive(fossil_tofu_t *array, int_least16_t left, int_least16_t right) {
    if (left < right) {
        int_least16_t mid = left + (right - left) / 2;
        fossil_sort_merge_recursive(array, left, mid);
        fossil_sort_merge_recursive(array, mid + 1, right);
        fossil_sort_merge_arrays(array, left, mid, right);
    }
}

// Sorts a "tofu" array using the Merge Sort algorithm
int fossil_sort_merge(fossil_tofu_arrayof_t array) {
    if (array.array == NULL || array.size == 0) {
        return -1; // Error: Invalid array
    }

    fossil_sort_merge_recursive(array.array, 0, array.size - 1);

    return 0; // Success
}
