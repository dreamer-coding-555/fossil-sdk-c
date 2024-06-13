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
#include "fossil/stdio/fstream.h"
#include <fossil/common/common.h>
#include <fossil/common/status.h>
#include <fossil/common/limits.h>
#include <errno.h>

// Open a stream for file operations
int32_t fossil_fstream_open(fossil_fstream_t *stream, const char *filename, const char *mode) {
    if (stream == cnullptr || filename == cnullptr || mode == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    if (strlen(filename) >= FOSSIL_BUFFER_MEDIUM) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_LIMIT_REACHED));
        return FOSSIL_ERROR_LIMIT_REACHED;
    }

    stream->file = fopen(filename, mode);
    if (stream->file == cnullptr) {
        fprintf(stderr, "%s %s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND), filename);
        return FOSSIL_ERROR_FILE_NOT_FOUND;
    }

    strncpy(stream->filename, filename, FOSSIL_BUFFER_MEDIUM);

    return FOSSIL_ERROR_OK;
}

// Close an open stream
void fossil_fstream_close(fossil_fstream_t *stream) {
    if (stream != cnullptr && stream->file != cnullptr) {
        if (fclose(stream->file) != 0) {
            fprintf(stderr, "%s %s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND), stream->filename);
        }
        stream->file = cnullptr;
    }
}

// Read data from an open stream
size_t fossil_fstream_read(fossil_fstream_t *stream, void *buffer, size_t size, size_t count) {
    if (stream == cnullptr || buffer == cnullptr || stream->file == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    size_t bytes_read = fread(buffer, size, count, stream->file);

    if (bytes_read == 0 && ferror(stream->file)) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_CORRUPTION));
        return FOSSIL_ERROR_FILE_CORRUPTION;
    }

    return bytes_read;
}

// Write data to an open stream
size_t fossil_fstream_write(fossil_fstream_t *stream, const void *buffer, size_t size, size_t count) {
    if (stream == cnullptr || buffer == cnullptr || stream->file == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    size_t bytes_written = fwrite(buffer, size, count, stream->file);

    if (bytes_written == 0 && ferror(stream->file)) {
        fprintf(stderr, "%s %s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND), strerror(errno));
        return FOSSIL_ERROR_FILE_NOT_FOUND;
    }

    return bytes_written;
}

// Append data to the end of an open stream
int32_t fossil_fstream_append(fossil_fstream_t *stream, const void * restrict buffer, size_t size, int32_t count) {
    if (stream == cnullptr || buffer == cnullptr || stream->file == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    fseek(stream->file, 0, SEEK_END);
    int32_t result = fwrite(buffer, size, count, stream->file);

    if (result != count) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND));
        return FOSSIL_ERROR_FILE_NOT_FOUND;
    }

    return FOSSIL_ERROR_OK;
}

