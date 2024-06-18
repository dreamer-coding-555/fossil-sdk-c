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
#ifndef FOSSIL_TOOL_COMMAND_H
#define FOSSIL_TOOL_COMMAND_H

/**
 * @brief Functions for executing commands and handling command results.
 *
 * This file provides functions for executing commands, checking command success,
 * retrieving command output, checking command existence, and safely concatenating strings.
 * It allows for command execution and result handling within C programs.
 *
 * Usage:
 *  1. Include "fossil_command.h" in your source code.
 *  2. Use fossil_command() to execute a command and get the result.
 *  3. Use fossil_command_success() to check if a command execution was successful.
 *  4. Use fossil_command_output() to retrieve the output of a command execution.
 *  5. Use fossil_command_exists() to check if a command exists.
 *  6. Use fossil_command_erase_exists() to erase a command and check if it exists.
 *  7. Use fossil_command_strcat_safe() to safely concatenate two strings into a destination buffer.
 *
 * Example:
 * ```c
 * #include "fossil_command.h"
 * #include <stdio.h>
 *
 * int main() {
 *     // Execute a command
 *     fossil_command_t process = fossil_command("ls -l");
 *     if (fossil_command_success(process)) {
 *         // Retrieve and print command output
 *         char output[1024];
 *         fossil_command_output(process, output, sizeof(output));
 *         printf("Command output: %s\n", output);
 *     } else {
 *         printf("Command execution failed\n");
 *     }
 *     return 0;
 * }
 * ```
 *
 */

#include "fossil/common/common.h"

// Define a typedef for char* to make the code more readable
typedef char* fossil_command_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalable functions
// =================================================================

/**
 * Execute a command and return the result.
 *
 * @param process The command to be executed.
 * @return        The result of the command execution.
 */
int32_t fossil_command(fossil_command_t process);

/**
 * Check if a command execution was successful.
 *
 * @param process The command to be checked.
 * @return        1 if the command was successful, 0 otherwise.
 */
int32_t fossil_command_success(fossil_command_t process);

/**
 * Retrieve the output of a command execution.
 *
 * @param process     The command to retrieve output from.
 * @param output      Buffer to store the output.
 * @param output_size Size of the output buffer.
 * @return            The result of the command execution.
 */
int32_t fossil_command_output(fossil_command_t process, char *restrict output, size_t output_size);

/**
 * Check if a command exists.
 *
 * @param process The command to be checked.
 * @return        1 if the command exists, 0 otherwise.
 */
int32_t fossil_command_exists(fossil_command_t process);

/**
 * Erase a command and check if it exists.
 *
 * @param path The command to be erased.
 * @return     1 if the command exists, 0 otherwise.
 */
int32_t fossil_command_erase_exists(fossil_command_t path);

/**
 * Safely concatenate two strings into a destination buffer.
 *
 * @param dest      The destination buffer for the concatenated strings.
 * @param src       The source string to be concatenated.
 * @param dest_size The size of the destination buffer.
 */
void fossil_command_strcat_safe(char *restrict dest, const char *restrict src, size_t dest_size);

#ifdef __cplusplus
}
#endif

#endif
