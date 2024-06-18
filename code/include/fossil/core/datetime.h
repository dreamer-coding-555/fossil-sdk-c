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
#ifndef FOSSIl_CORE_DATETIME_H
#define FOSSIl_CORE_DATETIME_H

/**
 * @brief Date and Time Utilities Library
 * 
 * This library provides a comprehensive set of functions for handling date and time operations in C.
 * It includes functions for parsing different time formats, getting and formatting current date and time,
 * and performing calendar-related calculations.
 * 
 * Key Features:
 * - Parse military, 12-hour, and human-readable time strings.
 * - Get and format current date and time in various formats.
 * - Calendar utilities including leap year checks.
 * - Utility functions for date and time manipulation and formatting.
 * 
 * Usage:
 * 
 * 1. Parse different time formats and populate date-time structures:
 *    @code
 *    fossil_datetime_t datetime;
 *    if (fossil_datetime_get_current_parse_military("2359", &datetime) == FOSSIL_DATETIME_STATUS_SUCCESS) {
 *        // Use the parsed date and time
 *    }
 *    @endcode
 * 
 * 2. Get and format current date and time:
 *    @code
 *    fossil_datetime_t datetime;
 *    char buffer[64];
 *    fossil_datetime_get_current(&datetime);
 *    fossil_datetime_get_current_custom(&datetime, buffer, sizeof(buffer));
 *    // buffer now contains the custom formatted date and time
 *    @endcode
 * 
 * 3. Calendar utilities:
 *    @code
 *    if (fossil_datetime_is_leap_year(2024)) {
 *        // 2024 is a leap year
 *    }
 *    @endcode
 *
 */

#include "fossil/common/common.h"

/**
 * Enumeration defining status codes for datetime operations.
 */
enum {
    FOSSIL_DATETIME_STATUS_SUCCESS,  /**< Operation succeeded. */
    FOSSIL_DATETIME_STATUS_FAILURE   /**< Operation failed. */
};

/**
 * Struct representing a datetime object.
 */
typedef struct fossil_datetime_t {
    int32_t year;               /**< Year. */
    int32_t month;              /**< Month. */
    int32_t day;                /**< Day. */
    int32_t hour;               /**< Hour. */
    int32_t minute;             /**< Minute. */
    int32_t second;             /**< Second. */
    int32_t ampm;               /**< AM/PM indicator (for 12-hour format). */
    char timezone[6];           /**< Time zone (e.g., "+0300"). */
} fossil_datetime_t;

/**
 * Struct representing a calendar date.
 */
typedef struct {
    int32_t year;               /**< Year. */
    int32_t month;              /**< Month. */
    int32_t day;                /**< Day. */
} fossil_calendar_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Timestamp functions
// =================================================================

/**
 * Parse a military time string and populate a fossil_datetime_t structure with the current date.
 *
 * @param str      The military time string to be parsed.
 * @param datetime Pointer to a fossil_datetime_t structure to store the parsed date and time.
 * @return         FOSSIL_DATETIME_STATUS_SUCCESS if parsing is successful, FOSSIL_DATETIME_STATUS_FAILURE otherwise.
 */
int32_t fossil_datetime_get_current_parse_military(const char*  str, fossil_datetime_t *datetime);

/**
 * Parse a 12-hour time string and populate a fossil_datetime_t structure with the current date.
 *
 * @param str      The 12-hour time string to be parsed.
 * @param datetime Pointer to a fossil_datetime_t structure to store the parsed date and time.
 * @return         FOSSIL_DATETIME_STATUS_SUCCESS if parsing is successful, FOSSIL_DATETIME_STATUS_FAILURE otherwise.
 */
int32_t fossil_datetime_get_current_parse_12_hour(const char*  str, fossil_datetime_t *datetime);

