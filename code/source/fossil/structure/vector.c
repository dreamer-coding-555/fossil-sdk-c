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
#include "fossil/structure/vector.h"

fossil_vector_t* fossil_vector_create(char* type) {
    fossil_vector_t* vector = (fossil_vector_t*)malloc(sizeof(fossil_vector_t));
    if (vector) {
        vector->data = cnullptr;
        vector->size = 0;
        vector->capacity = 0;
        vector->type = type; // Assuming type is a static string or managed separately
    }
    return vector;
}

void fossil_vector_erase(fossil_vector_t* vector) {
    if (!vector) return;

    free(vector->data);
    vector->data = cnullptr;
    vector->size = 0;
    vector->capacity = 0;
    free(vector);
}

void fossil_vector_push_back(fossil_vector_t* vector, fossil_tofu_t element) {
    if (vector->size >= vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        fossil_tofu_t* new_data = (fossil_tofu_t*)realloc(vector->data, new_capacity * sizeof(fossil_tofu_t));
        if (!new_data) {
            // Handle allocation failure
            return;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    vector->data[vector->size++] = element;
}

int fossil_vector_search(const fossil_vector_t* vector, fossil_tofu_t target) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (fossil_tofu_equals(vector->data[i], target)) {
            return (int)i; // Found
        }
    }
    return -1; // Not found
}

void fossil_vector_reverse(fossil_vector_t* vector) {
    for (size_t i = 0; i < vector->size / 2; ++i) {
        fossil_tofu_t temp = vector->data[i];
        vector->data[i] = vector->data[vector->size - i - 1];
        vector->data[vector->size - i - 1] = temp;
    }
}

bool fossil_vector_is_cnullptr(const fossil_vector_t* vector) {
    return vector == cnullptr;
}

bool fossil_vector_not_cnullptr(const fossil_vector_t* vector) {
    return vector != cnullptr;
}

bool fossil_vector_is_empty(const fossil_vector_t* vector) {
    return vector->size == 0;
}

bool fossil_vector_not_empty(const fossil_vector_t* vector) {
    return vector->size != 0;
}

void fossil_vector_setter(fossil_vector_t* vector, size_t index, fossil_tofu_t element) {
    if (index < vector->size) {
        vector->data[index] = element;
    }
}

fossil_tofu_t* fossil_vector_getter(const fossil_vector_t* vector, size_t index) {
    if (index < vector->size) {
        return &(vector->data[index]);
    }
    return cnullptr; // Handle out-of-bounds access
}

size_t fossil_vector_size(const fossil_vector_t* vector) {
    return vector->size;
}

void fossil_vector_peek(const fossil_vector_t* vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        fossil_tofu_print(vector->data[i]);
    }
}

