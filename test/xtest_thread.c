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
#include <fossil/threads/thread.h> // library under test

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

// Test case 1: Test fossil_thread_create with valid parameters
XTEST(test_fossil_thread_create_valid_params) {
    xthread_t thread;
    xthread_attr_t attr;
    xtask_t task = { .task_func = xnullptr, .arg = xnullptr };
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_create(&thread, &attr, task));
}

// Test case 2: Test fossil_thread_join with valid parameters
XTEST(test_fossil_thread_join_valid_params) {
    xthread_t thread;
    void *retval;
    fossil_thread_create(&thread, xnullptr, (xtask_t){ .task_func = xnullptr, .arg = xnullptr }); // Create a thread before joining it
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_join(thread, &retval));
}

// Test case 3: Test fossil_thread_detach with valid parameters
XTEST(test_fossil_thread_detach_valid_params) {
    xthread_t thread;
    fossil_thread_create(&thread, xnullptr, (xtask_t){ .task_func = xnullptr, .arg = xnullptr }); // Create a thread before detaching it
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_detach(thread));
}

// Test case 4: Test fossil_thread_attr_create
XTEST(test_fossil_thread_attr_create) {
    xthread_attr_t attr;
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_attr_create(&attr));
}

// Test case 5: Test fossil_thread_attr_erase with valid parameters
XTEST(test_fossil_thread_attr_erase_valid_params) {
    xthread_attr_t attr;
    fossil_thread_attr_create(&attr); // Create thread attributes before erasing them
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_attr_erase(&attr));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(threads_group) {
    XTEST_RUN_UNIT(test_fossil_thread_create_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_join_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_detach_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_attr_create);
    XTEST_RUN_UNIT(test_fossil_thread_attr_erase_valid_params);
} // end of fixture
