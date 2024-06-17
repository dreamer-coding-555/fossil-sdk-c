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
#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts
#include <fossil/common/common.h>

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
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

XTASK(pizza_maker_task, arg) {
    // Making a cool pizza
    (void)arg;
}

// Test case 1: Test fossil_thread_create with valid parameters
FOSSIL_TEST(test_fossil_thread_create_valid_params) {
    fossil_xthread_t thread;
    fossil_xtask_t task = {pizza_maker_task, NULL};

    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_create(&thread, NULL, task));
    fossil_thread_detach(thread); // Detach the thread to clean up resources
}

// Test case 2: Test fossil_thread_join with valid parameters
FOSSIL_TEST(test_fossil_thread_join_valid_params) {
    fossil_xthread_t thread;
    fossil_xtask_t task = {NULL, NULL}; // Initialize task variable
    fossil_thread_create(&thread, NULL, task); // Create a thread before joining it
    fossil_thread_create(&thread, NULL, task); // Create a thread before joining it
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_join(thread, NULL));
}

// Test case 3: Test fossil_thread_attr_create
FOSSIL_TEST(test_fossil_thread_attr_create) {
    fossil_xthread_attr_t attr;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_attr_create(&attr));
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_attr_erase(&attr)); // Clean up after creating thread attributes
}

// Test case 4: Test fossil_thread_attr_erase with valid parameters
FOSSIL_TEST(test_fossil_thread_attr_erase_valid_params) {
    fossil_xthread_attr_t attr;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_attr_create(&attr)); // Create thread attributes before erasing them
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_attr_erase(&attr));
}

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
