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
#include "fossil/structure/pqueue.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
fossil_pqueue_t* fossil_pqueue_create(fossil_tofu_type queue_type) {
    fossil_pqueue_t* new_pqueue = (fossil_pqueue_t*)malloc(sizeof(fossil_pqueue_t));
    if (new_pqueue == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_pqueue->queue_type = queue_type;
    new_pqueue->front = cnullptr;

    return new_pqueue;
}

void fossil_pqueue_erase(fossil_pqueue_t* pqueue) {
    if (pqueue == cnullptr) {
        return;
    }

    while (pqueue->front != cnullptr) {
        fossil_tofu_t data;
        int priority;
        fossil_pqueue_remove(pqueue, &data, &priority);
    }

    free(pqueue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

fossil_tofu_error_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority) {
    if (pqueue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_pqueue_node_t* new_node = (fossil_pqueue_node_t*)malloc(sizeof(fossil_pqueue_node_t));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->priority = priority;
    new_node->next = cnullptr;

    if (pqueue->front == cnullptr || priority > pqueue->front->priority) {
        // Insert at the beginning
        new_node->next = pqueue->front;
        pqueue->front = new_node;
    } else {
        fossil_pqueue_node_t* current = pqueue->front;

        while (current->next != cnullptr && priority <= current->next->priority) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, fossil_tofu_t* data, int* priority) {
    if (pqueue == cnullptr || data == cnullptr || priority == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (pqueue->front == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Queue is empty
    }

    fossil_pqueue_node_t* temp = pqueue->front;
    *data = temp->data;
    *priority = temp->priority;

    pqueue->front = pqueue->front->next;
    free(temp);

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_pqueue_search(const fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority) {
    if (pqueue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_pqueue_node_t* current = pqueue->front;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0 && current->priority == priority) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Found
        }

        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue) {
    if (pqueue == cnullptr) {
        return 0;
    }

    size_t size = 0;
    fossil_pqueue_node_t* current = pqueue->front;

    while (current != cnullptr) {
        ++size;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_pqueue_getter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority) {
    if (pqueue == cnullptr) {
        return cnullptr;
    }

    fossil_pqueue_node_t* current = pqueue->front;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0 && current->priority == priority) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return cnullptr; // Not found
}

fossil_tofu_error_t fossil_pqueue_setter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int priority) {
    if (pqueue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_pqueue_node_t* current = pqueue->front;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0 && current->priority == priority) {
            // Found, update the data
            current->data = data;
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
        }

        current = current->next;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Not found
}

bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue) {
    return pqueue != cnullptr && pqueue->front != cnullptr;
}

bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue != cnullptr;
}

bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue) {
    return pqueue == cnullptr || pqueue->front == cnullptr;
}

bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue == cnullptr;
}