// Seek to a specified position in an open stream
int32_t fossil_fstream_seek(fossil_fstream_t *stream, int64_t offset, int32_t origin) {
    if (stream == cnullptr || stream->file == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    int32_t result = fseek(stream->file, offset, origin);

    if (result != 0) {
        fprintf(stderr, "%s %s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND), strerror(errno));
        return FOSSIL_ERROR_FILE_NOT_FOUND;
    }

    return FOSSIL_ERROR_OK;
}

// Save an open stream to a new file
int32_t fossil_fstream_save(fossil_fstream_t *stream, const char *new_filename) {
    if (stream == cnullptr || stream->file == cnullptr || new_filename == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    if (strlen(new_filename) >= FOSSIL_BUFFER_MEDIUM) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_LIMIT_REACHED));
        return FOSSIL_ERROR_LIMIT_REACHED;
    }

    fclose(stream->file);

    if (rename(stream->filename, new_filename) != 0) {
        fprintf(stderr, "%s%s%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER), " failed to save ", new_filename);
        return FOSSIL_ERROR_NULL_POINTER;
    }

    // Reopen the file with the new name
    int32_t result = fossil_fstream_open(stream, new_filename, "r");

    if (result != FOSSIL_ERROR_OK) {
        fprintf(stderr, "%s %s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND), strerror(errno));
        return FOSSIL_ERROR_FILE_NOT_FOUND;
    }
    return result;
}

// Copy a file from the source to the destination
int32_t fossil_fstream_copy(const char *source_filename, const char *destination_filename) {
    if (source_filename == cnullptr || destination_filename == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    FILE *source_file = fopen(source_filename, "rb");
    if (source_file == cnullptr) {
        fprintf(stderr, "%s %s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND), source_filename);
        return FOSSIL_ERROR_FILE_NOT_FOUND;
    }

    FILE *destination_file = fopen(destination_filename, "wb");
    if (destination_file == cnullptr) {
        fprintf(stderr, "%s %s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND), destination_filename);
        fclose(source_file);
        return FOSSIL_ERROR_FILE_NOT_FOUND;
    }

    char buffer[FOSSIL_BUFFER_MEDIUM];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, FOSSIL_BUFFER_MEDIUM, source_file)) > 0) {
        size_t bytesWritten = fwrite(buffer, 1, bytesRead, destination_file);
        if (bytesWritten != bytesRead) {
            fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_FILE_NOT_FOUND));
            fclose(source_file);
            fclose(destination_file);
            return FOSSIL_ERROR_FILE_NOT_FOUND;
        }
    }

    fclose(source_file);
    fclose(destination_file);

    return FOSSIL_ERROR_OK;
}

// Create a backup of a file with a specified backup suffix
int32_t fossil_fstream_backup(const char *filename, const char *backup_suffix) {
    if (filename == cnullptr || backup_suffix == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    char backup_filename[FOSSIL_BUFFER_MEDIUM + 10];  // Length of backup_suffix + maximum integer length
    snprintf(backup_filename, FOSSIL_BUFFER_MEDIUM + 10, "%s%s", filename, backup_suffix);

    if (fossil_fstream_copy(filename, backup_filename) != FOSSIL_ERROR_OK) {
        fprintf(stderr, "%s%s%s\n", fossil_common_error_message(FOSSIL_ERROR_IO), " Failed to create backup for ", filename);
        return FOSSIL_ERROR_IO;
    }

    return FOSSIL_ERROR_OK;
}

// Check if a file exists
int32_t fossil_fstream_file_exists(const char *filename) {
    if (filename == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return FOSSIL_ERROR_FILE_NOT_FOUND;  // File exists
    }
    return FOSSIL_ERROR_OK;  // File does not exist
}

// Get the size of an open stream
int32_t fossil_fstream_get_size(fossil_fstream_t *stream) {
    if (stream == cnullptr || stream->file == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    fseek(stream->file, 0, SEEK_END);
    long size = ftell(stream->file);
    rewind(stream->file);

    if (size == -1L && ferror(stream->file)) {
        fprintf(stderr, "%s%s\n", fossil_common_error_message(FOSSIL_ERROR_IO), " from getting file size");
        return FOSSIL_ERROR_OK;
    }

    return (int32_t)size;
}

// Delete a file
int32_t fossil_fstream_delete(const char *filename) {
    if (filename == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    if (remove(filename) == 0) {
        return FOSSIL_ERROR_OK;  // File deleted successfully
    }

    fprintf(stderr, "%s%s%s\n", fossil_common_error_message(FOSSIL_ERROR_IO), " when deleting file ", filename);
    return FOSSIL_ERROR_IO;
}

// Rename a file or directory
int32_t fossil_fstream_rename(const char *old_filename, const char *new_filename) {
    if (old_filename == cnullptr || new_filename == cnullptr) {
        fprintf(stderr, "%s\n", fossil_common_error_message(FOSSIL_ERROR_NULL_POINTER));
        return FOSSIL_ERROR_NULL_POINTER;
    }

    if (rename(old_filename, new_filename) != 0) {
        fprintf(stderr, "%s%s%s\n", fossil_common_error_message(FOSSIL_ERROR_IO), " Failed to rename file ", old_filename);
        return FOSSIL_ERROR_IO;
    }

    return FOSSIL_ERROR_OK;
}
