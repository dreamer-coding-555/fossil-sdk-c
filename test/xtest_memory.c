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
#include "fossil/stdtool/memory.h" // lib source code

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

XTEST(test_memory_alloc) {
    size_t size = 10;
    fossil_memory_t ptr = fossil_memory_alloc(size);
    ASSUME_NOT_CNULL(ptr);
    fossil_memory_free(ptr); // Cleanup
}

XTEST(test_memory_realloc) {
    size_t size = 10;
    fossil_memory_t ptr = fossil_memory_alloc(size);
    ASSUME_NOT_CNULL(ptr);

    size *= 2;
    ptr = fossil_memory_realloc(ptr, size);
    ASSUME_NOT_CNULL(ptr);

    fossil_memory_free(ptr); // Cleanup
}

XTEST(test_memory_copy) {
    size_t size = 10;
    int* src = (int*)fossil_memory_alloc(size * sizeof(int));
    ASSUME_NOT_CNULL(src);

    int* dest = (int*)fossil_memory_alloc(size * sizeof(int));
    ASSUME_NOT_CNULL(dest);

    fossil_memory_set(src, 42, size * sizeof(int));
    fossil_memory_copy(dest, src, size * sizeof(int));

    for (size_t i = 0; i < size; i++) {
        ASSUME_ITS_EQUAL_I32(42, dest[i]);
    }

    fossil_memory_free(src); // Cleanup
    fossil_memory_free(dest); // Cleanup
}

XTEST(test_memory_set) {
    size_t size = 10;
    int* ptr = (int*)fossil_memory_alloc(size * sizeof(int));
    ASSUME_NOT_CNULL(ptr);

    fossil_memory_set(ptr, 42, size * sizeof(int));

    for (size_t i = 0; i < size; i++) {
        ASSUME_ITS_EQUAL_I32(42, ptr[i]);
    }

    fossil_memory_free(ptr); // Cleanup
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_memory_group) {
    ADD_TEST(test_memory_alloc);
    ADD_TEST(test_memory_realloc);
    ADD_TEST(test_memory_copy);
    ADD_TEST(test_memory_set);
} // end of function main
