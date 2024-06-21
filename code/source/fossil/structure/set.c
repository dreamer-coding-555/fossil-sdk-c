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
#include "fossil/structure/set.h"

fossil_set_t* fossil_set_create(char* type) {
    fossil_set_t* set = (fossil_set_t*)malloc(sizeof(fossil_set_t));
    if (set) {
        set->head = cnullptr;
        set->type = type;  // Assuming type is a static string or managed separately
    }
    return set;
}

void fossil_set_erase(fossil_set_t* set) {
    if (!set) return;

    fossil_set_node_t* current = set->head;
    while (current) {
        fossil_set_node_t* next = current->next;
        free(current);
        current = next;
    }
    set->head = cnullptr;
    free(set);
}

int32_t fossil_set_insert(fossil_set_t* set, fossil_tofu_t data) {
    if (fossil_set_contains(set, data)) {
        return -1;  // Duplicate element, insert fails
    }

    fossil_set_node_t* new_node = (fossil_set_node_t*)malloc(sizeof(fossil_set_node_t));
    if (!new_node) {
        return -2;  // Allocation failed
    }

    new_node->data = data;
    new_node->next = set->head;
    set->head = new_node;

    return 0;  // Success
}

int32_t fossil_set_remove(fossil_set_t* set, fossil_tofu_t data) {
    fossil_set_node_t* current = set->head;
    fossil_set_node_t* prev = cnullptr;

    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            if (prev) {
                prev->next = current->next;
            } else {
                set->head = current->next;
            }
            free(current);
            return 0;  // Success
        }
        prev = current;
        current = current->next;
    }
    return -1;  // Element not found
}

int32_t fossil_set_search(const fossil_set_t* set, fossil_tofu_t data) {
    fossil_set_node_t* current = set->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return 0;  // Found
        }
        current = current->next;
    }
    return -1;  // Not found
}

int32_t fossil_set_contains(const fossil_set_t* set, fossil_tofu_t data) {
    return fossil_set_search(set, data) == 0;
}

size_t fossil_set_size(const fossil_set_t* set) {
    size_t count = 0;
    fossil_set_node_t* current = set->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_set_getter(fossil_set_t* set, fossil_tofu_t data) {
    fossil_set_node_t* current = set->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return cnullptr;  // Not found
}

int32_t fossil_set_setter(fossil_set_t* set, fossil_tofu_t data) {
    fossil_set_node_t* current = set->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return 0;  // Success
        }
        current = current->next;
    }
    return -1;  // Not found
}

bool fossil_set_not_empty(const fossil_set_t* set) {
    return set->head != cnullptr;
}

bool fossil_set_not_cnullptr(const fossil_set_t* set) {
    return set != cnullptr;
}

bool fossil_set_is_empty(const fossil_set_t* set) {
    return set == cnullptr || set->head == cnullptr;
}

bool fossil_set_is_cnullptr(const fossil_set_t* set) {
    return set == cnullptr;
}
