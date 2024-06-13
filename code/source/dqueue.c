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
#include "fossil/structures/dqueue.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
fossil_dqueue_t* fossil_dqueue_create(fossil_tofu_type list_type) {
    fossil_dqueue_t* new_dqueue = (fossil_dqueue_t*)malloc(sizeof(fossil_dqueue_t));
    if (new_dqueue == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_dqueue->list_type = list_type;
    new_dqueue->front = cnullptr;
    new_dqueue->rear = cnullptr;

    return new_dqueue;
}

void fossil_dqueue_erase(fossil_dqueue_t* dqueue) {
    if (dqueue == cnullptr) {
        return;
    }

    while (dqueue->front != cnullptr) {
        fossil_tofu_t data;
        fossil_dqueue_remove(dqueue, &data);
    }

    free(dqueue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

fossil_tofu_error_t fossil_dqueue_insert(fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    if (dqueue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_dqueue_node_t* new_node = (fossil_dqueue_node_t*)malloc(sizeof(fossil_dqueue_node_t));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->prev = cnullptr;
    new_node->next = cnullptr;

    if (dqueue->front == cnullptr) {
        // Queue is empty
        dqueue->front = new_node;
        dqueue->rear = new_node;
    } else {
        new_node->next = dqueue->front;
        dqueue->front->prev = new_node;
        dqueue->front = new_node;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_dqueue_remove(fossil_dqueue_t* dqueue, fossil_tofu_t* data) {
    if (dqueue == cnullptr || data == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (dqueue->front == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Queue is empty
    }

    fossil_dqueue_node_t* temp = dqueue->front;
    *data = temp->data;

    if (dqueue->front == dqueue->rear) {
        // Only one element in the queue
        free(temp);
        dqueue->front = cnullptr;
        dqueue->rear = cnullptr;
    } else {
        dqueue->front = dqueue->front->next;
        dqueue->front->prev = cnullptr;
        free(temp);
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_dqueue_search(const fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    if (dqueue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_dqueue_node_t* current = dqueue->front;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Found
        }

        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fossil_dqueue_size(const fossil_dqueue_t* dqueue) {
    if (dqueue == cnullptr) {
        return 0;
    }

    size_t size = 0;
    fossil_dqueue_node_t* current = dqueue->front;

    while (current != cnullptr) {
        ++size;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_dqueue_getter(fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    if (dqueue == cnullptr) {
        return cnullptr;
    }

    fossil_dqueue_node_t* current = dqueue->front;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return cnullptr; // Not found
}

fossil_tofu_error_t fossil_dqueue_setter(fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    if (dqueue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_dqueue_node_t* current = dqueue->front;

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

bool fossil_dqueue_not_empty(const fossil_dqueue_t* dqueue) {
    return dqueue != cnullptr && dqueue->front != cnullptr;
}

bool fossil_dqueue_not_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue != cnullptr;
}

bool fossil_dqueue_is_empty(const fossil_dqueue_t* dqueue) {
    return dqueue == cnullptr || dqueue->front == cnullptr;
}

bool fossil_dqueue_is_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue == cnullptr;
}
