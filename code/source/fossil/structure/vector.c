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
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>

// =======================
// CREATE and DELETE
// =======================

fossil_vector_t fossil_vector_create(fossil_tofu_type expected_type) {
    fossil_vector_t new_vector;
    new_vector.data = (fossil_tofu_t*)malloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    if (new_vector.data == cnullptr) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    new_vector.size = 0;
    new_vector.capacity = INITIAL_CAPACITY;
    new_vector.expected_type = expected_type;

    return new_vector;
}

void fossil_vector_erase(fossil_vector_t* vector) {
    if (vector == cnullptr) {
        return;
    }

    free(vector->data);
    vector->data = cnullptr;
    vector->size = 0;
    vector->capacity = 0;
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

void fossil_vector_push_back(fossil_vector_t* vector, fossil_tofu_t element) {
    if (vector == cnullptr) {
        return;
    }

    // Check if the vector needs to be resized
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = (fossil_tofu_t*)realloc(vector->data, vector->capacity * sizeof(fossil_tofu_t));
        if (vector->data == cnullptr) {
            // Handle memory allocation failure
            exit(EXIT_FAILURE);
        }
    }

    // Check if the type matches the expected type
    if (element.type != vector->expected_type) {
        // Handle type mismatch
        exit(EXIT_FAILURE);
    }

    // Add the element to the vector
    vector->data[vector->size++] = element;
}

int fossil_vector_search(const fossil_vector_t* vector, fossil_tofu_t target) {
    if (vector == cnullptr) {
        return -1;
    }

    for (size_t i = 0; i < vector->size; ++i) {
        if (fossil_tofu_compare(&target, &vector->data[i]) == FOSSIL_TOFU_ERROR_OK) {
            return i; // Element found at index i
        }
    }

    return -1; // Element not found
}

void fossil_vector_reverse(fossil_vector_t* vector) {
    if (vector == cnullptr) {
        return;
    }

    for (size_t i = 0, j = vector->size - 1; i < j; ++i, --j) {
        // Swap elements at positions i and j
        fossil_tofu_t temp = vector->data[i];
        vector->data[i] = vector->data[j];
        vector->data[j] = temp;
    }
}

// =======================
// UTILITY FUNCTIONS
// =======================

bool fossil_vector_is_cnullptr(const fossil_vector_t* vector) {
    return vector == cnullptr;
}

bool fossil_vector_not_cnullptr(const fossil_vector_t* vector) {
    return vector != cnullptr;
}

bool fossil_vector_is_empty(const fossil_vector_t* vector) {
    return vector == cnullptr || vector->size == 0;
}

bool fossil_vector_not_empty(const fossil_vector_t* vector) {
    return vector != cnullptr && vector->size != 0;
}

void fossil_vector_setter(fossil_vector_t* vector, size_t index, fossil_tofu_t element) {
    if (vector == cnullptr || index >= vector->size) {
        return;
    }

    // Check if the type matches the expected type
    if (element.type != vector->expected_type) {
        // Handle type mismatch
        exit(EXIT_FAILURE);
    }

    vector->data[index] = element;
}

fossil_tofu_t fossil_vector_getter(const fossil_vector_t* vector, size_t index) {
    if (vector == cnullptr || index >= vector->size) {
        return (fossil_tofu_t){.type = TOFU_INVALID_TYPE}; // Invalid or out-of-bounds access
    }

    return vector->data[index];
}

size_t fossil_vector_size(const fossil_vector_t* vector) {
    return vector != cnullptr ? vector->size : 0;
}

void fossil_vector_peek(const fossil_vector_t* vector) {
    if (vector == cnullptr) {
        return;
    }

    printf("Vector contents: [");
    for (size_t i = 0; i < vector->size; ++i) {
        if (i > 0) {
            printf(", ");
        }
        fossil_tofu_out(vector->data[i]);
    }
    printf("]\n");
}

// =======================
// ITERATOR FUNCTIONS
// =======================

fossil_tofu_iterator fossil_vector_iterator_start(const fossil_vector_t* vector) {
    if (vector == cnullptr || vector->size == 0) {
        return (fossil_tofu_iterator){.current_value = cnullptr, .index = 0};
    }

    return (fossil_tofu_iterator){.current_value = &vector->data[0], .index = 0};
}

fossil_tofu_iterator fossil_vector_iterator_end(const fossil_vector_t* vector) {
    if (vector == cnullptr || vector->size == 0) {
        return (fossil_tofu_iterator){.current_value = cnullptr, .index = vector->size};
    }

    return (fossil_tofu_iterator){.current_value = &vector->data[vector->size - 1], .index = vector->size - 1};
}

fossil_tofu_iterator fossil_vector_iterator_next(const fossil_vector_t* vector, fossil_tofu_iterator iterator) {
    if (vector == cnullptr || iterator.index >= vector->size - 1) {
        return (fossil_tofu_iterator){.current_value = cnullptr, .index = iterator.index + 1};
    }

    return (fossil_tofu_iterator){.current_value = &vector->data[iterator.index + 1], .index = iterator.index + 1};
}

bool fossil_vector_iterator_has_next(const fossil_vector_t* vector, fossil_tofu_iterator iterator) {
    return vector != cnullptr && iterator.index < vector->size - 1;
}
