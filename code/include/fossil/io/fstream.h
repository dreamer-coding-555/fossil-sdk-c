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
#ifndef FOSSIL_STDIO_FSTREAM_H
#define FOSSIL_STDIO_FSTREAM_H

#include "fossil/common/common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Structure representing a file stream.
 */
typedef struct {
    FILE *file;                                       // Pointer to the FILE structure for the stream
    char filename[500]; // Array to store the filename
} fossil_fstream_t;

/**
 * Open a stream for file operations.
 *
 * This function opens a file stream, allowing read or write operations on the specified file.
 *
 * @param stream   Pointer to the fossil_fstream_t structure to store the opened stream.
 * @param filename The name of the file to be opened.
 * @param mode     The mode in which to open the file (e.g., "r" for read, "w" for write).
 * @return         0 on success, non-zero on failure.
 */
int32_t fossil_fstream_open(fossil_fstream_t *stream, const char *filename, const char *mode);

/**
 * Close an open stream.
 *
 * This function closes a previously opened stream, releasing associated resources.
 *
 * @param stream Pointer to the fossil_fstream_t structure to be closed.
 */
void fossil_fstream_close(fossil_fstream_t *stream);

/**
 * Read data from an open stream.
 *
 * This function reads data from an open stream into a buffer.
 *
 * @param stream Pointer to the fossil_fstream_t structure from which to read.
 * @param buffer Pointer to the buffer to store the read data.
 * @param size   Size of each element to be read.
 * @param count  Number of elements to read.
 * @return       The total number of elements successfully read.
 */
size_t fossil_fstream_read(fossil_fstream_t *stream, void *buffer, size_t size, size_t count);

/**
 * Write data to an open stream.
 *
 * This function writes data from a buffer to an open stream.
 *
 * @param stream Pointer to the fossil_fstream_t structure to which to write.
 * @param buffer Pointer to the buffer containing the data to be written.
 * @param size   Size of each element to be written.
 * @param count  Number of elements to write.
 * @return       The total number of elements successfully written.
 */
size_t fossil_fstream_write(fossil_fstream_t *stream, const void *buffer, size_t size, size_t count);

/**
 * Append data to the end of an open stream.
 *
 * This function appends data from a buffer to the end of an open stream.
 *
 * @param stream Pointer to the fossil_fstream_t structure to which to append.
 * @param buffer Pointer to the buffer containing the data to be appended.
 * @param size   Size of each element to be appended.
 * @param count  Number of elements to append.
 * @return       0 on success, non-zero on failure.
 */
int32_t fossil_fstream_append(fossil_fstream_t *stream, const void *buffer, size_t size, int32_t count);

/**
 * Seek to a specified position in an open stream.
 *
 * This function moves the file pointer associated with the stream to a new position.
 *
 * @param stream Pointer to the fossil_fstream_t structure to seek.
 * @param offset The offset from the specified origin.
 * @param origin The starting position for the offset (SEEK_SET, SEEK_CUR, SEEK_END).
 * @return       0 on success, non-zero on failure.
 */
int32_t fossil_fstream_seek(fossil_fstream_t *stream, int64_t offset, int32_t origin);

/**
 * Save an open stream to a new file.
 *
 * This function saves the contents of an open stream to a new file.
 *
 * @param stream       Pointer to the fossil_fstream_t structure to be saved.
 * @param new_filename The name of the new file to save to.
 * @return             0 on success, non-zero on failure.
 */
int32_t fossil_fstream_save(fossil_fstream_t *stream, const char *new_filename);

/**
 * Copy a file from the source to the destination.
 *
 * This function copies a file from a source file to a destination file.
 *
 * @param source_filename      The name of the source file.
 * @param destination_filename The name of the destination file.
 * @return                     0 on success, non-zero on failure.
 */
int32_t fossil_fstream_copy(const char *source_filename, const char *destination_filename);

/**
 * Create a backup of a file with a specified backup suffix.
 *
 * This function creates a backup of a file with the given suffix.
 *
 * @param filename      The name of the file to create a backup for.
 * @param backup_suffix The suffix to be appended to the backup file.
 * @return              0 on success, non-zero on failure.
 */
int32_t fossil_fstream_backup(const char *filename, const char *backup_suffix);

/**
 * Check if a file exists.
 *
 * This function checks if a file exists.
 *
 * @param filename The name of the file to check for existence.
 * @return         1 if the file exists, 0 if not.
 */
int32_t fossil_fstream_file_exists(const char *filename);

/**
 * Get the size of an open stream.
 *
 * This function retrieves the size of an open stream.
 *
 * @param stream Pointer to the fossil_fstream_t structure to get the size of.
 * @return       The size of the open stream.
 */
int32_t fossil_fstream_get_size(fossil_fstream_t *stream);

/**
 * Delete a file.
 *
 * This function deletes a file.
 *
 * @param filename The name of the file to be deleted.
 * @return         0 on success, non-zero on failure.
 */
int32_t fossil_fstream_delete(const char *filename);

/**
 * Rename a file or directory.
 *
 * This function renames a file or directory.
 *
 * @param old_filename The current name of the file or directory.
 * @param new_filename The new name to assign to the file or directory.
 * @return             0 on success, non-zero on failure.
 */
