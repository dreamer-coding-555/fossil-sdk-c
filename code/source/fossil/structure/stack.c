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
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>

// =======================
// CREATE and DELETE
// =======================

fossil_stack_t* fossil_stack_create(fossil_tofu_type stack_type) {
    fossil_stack_t* new_stack = (fossil_stack_t*)malloc(sizeof(fossil_stack_t));
    if (new_stack == cnullptr) {
        return cnullptr; // Handle memory allocation failure
    }

    new_stack->stack_type = stack_type;
    new_stack->top = cnullptr;

    return new_stack;
}

void fossil_stack_erase(fossil_stack_t* stack) {
    if (stack == cnullptr) {
        return;
    }

    while (fossil_stack_not_empty(stack)) {
        fossil_tofu_t removedData;
        fossil_stack_remove(stack, &removedData);
    }

    free(stack);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================
fossil_tofu_error_t fossil_stack_insert(fossil_stack_t* stack, fossil_tofu_t data) {
    if (stack == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_stack_node_t* new_node = (fossil_stack_node_t*)malloc(sizeof(fossil_stack_node_t));
    if (new_node == cnullptr) {
        // Handle memory allocation failure
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);
    }

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_stack_remove(fossil_stack_t* stack, fossil_tofu_t* data) {
    if (stack == cnullptr || data == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (stack->top == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Stack is empty
    }

    fossil_stack_node_t* temp = stack->top;
    stack->top = stack->top->next;

    *data = temp->data;
    free(temp);

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_stack_search(const fossil_stack_t* stack, fossil_tofu_t data) {
    if (stack == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_stack_node_t* current = stack->top;

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
size_t fossil_stack_size(const fossil_stack_t* stack) {
    if (stack == cnullptr) {
        return 0;
    }

    size_t size = 0;
    fossil_stack_node_t* current = stack->top;

    while (current != cnullptr) {
        ++size;
        current = current->next;
    }

    return size;
}

fossil_tofu_t* fossil_stack_getter(fossil_stack_t* stack, fossil_tofu_t data) {
    if (stack == cnullptr) {
        return cnullptr;
    }

    fossil_stack_node_t* current = stack->top;

    while (current != cnullptr) {
        if (fossil_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return cnullptr; // Not found
}

fossil_tofu_error_t fossil_stack_setter(fossil_stack_t* stack, fossil_tofu_t data) {
    if (stack == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    fossil_stack_node_t* current = stack->top;

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

bool fossil_stack_not_empty(const fossil_stack_t* stack) {
    return stack != cnullptr && stack->top != cnullptr;
}

bool fossil_stack_not_cnullptr(const fossil_stack_t* stack) {
    return stack != cnullptr;
}

bool fossil_stack_is_empty(const fossil_stack_t* stack) {
    return stack == cnullptr || stack->top == cnullptr;
}

bool fossil_stack_is_cnullptr(const fossil_stack_t* stack) {
    return stack == cnullptr;
}

fossil_tofu_t fossil_stack_top(fossil_stack_t* stack, fossil_tofu_t default_value) {
    if (stack == cnullptr || stack->top == cnullptr) {
        return default_value; // Return default value if the stack is empty
    }

    return stack->top->data;
}
