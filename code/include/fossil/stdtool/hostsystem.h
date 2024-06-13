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
#ifndef FOSSIL_TOOL_HOSTSYSTEM_H
#define FOSSIL_TOOL_HOSTSYSTEM_H

/**
 * @brief Functions for retrieving and printing system information.
 *
 * This file provides functions for retrieving and printing various system information,
 * including operating system details, CPU information, memory usage, and endianness.
 * It includes functions to retrieve system information and print it to standard output,
 * as well as a function to determine the endianness of the system.
 *
 * Usage:
 *  1. Include "fossil/stdtool/hostsystem.h" in your source code.
 *  2. Use fossil_hostsys_get() to retrieve system information and store it in a fossil_hostsystem_t structure.
 *  3. Use fossil_hostsys_print() to print the retrieved system information to the standard output.
 *  4. Use fossil_hostsys_endian() to determine the endianness of the system.
 *
 * Example:
 * ```c
 * #include "fossil/stdtool/hostsystem.h"
 * #include <stdio.h>
 *
 * int main() {
 *     fossil_hostsystem_t info;
 *     if (fossil_hostsys_get(&info)) {
 *         fossil_hostsys_print(&info);
 *         printf("Endianness: %s\n", fossil_hostsys_endian(&info));
 *     } else {
 *         fprintf(stderr, "Failed to retrieve system information\n");
 *     }
 *     return 0;
 * }
 * ```
 *
 */


#include <stdint.h>
#include <fossil/common/common.h>

enum {
    _FOSSIL_HOSTSYS_SIZE = 256
};

// Structure to represent a host system
typedef struct {
    char os_name[_FOSSIL_HOSTSYS_SIZE];
    char os_version[_FOSSIL_HOSTSYS_SIZE];
    char cpu_model[_FOSSIL_HOSTSYS_SIZE];
    int32_t cpu_cores;
    int64_t total_memory;
    int64_t free_memory;
    fossil_bool_t is_big_endian;
} fossil_hostsystem_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalable functions
// =================================================================

/**
 * @brief Retrieves the system information and stores it in the provided fossil_hostsystem_t structure.
 * 
 * This function retrieves various system information such as the operating system name,
 * version, CPU model, number of CPU cores, total memory, and free memory. The information
 * is stored in the provided fossil_hostsystem_t structure.
 * 
 * @param info Pointer to the fossil_hostsystem_t structure where the system information will be stored.
 * @return Returns true if the system information was successfully retrieved, otherwise false.
 */
fossil_bool_t fossil_hostsys_get(fossil_hostsystem_t *info);

/**
 * @brief Prints the system information to the standard output.
 * 
 * This function prints the retrieved system information to the standard output,
 * including the operating system name, version, CPU model, number of CPU cores,
 * total memory, free memory, and endianness.
 * 
 * @param info Pointer to the fossil_hostsystem_t structure containing the system information.
 */
void fossil_hostsys_print(fossil_hostsystem_t *info);

/**
 * @brief Returns a string indicating the endianness of the system.
 * 
 * This function checks the endianness of the system and returns a string indicating
 * whether the system is big endian or little endian.
 * 
 * @param info Pointer to the fossil_hostsystem_t structure containing the system information.
 * @return Returns a string "Big Endian" if the system is big endian, otherwise "Little Endian".
 */
const char* fossil_hostsys_endian(fossil_hostsystem_t *info);

#ifdef __cplusplus
}
#endif

#endif
