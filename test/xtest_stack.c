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
#include "fossil/xstructures/stack.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
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

XTEST(test_stack_create_and_erase) {
    cstack* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Check if the stack is created with the expected values
    TEST_ASSUME_NOT_CNULLPTR(stack);
    TEST_ASSUME_CNULLPTR(stack->top);
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, stack->stack_type);

    fossil_stack_erase(stack);

    // Check if the stack is erased
    TEST_ASSUME_CNULLPTR(stack->top);
    TEST_ASSUME_CNULLPTR(stack);
}

XTEST(test_stack_insert_and_size) {
    cstack* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element2));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element3));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(3, fossil_stack_size(stack));

    fossil_stack_erase(stack);
}

XTEST(test_stack_remove) {
    cstack* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_stack_insert(stack, element1);
    fossil_stack_insert(stack, element2);
    fossil_stack_insert(stack, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_stack_remove(stack, &removedElement));

    // Check if the removed element is correct
    TEST_ASSUME_EQUAL_INT(5, removedElement.data.int_type);

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(2, fossil_stack_size(stack));

    fossil_stack_erase(stack);
}

XTEST(test_stack_top) {
    cstack* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_stack_insert(stack, element1);
    fossil_stack_insert(stack, element2);
    fossil_stack_insert(stack, element3);

    // Check the top element
    fossil_tofu_t topElement = fossil_stack_top(stack, (fossil_tofu_t){TOFU_INT_TYPE, {.int_type = -1}});
    TEST_ASSUME_EQUAL_INT(5, topElement.data.int_type);

    // Remove an element
    fossil_stack_remove(stack, NULL);

    // Check the top element after removal
    topElement = fossil_stack_top(stack, (fossil_tofu_t){TOFU_INT_TYPE, {.int_type = -1}});
    TEST_ASSUME_EQUAL_INT(10, topElement.data.int_type);

    fossil_stack_erase(stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_stack_group) {
    XTEST_RUN_UNIT(test_stack_create_and_erase);
    XTEST_RUN_UNIT(test_stack_insert_and_size);
    XTEST_RUN_UNIT(test_stack_remove);
    XTEST_RUN_UNIT(test_stack_top);
} // end of func
