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
#include "fossil/structures/flist.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

fossil_flist_t* fossil_flist_create(fossil_tofu_type list_type) {
    fossil_flist_t* new_flist = (fossil_flist_t*)malloc(sizeof(fossil_flist_t));
    if (new_flist == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_flist->list_type = list_type;
    new_flist->head = cnullptr;

    return new_flist;
}

void fossil_flist_erase(fossil_flist_t* flist) {
    if (flist == cnullptr) {
        return;
    }

    while (flist->head != cnullptr) {
        fossil_tofu_t data;
        fossil_flist_remove(flist, &data);
    }

    free(flist);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

fossil_tofu_error_t fossil_flist_insert(fossil_flist_t* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_flist_node_t* new_node = (fossil_flist_node_t*)malloc(sizeof(fossil_flist_node_t));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->next = flist->head;
    flist->head = new_node;

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_flist_remove(fossil_flist_t* flist, fossil_tofu_t* data) {
    if (flist == cnullptr || data == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (flist->head == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // List is empty
    }

    fossil_flist_node_t* temp = flist->head;
    flist->head = flist->head->next;

    *data = temp->data;
    free(temp);

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_flist_search(const fossil_flist_t* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_flist_node_t* current = flist->head;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Found
        }

        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Not found
}

void fossil_flist_reverse_forward(fossil_flist_t* flist) {
    if (flist == cnullptr || flist->head == cnullptr) {
        return;
    }

    fossil_flist_node_t* prev = cnullptr;
    fossil_flist_node_t* current = flist->head;
    fossil_flist_node_t* next = cnullptr;

    while (current != cnullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    flist->head = prev;
}

void fossil_flist_reverse_backward(fossil_flist_t* flist) {
    if (flist == cnullptr || flist->head == cnullptr) {
        return;
    }

    fossil_flist_node_t* prev = cnullptr;
    fossil_flist_node_t* current = flist->head;
    fossil_flist_node_t* next = cnullptr;

    while (current != cnullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    flist->head = prev;
}

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fossil_flist_size(const fossil_flist_t* flist) {
    if (flist == cnullptr) {
        return 0;
    }

    size_t size = 0;
    fossil_flist_node_t* current = flist->head;

    while (current != cnullptr) {
        ++size;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_flist_getter(fossil_flist_t* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return cnullptr;
    }

    fossil_flist_node_t* current = flist->head;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return cnullptr; // Not found
}

fossil_tofu_error_t fossil_flist_setter(fossil_flist_t* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_flist_node_t* current = flist->head;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            // Found, update the data
            current->data = data;
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
        }

        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Not found
}

bool fossil_flist_not_empty(const fossil_flist_t* flist) {
    return flist != cnullptr && flist->head != cnullptr;
}

bool fossil_flist_not_cnullptr(const fossil_flist_t* flist) {
    return flist != cnullptr;
}

bool fossil_flist_is_empty(const fossil_flist_t* flist) {
    return flist == cnullptr || flist->head == cnullptr;
}

bool fossil_flist_is_cnullptr(const fossil_flist_t* flist) {
    return flist == cnullptr;
}
