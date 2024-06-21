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
#include "fossil/generic/iterator.h"

// Function to create a new iterator for an array of tofu
fossil_tofu_iteratorof_t fossil_tofu_iteratorof_create(fossil_tofu_t *array, size_t size) {
    fossil_tofu_iteratorof_t iterator;
    iterator.array = array;
    iterator.size = size;
    iterator.current_index = 0;
    return iterator;
}

// Function to check if the iterator has more elements
bool fossil_tofu_iteratorof_has_next(fossil_tofu_iteratorof_t *iterator) {
    return iterator->current_index < iterator->size;
}

// Function to get the next element in the iterator
fossil_tofu_t fossil_tofu_iteratorof_next(fossil_tofu_iteratorof_t *iterator) {
    if (fossil_tofu_iteratorof_has_next(iterator)) {
        return iterator->array[iterator->current_index++];
    }
    return fossil_tofu_create("ghost", ""); // Return a ghost tofu if no more elements
}

// Function to reset the iterator to the beginning
void fossil_tofu_iteratorof_reset(fossil_tofu_iteratorof_t *iterator) {
    iterator->current_index = 0;
}
