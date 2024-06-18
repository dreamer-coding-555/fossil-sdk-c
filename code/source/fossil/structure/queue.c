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
#include "fossil/structure/queue.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

fossil_queue_t* fossil_queue_create(fossil_tofu_type queue_type) {
    fossil_queue_t* new_queue = (fossil_queue_t*)malloc(sizeof(fossil_queue_t));
    if (new_queue == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_queue->queue_type = queue_type;
    new_queue->front = cnullptr;
    new_queue->rear = cnullptr;

    return new_queue;
}

void fossil_queue_erase(fossil_queue_t* queue) {
    if (queue == cnullptr) {
        return;
    }

    while (queue->front != cnullptr) {
        fossil_tofu_t data;
        fossil_queue_remove(queue, &data);
    }

    free(queue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

fossil_tofu_error_t fossil_queue_insert(fossil_queue_t* queue, fossil_tofu_t data) {
    if (queue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_queue_node_t* new_node = (fossil_queue_node_t*)malloc(sizeof(fossil_queue_node_t));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->next = cnullptr;

    if (queue->rear == cnullptr) {
        // Queue is empty
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_queue_remove(fossil_queue_t* queue, fossil_tofu_t* data) {
    if (queue == cnullptr || data == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (queue->front == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Queue is empty
    }

    fossil_queue_node_t* temp = queue->front;
    *data = temp->data;

    if (queue->front == queue->rear) {
        // Only one element in the queue
        free(temp);
        queue->front = cnullptr;
        queue->rear = cnullptr;
    } else {
        queue->front = queue->front->next;
        free(temp);
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_queue_search(const fossil_queue_t* queue, fossil_tofu_t data) {
    if (queue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_queue_node_t* current = queue->front;

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

size_t fossil_queue_size(const fossil_queue_t* queue) {
    if (queue == cnullptr) {
        return 0;
    }

    size_t size = 0;
    fossil_queue_node_t* current = queue->front;

    while (current != cnullptr) {
        ++size;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_queue_getter(fossil_queue_t* queue, fossil_tofu_t data) {
    if (queue == cnullptr) {
        return cnullptr;
    }

    fossil_queue_node_t* current = queue->front;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return cnullptr; // Not found
}

fossil_tofu_error_t fossil_queue_setter(fossil_queue_t* queue, fossil_tofu_t data) {
    if (queue == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_queue_node_t* current = queue->front;

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

bool fossil_queue_not_empty(const fossil_queue_t* queue) {
    return queue != cnullptr && queue->front != cnullptr;
}

bool fossil_queue_not_cnullptr(const fossil_queue_t* queue) {
    return queue != cnullptr;
}

bool fossil_queue_is_empty(const fossil_queue_t* queue) {
    return queue == cnullptr || queue->front == cnullptr;
}

bool fossil_queue_is_cnullptr(const fossil_queue_t* queue) {
    return queue == cnullptr;
}
