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
#include "fossil/structures/stack.h" // lib source code

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_stack_create_and_erase) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Check if the stack is created with the expected values
    ASSUME_NOT_CNULL(stack);
    ASSUME_ITS_CNULL(stack->top);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, stack->stack_type);

    fossil_stack_erase(stack);

    // Check if the stack is erased
    ASSUME_ITS_CNULL(stack->top);
    ASSUME_ITS_CNULL(stack);
}

FOSSIL_TEST(test_stack_insert_and_size) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_stack_size(stack));

    fossil_stack_erase(stack);
}

FOSSIL_TEST(test_stack_remove) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_stack_insert(stack, element1);
    fossil_stack_insert(stack, element2);
    fossil_stack_insert(stack, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_remove(stack, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_stack_size(stack));

    fossil_stack_erase(stack);
}

FOSSIL_TEST(test_stack_top) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_stack_insert(stack, element1);
    fossil_stack_insert(stack, element2);
    fossil_stack_insert(stack, element3);

    // Check the top element
    fossil_tofu_t topElement = fossil_stack_top(stack, (fossil_tofu_t){TOFU_INT_TYPE, {.int_type = -1}});
    ASSUME_ITS_EQUAL_I32(5, topElement.data.int_type);

    // Remove an element
    fossil_stack_remove(stack, NULL);

    // Check the top element after removal
    topElement = fossil_stack_top(stack, (fossil_tofu_t){TOFU_INT_TYPE, {.int_type = -1}});
    ASSUME_ITS_EQUAL_I32(10, topElement.data.int_type);

    fossil_stack_erase(stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_stack_group) {
    ADD_TEST(test_stack_create_and_erase);
    ADD_TEST(test_stack_insert_and_size);
    ADD_TEST(test_stack_remove);
    ADD_TEST(test_stack_top);
} // end of func
