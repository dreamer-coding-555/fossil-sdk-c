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
#include "fossil/algorithm/dynamic.h"
#include "fossil/common/common.h"

fossil_tofu_arrayof_t fossil_dynamic_concat_arrays(fossil_tofu_arrayof_t array1, fossil_tofu_arrayof_t array2) {
    if (!array1.array || !array2.array) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    size_t new_size = array1.size + array2.size;
    fossil_tofu_t *new_array = (fossil_tofu_t *)malloc(new_size * sizeof(fossil_tofu_t));
    if (!new_array) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    size_t index = 0;
    for (size_t i = 0; i < array1.size; ++i) {
        new_array[index++] = array1.array[i];
    }
    for (size_t i = 0; i < array2.size; ++i) {
        new_array[index++] = array2.array[i];
    }

    return (fossil_tofu_arrayof_t){ .array = new_array, .size = new_size, .capacity = new_size };
}

fossil_tofu_arrayof_t fossil_dynamic_reverse_array(fossil_tofu_arrayof_t array) {
    if (!array.array || array.size == 0) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    fossil_tofu_t *new_array = (fossil_tofu_t *)malloc(array.size * sizeof(fossil_tofu_t));
    if (!new_array) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    for (size_t i = 0; i < array.size; ++i) {
        new_array[i] = array.array[array.size - 1 - i];
    }

    return (fossil_tofu_arrayof_t){ .array = new_array, .size = array.size, .capacity = array.size };
}

fossil_tofu_arrayof_t fossil_dynamic_filter_array(fossil_tofu_arrayof_t array, bool (*predicate)(fossil_tofu_t)) {
    if (!array.array || array.size == 0) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    fossil_tofu_t *filtered_array = (fossil_tofu_t *)malloc(array.size * sizeof(fossil_tofu_t));
    if (!filtered_array) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    size_t filtered_size = 0;
    for (size_t i = 0; i < array.size; ++i) {
        if (predicate(array.array[i])) {
            filtered_array[filtered_size++] = array.array[i];
        }
    }

    return (fossil_tofu_arrayof_t){ .array = filtered_array, .size = filtered_size, .capacity = filtered_size };
}

fossil_tofu_arrayof_t fossil_dynamic_map_array(fossil_tofu_arrayof_t array, fossil_tofu_t (*transform)(fossil_tofu_t)) {
    if (!array.array || array.size == 0) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    fossil_tofu_t *mapped_array = (fossil_tofu_t *)malloc(array.size * sizeof(fossil_tofu_t));
    if (!mapped_array) {
        return (fossil_tofu_arrayof_t){ .array = NULL, .size = 0, .capacity = 0 };
    }

    for (size_t i = 0; i < array.size; ++i) {
        mapped_array[i] = transform(array.array[i]);
    }

    return (fossil_tofu_arrayof_t){ .array = mapped_array, .size = array.size, .capacity = array.size };
}

void fossil_dynamic_sort_array(fossil_tofu_arrayof_t array, int (*compare)(const void *, const void *)) {
    if (!array.array || array.size == 0) {
        return;
    }

    qsort(array.array, array.size, sizeof(fossil_tofu_t), compare);
}

void fossil_dynamic_shuffle_array(fossil_tofu_arrayof_t array) {
    if (!array.array || array.size == 0) {
        return;
    }

    srand((unsigned int)time(NULL));
    for (size_t i = array.size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);
        fossil_tofu_t temp = array.array[i];
        array.array[i] = array.array[j];
        array.array[j] = temp;
    }
}