int32_t fossil_fstream_rename(const char *old_filename, const char *new_filename);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <stdexcept>

namespace fossil {
/**
 * @brief Class representing a file stream.
 */
class FStream {
public:
    /**
     * @brief Open a stream for file operations.
     *
     * This function opens a file stream, allowing read or write operations on the specified file.
     *
     * @param filename The name of the file to be opened.
     * @param mode     The mode in which to open the file (e.g., "r" for read, "w" for write).
     */
    FStream(const char *filename, const char *mode) {
        if (fossil_fstream_open(&stream_, filename, mode) != 0) {
            throw std::runtime_error("Failed to open file stream");
        }
    }

    /**
     * @brief Close an open stream.
     */
    ~FStream() {
        fossil_fstream_close(&stream_);
    }

    /**
     * @brief Read data from an open stream.
     *
     * This function reads data from an open stream into a buffer.
     *
     * @param buffer Pointer to the buffer to store the read data.
     * @param size   Size of each element to be read.
     * @param count  Number of elements to read.
     * @return       The total number of elements successfully read.
     */
    size_t read(void *buffer, size_t size, size_t count) {
        return fossil_fstream_read(&stream_, buffer, size, count);
    }

    /**
     * @brief Write data to an open stream.
     *
     * This function writes data from a buffer to an open stream.
     *
     * @param buffer Pointer to the buffer containing the data to be written.
     * @param size   Size of each element to be written.
     * @param count  Number of elements to write.
     * @return       The total number of elements successfully written.
     */
    size_t write(const void *buffer, size_t size, size_t count) {
        return fossil_fstream_write(&stream_, buffer, size, count);
    }

    /**
     * @brief Append data to the end of an open stream.
     *
     * This function appends data from a buffer to the end of an open stream.
     *
     * @param buffer Pointer to the buffer containing the data to be appended.
     * @param size   Size of each element to be appended.
     * @param count  Number of elements to append.
     * @return       0 on success, non-zero on failure.
     */
    int32_t append(const void *buffer, size_t size, int32_t count) {
        return fossil_fstream_append(&stream_, buffer, size, count);
    }

    /**
     * @brief Seek to a specified position in an open stream.
     *
     * This function moves the file pointer associated with the stream to a new position.
     *
     * @param offset The offset from the specified origin.
     * @param origin The starting position for the offset (SEEK_SET, SEEK_CUR, SEEK_END).
     * @return       0 on success, non-zero on failure.
     */
    int32_t seek(int64_t offset, int32_t origin) {
        return fossil_fstream_seek(&stream_, offset, origin);
    }

    /**
     * @brief Save an open stream to a new file.
     *
     * This function saves the contents of an open stream to a new file.
     *
     * @param new_filename The name of the new file to save to.
     * @return             0 on success, non-zero on failure.
     */
    int32_t save(const char *new_filename) {
        return fossil_fstream_save(&stream_, new_filename);
    }

    /**
     * @brief Copy a file from the source to the destination.
     *
     * This function copies a file from a source file to a destination file.
     *
     * @param source_filename      The name of the source file.
     * @param destination_filename The name of the destination file.
     * @return                     0 on success, non-zero on failure.
     */
    static int32_t copy(const char *source_filename, const char *destination_filename) {
        return fossil_fstream_copy(source_filename, destination_filename);
    }

    /**
     * @brief Create a backup of a file with a specified backup suffix.
     *
     * This function creates a backup of a file with the given suffix.
     *
     * @param filename      The name of the file to create a backup for.
     * @param backup_suffix The suffix to be appended to the backup file.
     * @return              0 on success, non-zero on failure.
     */
    static int32_t backup(const char *filename, const char *backup_suffix) {
        return fossil_fstream_backup(filename, backup_suffix);
    }

    /**
     * @brief Check if a file exists.
     *
     * This function checks if a file exists.
     *
     * @param filename The name of the file to check for existence.
     * @return         1 if the file exists, 0 if not.
     */
    static int32_t file_exists(const char *filename) {
        return fossil_fstream_file_exists(filename);
    }

    /**
     * @brief Get the size of an open stream.
     *
     * This function retrieves the size of an open stream.
     *
     * @return The size of the open stream.
     */
    int32_t get_size() {
        return fossil_fstream_get_size(&stream_);
    }

    /**
     * @brief Delete a file.
     *
     * This function deletes a file.
     *
     * @param filename The name of the file to be deleted.
     * @return         0 on success, non-zero on failure.
     */
    static int32_t delete_file(const char *filename) {
        return fossil_fstream_delete(filename);
    }

    /**
     * @brief Rename a file or directory.
     *
     * This function renames a file or directory.
     *
     * @param old_filename The current name of the file or directory.
     * @param new_filename The new name to assign to the file or directory.
     * @return             0 on success, non-zero on failure.
     */
    static int32_t rename(const char *old_filename, const char *new_filename) {
        return fossil_fstream_rename(old_filename, new_filename);
    }

private:
    fossil_fstream_t stream_;
};
} // namespace fossil

#endif

#endif
