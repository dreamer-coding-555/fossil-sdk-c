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
#include "fossil/structure/dqueue.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_dqueue_t* fossil_dqueue_create(char* type) {
    fossil_dqueue_t* dqueue = (fossil_dqueue_t*)malloc(sizeof(fossil_dqueue_t));
    if (dqueue) {
        dqueue->front = cnullptr;
        dqueue->rear = cnullptr;
        dqueue->type = type;  // Assuming type is a static string or managed separately
    }
    return dqueue;
}

void fossil_dqueue_erase(fossil_dqueue_t* dqueue) {
    if (!dqueue) return;

    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        fossil_dqueue_node_t* next = current->next;
        free(current);
        current = next;
    }
    dqueue->front = cnullptr;
    dqueue->rear = cnullptr;
    free(dqueue);
}

int32_t fossil_dqueue_insert(fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    fossil_dqueue_node_t* new_node = (fossil_dqueue_node_t*)malloc(sizeof(fossil_dqueue_node_t));
    if (!new_node) {
        return -1;  // Allocation failed
    }

    new_node->data = data;
    new_node->prev = cnullptr;
    new_node->next = cnullptr;

    if (dqueue->rear == cnullptr) {
        // Empty queue case
        dqueue->front = new_node;
        dqueue->rear = new_node;
    } else {
        // Non-empty queue case
        new_node->prev = dqueue->rear;
        dqueue->rear->next = new_node;
        dqueue->rear = new_node;
    }

    return 0;  // Success
}

int32_t fossil_dqueue_remove(fossil_dqueue_t* dqueue, fossil_tofu_t* data) {
    if (fossil_dqueue_is_empty(dqueue)) {
        return -1;  // Empty queue
    }

    fossil_dqueue_node_t* node_to_remove = dqueue->front;

    if (node_to_remove == dqueue->rear) {
        // Only one node in the queue
        dqueue->front = cnullptr;
        dqueue->rear = cnullptr;
    } else {
        dqueue->front = node_to_remove->next;
        dqueue->front->prev = cnullptr;
    }

    *data = node_to_remove->data;
    free(node_to_remove);

    return 0;  // Success
}

int32_t fossil_dqueue_search(const fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return 0;  // Found
        }
        current = current->next;
    }
    return -1;  // Not found
}

size_t fossil_dqueue_size(const fossil_dqueue_t* dqueue) {
    size_t count = 0;
    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_dqueue_getter(fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return cnullptr;  // Not found
}

int32_t fossil_dqueue_setter(fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return 0;  // Success
        }
        current = current->next;
    }
    return -1;  // Not found
}

bool fossil_dqueue_not_empty(const fossil_dqueue_t* dqueue) {
    return dqueue->front != cnullptr;
}

bool fossil_dqueue_not_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue != cnullptr;
}

bool fossil_dqueue_is_empty(const fossil_dqueue_t* dqueue) {
    return dqueue->front == cnullptr;
}

bool fossil_dqueue_is_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue == cnullptr;
}
