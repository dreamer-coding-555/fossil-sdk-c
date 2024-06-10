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
#include <fossil/threads/mutexs.h> // library under test

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

// Test case 1: Test fossil_mutex_create
XTEST(test_fossil_mutex_create) {
    xmutex_t mutex;
    TEST_ASSUME_EQUAL_INT32(0, fossil_mutex_create(&mutex));
}

// Test case 2: Test fossil_mutex_erase
XTEST(test_fossil_mutex_erase) {
    xmutex_t mutex;
    fossil_mutex_create(&mutex); // Initialize the mutex before erasing it
    TEST_ASSUME_EQUAL_INT32(0, fossil_mutex_erase(&mutex));
}

// Test case 3: Test fossil_mutex_lock with valid parameters
XTEST(test_fossil_mutex_lock_valid_params) {
    xmutex_t mutex;
    fossil_mutex_create(&mutex);
    TEST_ASSUME_EQUAL_INT32(0, fossil_mutex_lock(&mutex));
}

// Test case 4: Test fossil_mutex_unlock with valid parameters
XTEST(test_fossil_mutex_unlock_valid_params) {
    xmutex_t mutex;
    fossil_mutex_create(&mutex);
    fossil_mutex_lock(&mutex); // Lock the mutex before unlocking it
    TEST_ASSUME_EQUAL_INT32(0, fossil_mutex_unlock(&mutex));
}

// Test case 5: Test fossil_mutex_trylock with valid parameters
XTEST(test_fossil_mutex_trylock_valid_params) {
    xmutex_t mutex;
    fossil_mutex_create(&mutex);
    TEST_ASSUME_EQUAL_INT32(0, fossil_mutex_trylock(&mutex));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(mutexs_group) {
    XTEST_RUN_UNIT(test_fossil_mutex_create);
    XTEST_RUN_UNIT(test_fossil_mutex_erase);
    XTEST_RUN_UNIT(test_fossil_mutex_lock_valid_params);
    XTEST_RUN_UNIT(test_fossil_mutex_unlock_valid_params);
    XTEST_RUN_UNIT(test_fossil_mutex_trylock_valid_params);
} // end of fixture
