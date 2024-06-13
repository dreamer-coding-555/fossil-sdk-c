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
#include "fossil/stdtool/smartptr.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

static bool custom_deleter_called = false;

static void custom_deleter(void *ptr) {
    custom_deleter_called = true;
    free(ptr);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

XTEST(test_fossil_smartptr_create_and_get) {
    fossil_smartptr_t sp;
    int *data = malloc(sizeof(int));
    *data = 42;

    ASSUME_ITS_TRUE(fossil_smartptr_create(&sp, data, free));
    ASSUME_ITS_EQUAL_I32(42, *(int *)fossil_smartptr_get(&sp));
    fossil_smartptr_erase(&sp);
}

XTEST(test_fossil_smartptr_acquire_and_erase) {
    fossil_smartptr_t sp;
    int *data = malloc(sizeof(int));
    *data = 42;

    ASSUME_ITS_TRUE(fossil_smartptr_create(&sp, data, free));
    ASSUME_ITS_TRUE(fossil_smartptr_acquire(&sp));
    ASSUME_ITS_EQUAL_I32(42, *(int *)fossil_smartptr_get(&sp));
    
    // Release the smart pointer twice, which should trigger the deleter
    ASSUME_ITS_TRUE(fossil_smartptr_erase(&sp));
    ASSUME_ITS_TRUE(fossil_smartptr_erase(&sp));
}

XTEST(test_fossil_smartptr_null_pointer) {
    fossil_smartptr_t sp;
    ASSUME_ITS_FALSE(fossil_smartptr_create(&sp, NULL, free));
}

XTEST(test_fossil_smartptr_custom_deleter) {
    fossil_smartptr_t sp;
    int *data = malloc(sizeof(int));
    *data = 42;

    ASSUME_ITS_TRUE(fossil_smartptr_create(&sp, data, custom_deleter));
    ASSUME_ITS_EQUAL_I32(42, *(int *)fossil_smartptr_get(&sp));
    ASSUME_ITS_TRUE(fossil_smartptr_erase(&sp));
    ASSUME_ITS_TRUE(custom_deleter_called);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_smartptr_group) {
    ADD_TEST(test_fossil_smartptr_create_and_get);
    ADD_TEST(test_fossil_smartptr_acquire_and_erase);
    ADD_TEST(test_fossil_smartptr_null_pointer);
    ADD_TEST(test_fossil_smartptr_custom_deleter);
} // end of func
