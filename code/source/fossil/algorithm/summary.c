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
#include "fossil/common/common.h"
#include <stdlib.h>

fossil_tofu_error_t fossil_summary_sum(const fossil_tofu_t* array, fossil_tofu_t* sum) {
    if (array == cnullptr || sum == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_tofu_error_t error = FOSSIL_TOFU_ERROR_OK;
    fossil_tofu_t temp_sum = *array;

    for (size_t i = 1; i < array->data.array_type.size; i++) {
        error = fossil_tofu_accumulate(&temp_sum);
        if (error != FOSSIL_TOFU_ERROR_OK) {
            return error;
        }

        error = fossil_tofu_accumulate(&array->data.array_type.elements[i]);
        if (error != FOSSIL_TOFU_ERROR_OK) {
            return error;
        }

        error = fossil_tofu_accumulate(&temp_sum);
        if (error != FOSSIL_TOFU_ERROR_OK) {
            return error;
        }
    }

    sum->type = array->type;
    sum->data = fossil_tofu_value_getter(&temp_sum);

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_summary_mean(const fossil_tofu_t* array, fossil_tofu_t* mean) {
    if (array == cnullptr || mean == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_tofu_error_t error = fossil_summary_sum(array, mean);
    if (error != FOSSIL_TOFU_ERROR_OK) {
        return error;
    }

    mean->data.int_type /= array->data.array_type.size;

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

static int _compare(const void* a, const void* b) {
    const fossil_tofu_data* a_data = (const fossil_tofu_data*)a;
    const fossil_tofu_data* b_data = (const fossil_tofu_data*)b;

    if (a_data->int_type < b_data->int_type) {
        return -1;
    } else if (a_data->int_type > b_data->int_type) {
        return 1;
    } else {
        return 0;
    }
}

fossil_tofu_error_t fossil_summary_median(const fossil_tofu_t* array, fossil_tofu_t* median) {
    if (array == cnullptr || median == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (array->data.array_type.size == 0) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INVALID_OPERATION);
    }

    // Create a temporary array to hold sorted elements
    fossil_tofu_t* temp_array = (fossil_tofu_t*)malloc(array->data.array_type.size * sizeof(fossil_tofu_t));
    if (temp_array == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INVALID_OPERATION);
    }

    // Copy elements from the input array to the temporary array
    for (size_t i = 0; i < array->data.array_type.size; i++) {
        temp_array[i] = array->data.array_type.elements[i];
    }

    // Sort the temporary array
    qsort(temp_array, array->data.array_type.size, sizeof(fossil_tofu_t), _compare);

    // Calculate median based on array size
    size_t middle = array->data.array_type.size / 2;
    if (array->data.array_type.size % 2 == 0) {
        // If array size is even, median is the average of two middle elements
        fossil_tofu_t median_sum;
        fossil_tofu_value_setter(&temp_array[middle - 1], &median_sum);
        fossil_tofu_accumulate(&median_sum);
        fossil_tofu_value_setter(&temp_array[middle], &median_sum);
        fossil_tofu_accumulate(&median_sum);
        median->type = array->type;
        median->data = fossil_tofu_value_getter(&median_sum);
    } else {
        // If array size is odd, median is the middle element
        median->type = array->type;
        median->data = fossil_tofu_value_getter(&temp_array[middle]);
    }

    free(temp_array);
    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}
