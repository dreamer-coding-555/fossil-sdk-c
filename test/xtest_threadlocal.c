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
#include <fossil/threads/threadlocal.h> // library under test

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

// Test case 1: Test fossil_thread_local_create with valid parameters
XTEST(test_fossil_thread_local_create_valid_params) {
    xthread_local_t key;
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_local_create(&key, NULL));
}

// Test case 2: Test fossil_thread_local_erase with valid parameters
XTEST(test_fossil_thread_local_erase_valid_params) {
    xthread_local_t key;
    fossil_thread_local_create(&key, NULL); // Create a thread-local storage key before erasing it
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_local_erase(key));
}

// Test case 3: Test fossil_thread_local_get with valid parameters
XTEST(test_fossil_thread_local_get_valid_params) {
    xthread_local_t key;
    fossil_thread_local_create(&key, NULL); // Create a thread-local storage key before getting its value
    TEST_ASSUME_CNULLPTR(fossil_thread_local_get(key));
}

// Test case 4: Test fossil_thread_local_set with valid parameters
XTEST(test_fossil_thread_local_set_valid_params) {
    xthread_local_t key;
    int value = 42;
    fossil_thread_local_create(&key, NULL); // Create a thread-local storage key before setting its value
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_local_set(key, &value));
}

// Test case 5: Test fossil_thread_local_set with valid parameters
XTEST(test_fossil_thread_local_set_invalid_params) {
    xthread_local_t key = -1; // Invalid key
    int value = 42;
    TEST_ASSUME_EQUAL_INT32(-1, fossil_thread_local_set(key, &value));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(localthreads_group) {
    XTEST_RUN_UNIT(test_fossil_thread_local_create_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_local_erase_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_local_get_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_local_set_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_local_set_invalid_params);
} // end of fixture
