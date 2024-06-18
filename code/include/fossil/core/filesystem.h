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
#ifndef FOSSIL_TOOL_FILESYSTEM_H
#define FOSSIL_TOOL_FILESYSTEM_H

/**
 * @brief Functions for creating, erasing, listing, and manipulating filesystem objects.
 *
 * This file provides functions for creating, erasing, listing files, creating subdirectories,
 * checking existence, removing files, and changing the current working directory of filesystem objects.
 * It allows for basic manipulation and management of filesystem objects such as directories and files.
 *
 * Usage:
 *  1. Include "fossil/core/filesystem.h" in your source code.
 *  2. Use fossil_filesys_create() to create a filesystem object for a specified path.
 *  3. Use fossil_filesys_erase() to erase a filesystem object.
 *  4. Use fossil_filesys_list_files() to list files in a directory.
 *  5. Use fossil_filesys_create_subdirectory() to create a subdirectory in a parent directory.
 *  6. Use fossil_filesys_exists() to check if a directory or filesystem exists at a specified path.
 *  7. Use fossil_filesys_remove_file() to remove a file from a directory.
 *  8. Use fossil_filesys_change_directory() to change the current working directory of a filesystem object.
 *
 * Example:
 * ```c
 * #include "fossil/core/filesystem.h"
 *
 * int main() {
 *     // Create a filesystem object for a specified path
 *     fossil_filesystem_t directory = fossil_filesys_create("/path/to/directory");
 *
 *     // List files in the directory
 *     fossil_filesys_list_files(&directory);
 *
 *     // Create a subdirectory
 *     fossil_filesys_create_subdirectory(&directory, "subdir");
 *
 *     // Check if directory exists
 *     if (fossil_filesys_exists(&directory)) {
 *         // Change directory
 *         fossil_filesys_change_directory(&directory, "/new/path");
 *     }
 *
 *     // Erase the directory
 *     fossil_filesys_erase(&directory);
 *
 *     return 0;
 * }
 * ```
 *
 */

#include "fossil/common/common.h"

// Structure to represent a directory
typedef struct {
    char* path;
} fossil_filesystem_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalable functions
// =================================================================

/**
 * Create a filesystem object for the specified path.
 *
 * @param path The path for the filesystem.
 * @return     The created filesystem object.
 */
fossil_filesystem_t fossil_filesys_create(const char*  path);

/**
 * Erase a filesystem object.
 *
 * @param directory The filesystem object to be erased.
 */
void fossil_filesys_erase(fossil_filesystem_t* directory);

/**
 * List files in the specified directory.
 *
 * @param directory The directory to list files from.
 */
void fossil_filesys_list_files(const fossil_filesystem_t* directory);

/**
 * Create a subdirectory in the specified parent directory.
 *
 * @param parent            The parent directory.
 * @param subfossil_filesys_name The name of the subdirectory to be created.
 */
void fossil_filesys_create_subdirectory(const fossil_filesystem_t* parent, const char*  subfossil_filesys_name);

/**
 * Check if a directory or filesystem exists at the specified path.
 *
 * @param directory The directory or filesystem to check.
 * @return          1 if it exists, 0 otherwise.
 */
int fossil_filesys_exists(const fossil_filesystem_t* directory);

/**
 * Remove a file from the specified directory.
 *
 * @param directory The directory from which to remove the file.
 * @param filename  The name of the file to be removed.
 */
void fossil_filesys_remove_file(const fossil_filesystem_t* directory, const char*  filename);

/**
 * Change the current working directory of the filesystem object.
 *
 * @param directory The filesystem object to change the directory for.
 * @param new_path  The new path to set as the working directory.
 */
void fossil_filesys_change_directory(fossil_filesystem_t* directory, const char*  new_path);

#ifdef __cplusplus
}
#endif

#endif
