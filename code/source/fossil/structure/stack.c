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
#include "fossil/structure/stack.h"

fossil_stack_t* fossil_stack_create(char* type) {
    fossil_stack_t* stack = (fossil_stack_t*)malloc(sizeof(fossil_stack_t));
    if (stack) {
        stack->type = type; // Assuming type is a static string or managed separately
        stack->top = cnullptr;
    }
    return stack;
}

void fossil_stack_erase(fossil_stack_t* stack) {
    if (!stack) return;

    fossil_stack_node_t* current = stack->top;
    while (current) {
        fossil_stack_node_t* next = current->next;
        free(current);
        current = next;
    }
    stack->top = cnullptr;
    free(stack);
}

int32_t fossil_stack_insert(fossil_stack_t* stack, fossil_tofu_t data) {
    fossil_stack_node_t* new_node = (fossil_stack_node_t*)malloc(sizeof(fossil_stack_node_t));
    if (!new_node) {
        return -1; // Allocation failed
    }

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;

    return 0; // Success
}

int32_t fossil_stack_remove(fossil_stack_t* stack, fossil_tofu_t* data) {
    if (!stack->top) {
        return -1; // Stack is empty
    }

    fossil_stack_node_t* top_node = stack->top;
    *data = top_node->data;
    stack->top = top_node->next;
    free(top_node);

    return 0; // Success
}

int32_t fossil_stack_search(const fossil_stack_t* stack, fossil_tofu_t data) {
    fossil_stack_node_t* current = stack->top;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return 0; // Found
        }
        current = current->next;
    }
    return -1; // Not found
}

size_t fossil_stack_size(const fossil_stack_t* stack) {
    size_t count = 0;
    fossil_stack_node_t* current = stack->top;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_stack_getter(fossil_stack_t* stack, fossil_tofu_t data) {
    fossil_stack_node_t* current = stack->top;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data); // Return pointer to found data
        }
        current = current->next;
    }
    return cnullptr; // Not found
}

int32_t fossil_stack_setter(fossil_stack_t* stack, fossil_tofu_t data) {
    fossil_stack_node_t* current = stack->top;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data; // Update data
            return 0; // Success
        }
        current = current->next;
    }
    return -1; // Not found
}

bool fossil_stack_not_empty(const fossil_stack_t* stack) {
    return stack->top != cnullptr;
}

bool fossil_stack_not_cnullptr(const fossil_stack_t* stack) {
    return stack != cnullptr;
}

bool fossil_stack_is_empty(const fossil_stack_t* stack) {
    return stack->top == cnullptr;
}

bool fossil_stack_is_cnullptr(const fossil_stack_t* stack) {
    return stack == cnullptr;
}

fossil_tofu_t fossil_stack_top(fossil_stack_t* stack, fossil_tofu_t default_value) {
    if (!stack->top) {
        return default_value; // Stack is empty
    }
    return stack->top->data;
}
