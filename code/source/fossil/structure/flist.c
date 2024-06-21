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
#include "fossil/structure/flist.h"

fossil_flist_t* fossil_flist_create(char* type) {
    fossil_flist_t* flist = (fossil_flist_t*)malloc(sizeof(fossil_flist_t));
    if (flist) {
        flist->head = cnullptr;
        flist->type = type;  // Assuming type is a static string or managed separately
    }
    return flist;
}

void fossil_flist_erase(fossil_flist_t* flist) {
    if (!flist) return;

    fossil_flist_node_t* current = flist->head;
    while (current) {
        fossil_flist_node_t* next = current->next;
        free(current);
        current = next;
    }
    flist->head = cnullptr;
    free(flist);
}

int32_t fossil_flist_insert(fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* new_node = (fossil_flist_node_t*)malloc(sizeof(fossil_flist_node_t));
    if (!new_node) {
        return -1;  // Allocation failed
    }

    new_node->data = data;
    new_node->next = flist->head;
    flist->head = new_node;

    return 0;  // Success
}

int32_t fossil_flist_remove(fossil_flist_t* flist, fossil_tofu_t* data) {
    if (fossil_flist_is_empty(flist)) {
        return -1;  // Empty list
    }

    fossil_flist_node_t* node_to_remove = flist->head;
    *data = node_to_remove->data;
    flist->head = node_to_remove->next;
    free(node_to_remove);

    return 0;  // Success
}

int32_t fossil_flist_search(const fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* current = flist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return 0;  // Found
        }
        current = current->next;
    }
    return -1;  // Not found
}

void fossil_flist_reverse_forward(fossil_flist_t* flist) {
    fossil_flist_node_t* prev = cnullptr;
    fossil_flist_node_t* current = flist->head;
    fossil_flist_node_t* next = cnullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    flist->head = prev;
}

void fossil_flist_reverse_backward(fossil_flist_t* flist) {
    fossil_flist_reverse_forward(flist);
}

size_t fossil_flist_size(const fossil_flist_t* flist) {
    size_t count = 0;
    fossil_flist_node_t* current = flist->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_flist_getter(fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* current = flist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return cnullptr;  // Not found
}

int32_t fossil_flist_setter(fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* current = flist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return 0;  // Success
        }
        current = current->next;
    }
    return -1;  // Not found
}

bool fossil_flist_not_empty(const fossil_flist_t* flist) {
    return flist->head != cnullptr;
}

bool fossil_flist_not_cnullptr(const fossil_flist_t* flist) {
    return flist != cnullptr;
}

bool fossil_flist_is_empty(const fossil_flist_t* flist) {
    return flist->head == cnullptr;
}

bool fossil_flist_is_cnullptr(const fossil_flist_t* flist) {
    return flist == cnullptr;
}
