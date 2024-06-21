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

fossil_queue_t* fossil_queue_create(char* type) {
    fossil_queue_t* queue = (fossil_queue_t*)malloc(sizeof(fossil_queue_t));
    if (queue) {
        queue->front = cnullptr;
        queue->rear = cnullptr;
        queue->type = type;  // Assuming type is a static string or managed separately
    }
    return queue;
}

void fossil_queue_erase(fossil_queue_t* queue) {
    if (!queue) return;

    fossil_queue_node_t* current = queue->front;
    while (current) {
        fossil_queue_node_t* next = current->next;
        free(current);
        current = next;
    }
    queue->front = cnullptr;
    queue->rear = cnullptr;
    free(queue);
}

int32_t fossil_queue_insert(fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* new_node = (fossil_queue_node_t*)malloc(sizeof(fossil_queue_node_t));
    if (!new_node) {
        return -1;  // Allocation failed
    }

    new_node->data = data;
    new_node->next = cnullptr;

    if (queue->rear == cnullptr) {
        // Empty queue case
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        // Non-empty queue case
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    return 0;  // Success
}

int32_t fossil_queue_remove(fossil_queue_t* queue, fossil_tofu_t* data) {
    if (fossil_queue_is_empty(queue)) {
        return -1;  // Empty queue
    }

    fossil_queue_node_t* node_to_remove = queue->front;
    *data = node_to_remove->data;
    queue->front = node_to_remove->next;
    free(node_to_remove);

    if (queue->front == cnullptr) {
        queue->rear = cnullptr;
    }

    return 0;  // Success
}

int32_t fossil_queue_search(const fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* current = queue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return 0;  // Found
        }
        current = current->next;
    }
    return -1;  // Not found
}

size_t fossil_queue_size(const fossil_queue_t* queue) {
    size_t count = 0;
    fossil_queue_node_t* current = queue->front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_queue_getter(fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* current = queue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return cnullptr;  // Not found
}

int32_t fossil_queue_setter(fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* current = queue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return 0;  // Success
        }
        current = current->next;
    }
    return -1;  // Not found
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