/**
 * Parse a human-readable time string and populate a fossil_datetime_t structure with the current date.
 *
 * @param str      The human-readable time string to be parsed.
 * @param datetime Pointer to a fossil_datetime_t structure to store the parsed date and time.
 * @return         FOSSIL_DATETIME_STATUS_SUCCESS if parsing is successful, FOSSIL_DATETIME_STATUS_FAILURE otherwise.
 */
int32_t fossil_datetime_get_current_parse_human_readable(const char*  str, fossil_datetime_t *datetime);

/**
 * Get a custom string representation of a fossil_datetime_t structure.
 *
 * @param datetime Pointer to a fossil_datetime_t structure.
 * @param str      Buffer to store the custom string representation.
 * @param max_size Maximum size of the buffer.
 */
void fossil_datetime_get_current_custom(const fossil_datetime_t *datetime, char*  str, size_t max_size);

// =================================================================
// Calander functions
// =================================================================

/**
 * Get the current date in the "YYYY-MM-DD" format from a fossil_calendar_t structure.
 *
 * @param calendar Pointer to a fossil_calendar_t structure.
 * @param str      Buffer to store the formatted date string.
 * @param max_size Maximum size of the buffer.
 */
void fossil_datetime_get_current_calendar_yyyy_mm_dd(const fossil_calendar_t *calendar, char*  str, size_t max_size);

/**
 * Get the current date in the "DD-MM-YYYY" format from a fossil_calendar_t structure.
 *
 * @param calendar Pointer to a fossil_calendar_t structure.
 * @param str      Buffer to store the formatted date string.
 * @param max_size Maximum size of the buffer.
 */
void fossil_datetime_get_current_calendar_dd_mm_yyyy(const fossil_calendar_t *calendar, char*  str, size_t max_size);

/**
 * Get the current date in the "Month DD, YYYY" format from a fossil_calendar_t structure.
 *
 * @param calendar Pointer to a fossil_calendar_t structure.
 * @param str      Buffer to store the formatted date string.
 * @param max_size Maximum size of the buffer.
 */
void fossil_datetime_get_current_calendar_month_dd_yyyy(const fossil_calendar_t *calendar, char*  str, size_t max_size);

/**
 * Check if the given year is a leap year.
 *
 * @param year The year to be checked.
 * @return     FOSSIL_DATETIME_STATUS_SUCCESS if the year is a leap year, FOSSIL_DATETIME_STATUS_FAILURE otherwise.
 */
int32_t fossil_datetime_get_current_is_leap_year(int32_t year);

// =================================================================
// Format utilities
// =================================================================

/**
 * Get the current date and time and populate a fossil_datetime_t structure.
 *
 * @param datetime Pointer to a fossil_datetime_t structure to store the current date and time.
 */
void fossil_datetime_get_current(fossil_datetime_t *datetime);

/**
 * Function to format a fossil_calendar_t object into a string with the format "YYYY-MM-DD".
 */
void fossil_datetime_format_yyyy_mm_dd(const fossil_calendar_t *calendar, char*  str, size_t max_size);

/**
 * Function to format a fossil_calendar_t object into a string with the format "DD/MM/YYYY".
 */
void fossil_datetime_format_dd_mm_yyyy(const fossil_calendar_t *calendar, char*  str, size_t max_size);

/**
 * Function to format a fossil_calendar_t object into a string with the format "Month DD, YYYY".
 */
void fossil_datetime_format_month_dd_yyyy(const fossil_calendar_t *calendar, char*  str, size_t max_size);

/**
 * Function to format a fossil_datetime_t object into a custom string
 */
void fossil_datetime_format_custom(const fossil_datetime_t *datetime, char*  str, size_t max_size);

// =================================================================
// DateTime utilities
// =================================================================

/**
 * Sleep for the specified number of seconds.
 *
 * @param seconds The duration of sleep in seconds.
 */
void fossil_datetime_sleep(uint32_t seconds);

/**
 * Checks if a given year is a leap year.
 */
int32_t fossil_datetime_is_leap_year(int32_t year);

#ifdef __cplusplus
}
#endif

#endif
