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
#include "fossil/xstructures/dlist.h"
#include "fossil/xstructures/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
cdlist* fossil_dlist_create(fossil_tofu_type list_type) {
    cdlist* new_dlist = (cdlist*)malloc(sizeof(cdlist));
    if (new_dlist == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_dlist->list_type = list_type;
    new_dlist->head = cnullptr;
    new_dlist->tail = cnullptr;

    return new_dlist;
}

void fossil_dlist_erase(cdlist* dlist) {
    if (dlist == cnullptr) {
        return;
    }

    while (dlist->head != cnullptr) {
        fossil_tofu_t data;
        fossil_dlist_remove(dlist, &data);
    }

    free(dlist);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================
fossil_tofu_error_t fossil_dlist_insert(cdlist* dlist, fossil_tofu_t data) {
    if (dlist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cdlist_node* new_node = (cdlist_node*)malloc(sizeof(cdlist_node));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->prev = cnullptr;
    new_node->next = cnullptr;

    if (dlist->head == cnullptr) {
        // List is empty
        dlist->head = new_node;
        dlist->tail = new_node;
    } else {
        new_node->next = dlist->head;
        dlist->head->prev = new_node;
        dlist->head = new_node;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_dlist_remove(cdlist* dlist, fossil_tofu_t* data) {
    if (dlist == cnullptr || data == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (dlist->head == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // List is empty
    }

    cdlist_node* temp = dlist->head;
    *data = temp->data;

    if (dlist->head == dlist->tail) {
        // Only one element in the list
        free(temp);
        dlist->head = cnullptr;
        dlist->tail = cnullptr;
    } else {
        dlist->head = dlist->head->next;
        dlist->head->prev = cnullptr;
        free(temp);
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_dlist_search(const cdlist* dlist, fossil_tofu_t data) {
    if (dlist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cdlist_node* current = dlist->head;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Found
        }

        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Not found
}

void fossil_dlist_reverse_forward(cdlist* dlist) {
    if (dlist == cnullptr || dlist->head == cnullptr || dlist->head == dlist->tail) {
        return;
    }

    cdlist_node* current = dlist->head;
    cdlist_node* temp = cnullptr;

    while (current != cnullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

void fossil_dlist_reverse_backward(cdlist* dlist) {
    if (dlist == cnullptr || dlist->head == cnullptr || dlist->head == dlist->tail) {
        return;
    }

    cdlist_node* current = dlist->tail;
    cdlist_node* temp = cnullptr;

    while (current != cnullptr) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->next;
    }

    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fossil_dlist_size(const cdlist* dlist) {
    if (dlist == cnullptr) {
        return 0;
    }

    size_t size = 0;
    cdlist_node* current = dlist->head;

    while (current != cnullptr) {
        ++size;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_dlist_getter(cdlist* dlist, fossil_tofu_t data) {
    if (dlist == cnullptr) {
        return cnullptr;
    }

    cdlist_node* current = dlist->head;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return cnullptr; // Not found
}

fossil_tofu_error_t fossil_dlist_setter(cdlist* dlist, fossil_tofu_t data) {
    if (dlist == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    cdlist_node* current = dlist->head;

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

bool fossil_dlist_not_empty(const cdlist* dlist) {
    return dlist != cnullptr && dlist->head != cnullptr;
}

bool fossil_dlist_not_cnullptr(const cdlist* dlist) {
    return dlist != cnullptr;
}

bool fossil_dlist_is_empty(const cdlist* dlist) {
    return dlist == cnullptr || dlist->head == cnullptr;
}

bool fossil_dlist_is_cnullptr(const cdlist* dlist) {
    return dlist == cnullptr;
}
