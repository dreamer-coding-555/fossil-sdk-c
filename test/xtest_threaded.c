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

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test classic threads
// * * * * * * * * * * * * * * * * * * * * * * * *

XTASK(pizza_maker_task, arg) {
    // Making a cool pizza
    (void)arg;
}

FOSSIL_FIXTURE(c_thread_fixture);
FOSSIL_SETUP(c_thread_fixture) {
    // Setup code goes here
}

FOSSIL_TEARDOWN(c_thread_fixture) {
    // Teardown code goes here
}

// Test case 1: Test fossil_thread_create with valid parameters
FOSSIL_TEST(testing_thread_create) {
    fossil_xthread_t thread;
    fossil_xtask_t task = {pizza_maker_task, NULL};

    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_create(&thread, NULL, task));
    fossil_thread_detach(thread); // Detach the thread to clean up resources
}

// Test case 2: Test fossil_thread_attr_create
FOSSIL_TEST(testing_thread_attr_create) {
    fossil_xthread_attr_t attr;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_attr_create(&attr));
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_attr_erase(&attr)); // Clean up after creating thread attributes
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test thread-local
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test case: Thread-local storage with destructor
XTASK(dummy_destructor, value) {
    // Dummy destructor function for testing
    free(value);
}

// Test fixture for thread-local storage
FOSSIL_FIXTURE(c_thread_local_fixture);
FOSSIL_SETUP(c_thread_local_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_thread_local_fixture) {
    // Teardown code if needed
}

// Test case: Create and erase thread-local storage key
FOSSIL_TEST(test_fossil_thread_local_create_erase) {
    fossil_xthread_local_t key;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_create(&key, NULL));
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_erase(key));
}

// Test case: Set and get thread-local storage value
FOSSIL_TEST(test_fossil_thread_local_set_get) {
    fossil_xthread_local_t key;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_create(&key, NULL));
    
    const char *value = "test_value";
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_set(key, value));
    
    const char *retrieved_value = (const char*)fossil_thread_local_get(key);
    ASSUME_ITS_EQUAL_S(value, retrieved_value);
    
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_erase(key));
}

FOSSIL_TEST(test_fossil_thread_local_with_destructor) {
    fossil_xthread_local_t key;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_create(&key, dummy_destructor));
    
    char *value = malloc(20);
    strcpy(value, "test_value_with_destructor");
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_set(key, value));
    
    const char *retrieved_value = (const char*)fossil_thread_local_get(key);
    ASSUME_ITS_EQUAL_S(value, retrieved_value);
    
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_thread_local_erase(key));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_threaded_tests) {
    // Threads Fixture
    ADD_TESTF(testing_thread_create, c_thread_fixture);
    ADD_TESTF(testing_thread_attr_create, c_thread_fixture);
    
    // Local Threads Fixture
    ADD_TESTF(test_fossil_thread_local_create_erase, c_thread_local_fixture);
    ADD_TESTF(test_fossil_thread_local_set_get, c_thread_local_fixture);
    ADD_TESTF(test_fossil_thread_local_with_destructor, c_thread_local_fixture);
} // end of fixture
