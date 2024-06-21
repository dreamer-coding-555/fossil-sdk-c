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
#include "fossil/structure/dlist.h"

fossil_dlist_t* fossil_dlist_create(char* type) {
    fossil_dlist_t* dlist = (fossil_dlist_t*)malloc(sizeof(fossil_dlist_t));
    if (dlist) {
        dlist->head = cnullptr;
        dlist->tail = cnullptr;
        dlist->type = type;  // Assuming type is a static string or managed separately
    }
    return dlist;
}

void fossil_dlist_erase(fossil_dlist_t* dlist) {
    if (!dlist) return;

    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        fossil_dlist_node_t* next = current->next;
        free(current);
        current = next;
    }
    dlist->head = cnullptr;
    dlist->tail = cnullptr;
    free(dlist);
}

int32_t fossil_dlist_insert(fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* new_node = (fossil_dlist_node_t*)malloc(sizeof(fossil_dlist_node_t));
    if (!new_node) {
        return -1;  // Allocation failed
    }

    new_node->data = data;
    new_node->prev = cnullptr;
    new_node->next = cnullptr;

    if (dlist->head == cnullptr) {
        // Empty list case
        dlist->head = new_node;
        dlist->tail = new_node;
    } else {
        // Non-empty list case
        new_node->prev = dlist->tail;
        dlist->tail->next = new_node;
        dlist->tail = new_node;
    }

    return 0;  // Success
}

int32_t fossil_dlist_remove(fossil_dlist_t* dlist, fossil_tofu_t* data) {
    if (fossil_dlist_is_empty(dlist)) {
        return -1;  // Empty list
    }

    fossil_dlist_node_t* node_to_remove = dlist->tail;

    if (node_to_remove == dlist->head) {
        // Only one node in the list
        dlist->head = cnullptr;
        dlist->tail = cnullptr;
    } else {
        dlist->tail = node_to_remove->prev;
        dlist->tail->next = cnullptr;
    }

    *data = node_to_remove->data;
    free(node_to_remove);

    return 0;  // Success
}

int32_t fossil_dlist_search(const fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return 0;  // Found
        }
        current = current->next;
    }
    return -1;  // Not found
}

void fossil_dlist_reverse_forward(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = cnullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node
    }

    // Swap head and tail
    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

void fossil_dlist_reverse_backward(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->tail;
    fossil_dlist_node_t* temp = cnullptr;

    while (current) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->next; // Move to the previous node
    }

    // Swap head and tail
    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

size_t fossil_dlist_size(const fossil_dlist_t* dlist) {
    size_t count = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_dlist_getter(fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return cnullptr;  // Not found
}

int32_t fossil_dlist_setter(fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return 0;  // Success
        }
        current = current->next;
    }
    return -1;  // Not found
}

bool fossil_dlist_not_empty(const fossil_dlist_t* dlist) {
    return (dlist != cnullptr && dlist->head != cnullptr);
}

bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist) {
    return (dlist != cnullptr);
}

bool fossil_dlist_is_empty(const fossil_dlist_t* dlist) {
    return (dlist == cnullptr || dlist->head == cnullptr);
}

bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist) {
    return (dlist == cnullptr);
}
