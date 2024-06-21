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

fossil_pqueue_t* fossil_pqueue_create(char* type) {
    fossil_pqueue_t* pqueue = (fossil_pqueue_t*)malloc(sizeof(fossil_pqueue_t));
    if (pqueue) {
        pqueue->front = cnullptr;
        pqueue->type = type;  // Assuming type is a static string or managed separately
    }
    return pqueue;
}

void fossil_pqueue_erase(fossil_pqueue_t* pqueue) {
    if (!pqueue) return;

    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        fossil_pqueue_node_t* next = current->next;
        free(current);
        current = next;
    }
    pqueue->front = cnullptr;
    free(pqueue);
}

int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    fossil_pqueue_node_t* new_node = (fossil_pqueue_node_t*)malloc(sizeof(fossil_pqueue_node_t));
    if (!new_node) {
        return -1;  // Allocation failed
    }

    new_node->data = data;
    new_node->priority = priority;
    new_node->next = cnullptr;

    if (!pqueue->front || pqueue->front->priority > priority) {
        new_node->next = pqueue->front;
        pqueue->front = new_node;
    } else {
        fossil_pqueue_node_t* current = pqueue->front;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    return 0;  // Success
}

int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, fossil_tofu_t* data, int32_t priority) {
    if (fossil_pqueue_is_empty(pqueue)) {
        return -1;  // Empty queue
    }

    fossil_pqueue_node_t* current = pqueue->front;
    fossil_pqueue_node_t* prev = cnullptr;

    while (current && current->priority != priority) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        return -1;  // Not found
    }

    if (prev) {
        prev->next = current->next;
    } else {
        pqueue->front = current->next;
    }

    *data = current->data;
    free(current);

    return 0;  // Success
}

int32_t fossil_pqueue_search(const fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        if (current->priority == priority && fossil_tofu_equals(current->data, data)) {
            return 0;  // Found
        }
        current = current->next;
    }
    return -1;  // Not found
}

size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue) {
    size_t count = 0;
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_pqueue_getter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        if (current->priority == priority && fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return cnullptr;  // Not found
}

int32_t fossil_pqueue_setter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        if (current->priority == priority && fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return 0;  // Success
        }
        current = current->next;
    }
    return -1;  // Not found
}

bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue) {
    return pqueue->front != cnullptr;
}

bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue != cnullptr;
}

bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue) {
    return pqueue->front == cnullptr;
}

bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue == cnullptr;
}
