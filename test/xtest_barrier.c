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
#include <fossil/threads/barrier.h> // library under test

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

// Test case 1: Test fossil_barrier_create with a valid count
XTEST(test_fossil_barrier_create_valid_count) {
    xbarrier_t barrier;
    TEST_ASSUME_EQUAL_INT32(0, fossil_barrier_create(&barrier, 5));
}

// Test case 2: Test fossil_barrier_create with an invalid count
XTEST(test_fossil_barrier_create_invalid_count) {
    xbarrier_t barrier;
    TEST_ASSUME_EQUAL_INT32(-1, fossil_barrier_create(&barrier, 0));
}

// Test case 3: Test fossil_barrier_erase after creation
XTEST(test_fossil_barrier_erase_after_create) {
    xbarrier_t barrier;
    fossil_barrier_create(&barrier, 5);
    TEST_ASSUME_EQUAL_INT32(0, fossil_barrier_erase(&barrier));
}

// Test case 4: Test fossil_barrier_erase without creation
XTEST(test_fossil_barrier_erase_without_create) {
    xbarrier_t barrier;
    TEST_ASSUME_EQUAL_INT32(-1, fossil_barrier_erase(&barrier));
}

// Test case 5: Test fossil_barrier_wait with multiple threads
XTEST(test_fossil_barrier_wait_multiple_threads) {
    xbarrier_t barrier;
    fossil_barrier_create(&barrier, 3); // 3 threads required to reach barrier
    // Simulate multiple threads reaching the barrier
    TEST_ASSUME_EQUAL_INT32(0, fossil_barrier_wait(&barrier));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(barrier_group) {
    XTEST_RUN_UNIT(test_fossil_barrier_create_valid_count);
    XTEST_RUN_UNIT(test_fossil_barrier_create_invalid_count);
    XTEST_RUN_UNIT(test_fossil_barrier_erase_after_create);
    XTEST_RUN_UNIT(test_fossil_barrier_erase_without_create);
    XTEST_RUN_UNIT(test_fossil_barrier_wait_multiple_threads);
} // end of fixture
