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
#include "fossil/structures/set.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cset* fossil_set_create(fossil_tofu_type set_type) {
    cset* new_set = (cset*)malloc(sizeof(cset));
    if (new_set == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_set->head = cnullptr;
    new_set->set_type = set_type;

    return new_set;
}

void fossil_set_erase(cset* set) {
    if (set == cnullptr) {
        return;
    }

    // Remove all nodes
    cset_node* current = set->head;
    while (current != cnullptr) {
        cset_node* next = current->next;
        free(current);
        current = next;
    }

    free(set);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

fossil_tofu_error_t fossil_set_insert(cset* set, fossil_tofu_t data) {
    if (set == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    // Check if the element already exists
    cset_node* current = set->head;
    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_TYPE_MISMATCH); // Duplicate element
        }
        current = current->next;
    }

    // Create a new node
    cset_node* new_node = (cset_node*)malloc(sizeof(cset_node));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->next = set->head;
    set->head = new_node;

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_set_remove(cset* set, fossil_tofu_t data) {
    if (set == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cset_node* current = set->head;
    cset_node* prev = cnullptr;

    // Find the node to remove
    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            if (prev == cnullptr) {
                set->head = current->next; // Remove the head node
            } else {
                prev->next = current->next; // Remove a non-head node
            }

            free(current);
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
        }

        prev = current;
        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Element not found
}

fossil_tofu_error_t fossil_set_search(const cset* set, fossil_tofu_t data) {
    if (set == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Element found
        }
        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Element not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fossil_set_size(const cset* set) {
    if (set == cnullptr) {
        return 0;
    }

    size_t size = 0;
    cset_node* current = set->head;

    // Count the number of elements
    while (current != cnullptr) {
        size++;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_set_getter(cset* set, fossil_tofu_t data) {
    if (set == cnullptr) {
        return cnullptr;
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Return a pointer to the element
        }
        current = current->next;
    }

    return cnullptr; // Element not found
}

fossil_tofu_error_t fossil_set_setter(cset* set, fossil_tofu_t data) {
    if (set == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            current->data = data; // Update the element
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
        }
        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Element not found
}

bool fossil_set_not_empty(const cset* set) {
    return set != cnullptr && set->head != cnullptr;
}

bool fossil_set_not_cnullptr(const cset* set) {
    return set != cnullptr;
}

bool fossil_set_is_empty(const cset* set) {
    return set == cnullptr || set->head == cnullptr;
}

bool fossil_set_is_cnullptr(const cset* set) {
    return set == cnullptr;
}

bool fossil_set_contains(const cset* set, fossil_tofu_t data) {
    if (set == cnullptr) {
        return false;
    }

    cset_node* current = set->head;

    // Check if the element exists
    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return true; // Element found
        }
        current = current->next;
    }

    return false; // Element not found
}

// =======================
// ITERATOR FUNCTIONS
// =======================
fossil_tofu_iterator fossil_set_iterator_start(cset* set) {
    fossil_tofu_iterator iterator;
    iterator.current_key = cnullptr;
    iterator.current_value = cnullptr;
    iterator.index = 0;

    if (set->head != cnullptr) {
        iterator.current_key = &set->head->data;
        iterator.current_value = &set->head->data;
    }

    return iterator;
}

fossil_tofu_iterator fossil_set_iterator_end(void) {
    fossil_tofu_iterator iterator;
    iterator.current_key = cnullptr;
    iterator.current_value = cnullptr;
    iterator.index = 0;
    return iterator;
}

fossil_tofu_iterator fossil_set_iterator_next(fossil_tofu_iterator iterator) {
    if (iterator.current_value != cnullptr) {
        iterator.current_key = &iterator.current_value[1];
        iterator.current_value = &iterator.current_value[1];
        iterator.index++;
    }

    return iterator;
}

bool fossil_set_iterator_has_next(fossil_tofu_iterator iterator) {
    return iterator.current_value != cnullptr;
}
