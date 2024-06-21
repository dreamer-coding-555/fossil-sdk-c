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
#include "fossil/algorithm/summary.h"
#include "fossil/generic/actionof.h"
#include <stdlib.h>

int fossil_summary_sum(const fossil_tofu_arrayof_t array, fossil_tofu_arrayof_t sum) {
    // Check if input array is NULL or empty
    if (array.array == NULL || array.size == 0) {
        return -1;  // Error code for empty array
    }

    // Initialize sum to zero
    fossil_tofu_t total_sum = {.type = FOSSIL_TOFU_TYPE_INT, .value.int_val = 0};

    // Accumulate sum of elements in the array
    for (size_t i = 0; i < array.size; ++i) {
        total_sum.value.int_val += array.array[i].value.int_val;
    }

    // Copy the computed sum to the output parameter
    sum.array = &total_sum;
    sum.size = 1;
    sum.capacity = 1;

    return 0;  // Success
}

int fossil_summary_mean(const fossil_tofu_arrayof_t array, fossil_tofu_arrayof_t mean) {
    // Check if input array is NULL or empty
    if (array.array == NULL || array.size == 0) {
        return -1;  // Error code for empty array
    }

    // Calculate sum of elements
    fossil_tofu_arrayof_t sum;
    int result = fossil_summary_sum(array, sum);
    if (result != 0) {
        return result;  // Return error if sum calculation fails
    }

    // Calculate mean (average)
    fossil_tofu_t average = {.type = FOSSIL_TOFU_TYPE_DOUBLE};
    average.value.double_val = (double)sum.array[0].value.int_val / array.size;

    // Copy the computed mean to the output parameter
    mean.array = &average;
    mean.size = 1;
    mean.capacity = 1;

    return 0;  // Success
}

static int _compare_wrapper(const void *a, const void *b) {
    return fossil_tofu_actionof_compare(*(fossil_tofu_t*)a, *(fossil_tofu_t*)b);
}

int fossil_summary_median(const fossil_tofu_arrayof_t array, fossil_tofu_arrayof_t median) {
    // Check if input array is NULL or empty
    if (array.array == NULL || array.size == 0) {
        return -1;  // Error code for empty array
    }

    // Sort the array (you may use any sorting algorithm here)
    fossil_tofu_arrayof_t sorted_array = array;
    fossil_tofu_actionof_sort(sorted_array.array, sorted_array.size, _compare_wrapper);

    // Calculate median index
    size_t median_index = sorted_array.size / 2;

    // Copy the median element to the output parameter
    median.array = &sorted_array.array[median_index];
    median.size = 1;
    median.capacity = 1;

    return 0;  // Success
}
