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
#include "fossil/xstructures/flist.h"
#include "fossil/xstructures/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cflist* fossil_flist_create(fossil_tofu_type list_type) {
    cflist* new_flist = (cflist*)malloc(sizeof(cflist));
    if (new_flist == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_flist->list_type = list_type;
    new_flist->head = cnullptr;

    return new_flist;
}

void fossil_flist_erase(cflist* flist) {
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

fossil_tofu_error_t fossil_flist_insert(cflist* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cflist_node* new_node = (cflist_node*)malloc(sizeof(cflist_node));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->next = flist->head;
    flist->head = new_node;

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_flist_remove(cflist* flist, fossil_tofu_t* data) {
    if (flist == cnullptr || data == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (flist->head == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // List is empty
    }

    cflist_node* temp = flist->head;
    flist->head = flist->head->next;

    *data = temp->data;
    free(temp);

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_flist_search(const cflist* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cflist_node* current = flist->head;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Found
        }

        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Not found
}

void fossil_flist_reverse_forward(cflist* flist) {
    if (flist == cnullptr || flist->head == cnullptr) {
        return;
    }

    cflist_node* prev = cnullptr;
    cflist_node* current = flist->head;
    cflist_node* next = cnullptr;

    while (current != cnullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    flist->head = prev;
}

void fossil_flist_reverse_backward(cflist* flist) {
    if (flist == cnullptr || flist->head == cnullptr) {
        return;
    }

    cflist_node* prev = cnullptr;
    cflist_node* current = flist->head;
    cflist_node* next = cnullptr;

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
size_t fossil_flist_size(const cflist* flist) {
    if (flist == cnullptr) {
        return 0;
    }

    size_t size = 0;
    cflist_node* current = flist->head;

    while (current != cnullptr) {
        ++size;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_flist_getter(cflist* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return cnullptr;
    }

    cflist_node* current = flist->head;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return cnullptr; // Not found
}

fossil_tofu_error_t fossil_flist_setter(cflist* flist, fossil_tofu_t data) {
    if (flist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cflist_node* current = flist->head;

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

bool fossil_flist_not_empty(const cflist* flist) {
    return flist != cnullptr && flist->head != cnullptr;
}

bool fossil_flist_not_cnullptr(const cflist* flist) {
    return flist != cnullptr;
}

bool fossil_flist_is_empty(const cflist* flist) {
    return flist == cnullptr || flist->head == cnullptr;
}

bool fossil_flist_is_cnullptr(const cflist* flist) {
    return flist == cnullptr;
}
