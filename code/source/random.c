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
#include "fossil/stdtool/random.h"
#include "fossil/common/common.h"
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#include <process.h>
#include <windows.h>
#define getpid _getpid
#else
#include <unistd.h>
#include <sys/time.h>
#endif

// Function to initialize the seed
void fossil_random_seed(fossil_random_t* rng, uint32_t seed) {
    rng->current_seed = seed;
}

// Internal function to generate the next random number using bitwise and xor operations
static uint32_t fossil_random_next(fossil_random_t* rng) {
    rng->current_seed ^= rng->current_seed << 13;
    rng->current_seed ^= rng->current_seed >> 17;
    rng->current_seed ^= rng->current_seed << 5;
    uint32_t result = rng->current_seed;
    return result;
}

// Function to generate a random 8-bit unsigned integer
uint8_t fossil_random_uint8(fossil_random_t* rng) {
    return (uint8_t)(fossil_random_next(rng) & 0xFF);
}

// Function to generate a random 16-bit unsigned integer
uint16_t fossil_random_uint16(fossil_random_t* rng) {
    return (uint16_t)(fossil_random_next(rng) & 0xFFFF);
}

// Function to generate a random 32-bit unsigned integer
uint32_t fossil_random_uint32(fossil_random_t* rng) {
    return fossil_random_next(rng);
}

// Function to generate a random 64-bit unsigned integer
uint64_t fossil_random_uint64(fossil_random_t* rng) {
    uint64_t high = (uint64_t)fossil_random_next(rng);
    uint64_t low = (uint64_t)fossil_random_next(rng);
    return (high << 32) | low;
}

// Function to generate a random integer within a range
int32_t fossil_random_int_range(fossil_random_t* rng, int32_t min, int32_t max) {
    if (min > max) {
        // Swap min and max if min is greater than max
        int temp = min;
        min = max;
        max = temp;
    }
    return min + (fossil_random_next(rng) % (max - min + 1));
}

// Function to generate a random float between 0 and 1
float fossil_random_float(fossil_random_t* rng) {
    // Generate a random 32-bit number
    uint32_t random_uint = fossil_random_next(rng);
    // Convert to a float between 0 and 1 using division by UINT32_MAX + 1
    return (random_uint / (float)(UINT32_MAX + 1.0));
}

// Function to generate a random double between 0 and 1
double fossil_random_double(fossil_random_t* rng) {
    // Generate a random 32-bit number
    uint32_t random_uint = fossil_random_next(rng);
    // Convert to a double between 0 and 1 using division by UINT32_MAX + 1
    return (random_uint / (double)(UINT32_MAX + 1.0));
}

// Function to generate a random hexadecimal number with a specific number of bits
uint32_t fossil_random_hex(fossil_random_t* rng, int32_t num_bits) {
    return fossil_random_next(rng) & ((1 << num_bits) - 1);
}

// Function to generate a random octal number with a specific number of bits
uint32_t fossil_random_oct(fossil_random_t* rng, int32_t num_bits) {
    return fossil_random_next(rng) & ((1 << num_bits) - 1);
}

// Function to generate a random binary number with a specific number of bits
uint32_t fossil_random_binary(fossil_random_t* rng, int32_t num_bits) {
    return fossil_random_next(rng) & ((1 << num_bits) - 1);
}

// Function to yield a seed value
uint32_t fossil_random_yield_seed(void) {
    // Combine time, process ID, and additional entropy sources to generate a seed
    uint32_t time_seed = (uint32_t)time(cnullptr);
    uint32_t pid_seed = (uint32_t)getpid();

    // Additional entropy source from high-resolution timer
    uint32_t high_res_time_seed;
#if defined(_WIN32) || defined(_WIN64)
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    high_res_time_seed = (uint32_t)((counter.QuadPart * 1000000) / freq.QuadPart);
#else
    struct timeval tv;
    gettimeofday(&tv, cnullptr);
    high_res_time_seed = (uint32_t)(tv.tv_sec * 1000000 + tv.tv_usec);
#endif

    // Additional entropy source from clock cycles
    uint32_t clock_seed = (uint32_t)clock();

    // Use XOR to combine the seeds
    return time_seed ^ pid_seed ^ high_res_time_seed ^ clock_seed;
}
