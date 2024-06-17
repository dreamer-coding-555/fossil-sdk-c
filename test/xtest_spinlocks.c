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
#include <fossil/threads/spinlocks.h> // library under test

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

// Test case 1: Test fossil_spinlock_create
FOSSIL_TEST(test_fossil_spinlock_create) {
    fossil_xspinlock_t lock;
    ASSUME_ITS_EQUAL_I32(0, fossil_spinlock_create(&lock));
}

// Test case 2: Test fossil_spinlock_erase
FOSSIL_TEST(test_fossil_spinlock_erase) {
    fossil_xspinlock_t lock;
    fossil_spinlock_create(&lock); // Initialize the spinlock before erasing it
    ASSUME_ITS_EQUAL_I32(0, fossil_spinlock_erase(&lock));
}

// Test case 3: Test fossil_spinlock_lock with valid parameters
FOSSIL_TEST(test_fossil_spinlock_lock_valid_params) {
    fossil_xspinlock_t lock;
    fossil_spinlock_create(&lock);
    ASSUME_ITS_EQUAL_I32(0, fossil_spinlock_lock(&lock));
}

// Test case 4: Test fossil_spinlock_unlock with valid parameters
FOSSIL_TEST(test_fossil_spinlock_unlock_valid_params) {
    fossil_xspinlock_t lock;
    fossil_spinlock_create(&lock);
    fossil_spinlock_lock(&lock); // Acquire the spinlock before unlocking it
    ASSUME_ITS_EQUAL_I32(0, fossil_spinlock_unlock(&lock));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(spinlocks_group) {
    ADD_TEST(test_fossil_spinlock_create);
    ADD_TEST(test_fossil_spinlock_erase);
    ADD_TEST(test_fossil_spinlock_lock_valid_params);
    ADD_TEST(test_fossil_spinlock_unlock_valid_params);
} // end of fixture
