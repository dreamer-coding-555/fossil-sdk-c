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
#include <fossil/threads.h> // library under test

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_thread_fixture);
FOSSIL_SETUP(c_thread_fixture) {
    // Setup code goes here
}

FOSSIL_TEARDOWN(c_thread_fixture) {
    // Teardown code goes here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Start: Fossil Threads Fixture
// * * * * * * * * * * * * * * * * * * * * * * * *

XTASK(pizza_maker_task, arg_name) {
    // Making a cool pizza
    (void)arg_name;
}

// Test case 1: Test fossil_thread_create with valid parameters
FOSSIL_TEST(test_fossil_thread_create_valid_params) {
    fossil_xthread_t thread;
    fossil_xtask_t task = (fossil_xtask_t){pizza_maker_task, xnull};

    ASSUME_ITS_EQUAL_I32(0, fossil_thread_create(&thread, xnullptr, task));
    fossil_thread_detach(thread);
}

// Test case 2: Test fossil_thread_join with valid parameters
FOSSIL_TEST(test_fossil_thread_join_valid_params) {
    fossil_xthread_t thread;
    fossil_xtask_t task = (fossil_xtask_t){pizza_maker_task, xnull}; // Initialize task variable
    fossil_thread_create(&thread, xnullptr, task); // Create a thread before joining it
    ASSUME_ITS_EQUAL_I32(0, fossil_thread_join(thread, xnullptr));
    fossil_thread_detach(thread);
}

// Test case 5: Test fossil_thread_attr_create
FOSSIL_TEST(test_fossil_thread_attr_create) {
    fossil_xthread_attr_t attr;
    ASSUME_ITS_EQUAL_I32(0, fossil_thread_attr_create(&attr));
    fossil_thread_attr_erase(&attr); // Clean up after creating thread attributes
}

// Test case 6: Test fossil_thread_attr_erase with valid parameters
FOSSIL_TEST(test_fossil_thread_attr_erase_valid_params) {
    fossil_xthread_attr_t attr;
    fossil_thread_attr_create(&attr); // Create thread attributes before erasing them
    ASSUME_ITS_EQUAL_I32(0, fossil_thread_attr_erase(&attr));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * End: Fossil Threads Fixture
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_threaded_tests) {
    // Threads Fixture
    ADD_TESTF(test_fossil_thread_create_valid_params, c_thread_fixture);
    ADD_TESTF(test_fossil_thread_join_valid_params, c_thread_fixture);
    ADD_TESTF(test_fossil_thread_attr_create, c_thread_fixture);
    ADD_TESTF(test_fossil_thread_attr_erase_valid_params, c_thread_fixture);
} // end of fixture
