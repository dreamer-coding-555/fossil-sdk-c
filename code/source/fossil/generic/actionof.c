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
#include "fossil/generic/actionof.h"
#include <time.h>

// Function to transform elements in an array
void fossil_tofu_actionof_transform(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t)) {
    for (size_t i = 0; i < size; i++) {
        array[i] = func(array[i]);
    }
}

// Function to accumulate elements in an array
fossil_tofu_t fossil_tofu_actionof_accumulate(fossil_tofu_t *array, size_t size, fossil_tofu_t init, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    fossil_tofu_t result = init;
    for (size_t i = 0; i < size; i++) {
        result = func(result, array[i]);
    }
    return result;
}

// Function to filter elements in an array
size_t fossil_tofu_actionof_filter(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(array[i])) {
            array[j++] = array[i];
        }
    }
    return j;
}

// Original comparison function signature
int compare_fossil_tofu(fossil_tofu_t a, fossil_tofu_t b) {
    fossil_tofu_compare(&a, &b);
}

// Wrapper function to match qsort's required signature
int compare_fossil_tofu_wrapper(const void *a, const void *b) {
    fossil_tofu_t *arg1 = (fossil_tofu_t *)a;
    fossil_tofu_t *arg2 = (fossil_tofu_t *)b;
    return compare_fossil_tofu(*arg1, *arg2);
}

// Function to sort elements in an array
void fossil_tofu_actionof_sort(fossil_tofu_t *array, size_t size, int (*compare)(fossil_tofu_t, fossil_tofu_t)) {
    qsort(array, size, sizeof(fossil_tofu_t), compare_fossil_tofu_wrapper);
}

// Function to search for an element in an array
fossil_tofu_t* fossil_tofu_actionof_search(fossil_tofu_t *array, size_t size, fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t)) {
    for (size_t i = 0; i < size; i++) {
        if (compare(array[i], key)) {
            return &array[i];
        }
    }
    return NULL;
}

// Function to reverse elements in an array
void fossil_tofu_actionof_reverse(fossil_tofu_t *array, size_t size) {
    for (size_t i = 0, j = size - 1; i < j; i++, j--) {
        fossil_tofu_actionof_swap(array, i, j);
    }
}

// Function to swap two elements in an array
void fossil_tofu_actionof_swap(fossil_tofu_t *array, size_t index1, size_t index2) {
    fossil_tofu_t temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

// Function to compare two elements
int fossil_tofu_actionof_compare(fossil_tofu_t a, fossil_tofu_t b) {
    // Simplified example, more comprehensive comparison logic needed for all types
    if (a.type != b.type) return a.type - b.type;
    switch (a.type) {
        case FOSSIL_TOFU_TYPE_INT:
            return a.value.int_val - b.value.int_val;
        case FOSSIL_TOFU_TYPE_UINT:
            return a.value.uint_val - b.value.uint_val;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            return (a.value.double_val > b.value.double_val) - (a.value.double_val < b.value.double_val);
        case FOSSIL_TOFU_TYPE_FLOAT:
            return (a.value.float_val > b.value.float_val) - (a.value.float_val < b.value.float_val);
        default:
            return 0;
    }
}

// Function to reduce elements in an array
fossil_tofu_t fossil_tofu_actionof_reduce(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    if (size == 0) return fossil_tofu_create("ghost", "");
    fossil_tofu_t result = array[0];
    for (size_t i = 1; i < size; i++) {
        result = func(result, array[i]);
    }
    return result;
}

// Function to shuffle elements in an array
void fossil_tofu_actionof_shuffle(fossil_tofu_t *array, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
        fossil_tofu_actionof_swap(array, i, j);
    }
}

// Function to apply a function to each element in an array
void fossil_tofu_actionof_for_each(fossil_tofu_t *array, size_t size, void (*func)(fossil_tofu_t)) {
    for (size_t i = 0; i < size; i++) {
        func(array[i]);
    }
}

// Function to partition elements in an array
size_t fossil_tofu_actionof_partition(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(array[i])) {
            fossil_tofu_actionof_swap(array, i, j++);
        }
    }
    return j;
}

// Function to calculate the summary of elements in an array
fossil_tofu_t fossil_tofu_actionof_summary(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    return fossil_tofu_actionof_reduce(array, size, func);
}

// Helper function for calculating the average
fossil_tofu_t fossil_tofu_actionof_average_helper(fossil_tofu_t a, fossil_tofu_t b) {
    a.value.double_val += b.value.double_val;
    return a;
}

// Function to calculate the average of elements in an array
fossil_tofu_t fossil_tofu_actionof_average(fossil_tofu_t *array, size_t size) {
    if (size == 0) return fossil_tofu_create("ghost", "ghost");
    fossil_tofu_t sum = fossil_tofu_actionof_reduce(array, size, fossil_tofu_actionof_average_helper);
    sum.value.double_val /= size;
    return sum;
}
