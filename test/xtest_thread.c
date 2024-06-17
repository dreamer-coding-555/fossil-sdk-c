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

// Test case 5: Test fossil_thread_attr_create
FOSSIL_TEST(test_fossil_thread_attr_create) {
    fossil_xthread_attr_t attr;
    ASSUME_ITS_EQUAL_I32(0, fossil_thread_attr_create(&attr));
}

// Test case 6: Test fossil_thread_attr_erase with valid parameters
FOSSIL_TEST(test_fossil_thread_attr_erase_valid_params) {
    fossil_xthread_attr_t attr;
    fossil_thread_attr_create(&attr); // Create thread attributes before erasing them
    ASSUME_ITS_EQUAL_I32(0, fossil_thread_attr_erase(&attr));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(threads_group) {
    ADD_TEST(test_fossil_thread_attr_create);
    ADD_TEST(test_fossil_thread_attr_erase_valid_params);
} // end of fixture
