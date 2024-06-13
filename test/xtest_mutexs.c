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

// Test case 1: Test fossil_mutex_create
FOSSIL_TEST(test_fossil_mutex_create) {
    fossil_xmutex_t mutex;
    ASSUME_ITS_EQUAL_I32(0, fossil_mutex_create(&mutex));
}

// Test case 2: Test fossil_mutex_erase
FOSSIL_TEST(test_fossil_mutex_erase) {
    fossil_xmutex_t mutex;
    fossil_mutex_create(&mutex); // Initialize the mutex before erasing it
    ASSUME_ITS_EQUAL_I32(0, fossil_mutex_erase(&mutex));
}

// Test case 3: Test fossil_mutex_lock with valid parameters
FOSSIL_TEST(test_fossil_mutex_lock_valid_params) {
    fossil_xmutex_t mutex;
    fossil_mutex_create(&mutex);
    ASSUME_ITS_EQUAL_I32(0, fossil_mutex_lock(&mutex));
}

// Test case 4: Test fossil_mutex_unlock with valid parameters
FOSSIL_TEST(test_fossil_mutex_unlock_valid_params) {
    fossil_xmutex_t mutex;
    fossil_mutex_create(&mutex);
    fossil_mutex_lock(&mutex); // Lock the mutex before unlocking it
    ASSUME_ITS_EQUAL_I32(0, fossil_mutex_unlock(&mutex));
}

// Test case 5: Test fossil_mutex_trylock with valid parameters
FOSSIL_TEST(test_fossil_mutex_trylock_valid_params) {
    fossil_xmutex_t mutex;
    fossil_mutex_create(&mutex);
    ASSUME_ITS_EQUAL_I32(0, fossil_mutex_trylock(&mutex));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(mutexs_group) {
    ADD_TEST(test_fossil_mutex_create);
    ADD_TEST(test_fossil_mutex_erase);
    ADD_TEST(test_fossil_mutex_lock_valid_params);
    ADD_TEST(test_fossil_mutex_unlock_valid_params);
    ADD_TEST(test_fossil_mutex_trylock_valid_params);
} // end of fixture
