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

// Test case 1: Test fossil_spinlock_create
XTEST(test_fossil_spinlock_create) {
    xspinlock_t lock;
    TEST_ASSUME_EQUAL_INT32(0, fossil_spinlock_create(&lock));
}

// Test case 2: Test fossil_spinlock_erase
XTEST(test_fossil_spinlock_erase) {
    xspinlock_t lock;
    fossil_spinlock_create(&lock); // Initialize the spinlock before erasing it
    TEST_ASSUME_EQUAL_INT32(0, fossil_spinlock_erase(&lock));
}

// Test case 3: Test fossil_spinlock_lock with valid parameters
XTEST(test_fossil_spinlock_lock_valid_params) {
    xspinlock_t lock;
    fossil_spinlock_create(&lock);
    TEST_ASSUME_EQUAL_INT32(0, fossil_spinlock_lock(&lock));
}

// Test case 4: Test fossil_spinlock_unlock with valid parameters
XTEST(test_fossil_spinlock_unlock_valid_params) {
    xspinlock_t lock;
    fossil_spinlock_create(&lock);
    fossil_spinlock_lock(&lock); // Acquire the spinlock before unlocking it
    TEST_ASSUME_EQUAL_INT32(0, fossil_spinlock_unlock(&lock));
}

// Test case 5: Test fossil_spinlock_trylock with valid parameters
XTEST(test_fossil_spinlock_trylock_valid_params) {
    xspinlock_t lock;
    fossil_spinlock_create(&lock);
    TEST_ASSUME_EQUAL_INT32(0, fossil_spinlock_trylock(&lock));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(spinlocks_group) {
    XTEST_RUN_UNIT(test_fossil_spinlock_create);
    XTEST_RUN_UNIT(test_fossil_spinlock_erase);
    XTEST_RUN_UNIT(test_fossil_spinlock_lock_valid_params);
    XTEST_RUN_UNIT(test_fossil_spinlock_unlock_valid_params);
    XTEST_RUN_UNIT(test_fossil_spinlock_trylock_valid_params);
} // end of fixture
