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
#include "fossil/core/datetime.h"
#include "fossil/common/common.h"
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
char *MONTHS[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


// Function to get the month index from a month name
char* fossil_datetime_get_current_month(int32_t month) {
    if (month >= 1 && month <= 12) {
        return MONTHS[month];
    } else {
        return "Invalid Index";
    }
} // end of func

char* fossil_datetime_get_current_ampm(int32_t hour) {
    if (hour >= 0 && hour <= 11) {
        return "AM";
    } else if (hour >= 12 && hour <= 23) {
        return "PM";
    } else {
        return "Invalid Hour"; // Handle invalid hour values
    }
} // end of func

// Function to parse a DateTime string in 24-hour format (military time)
int32_t fossil_datetime_get_current_parse_military(const char*  str, fossil_datetime_t *datetime) {
    // Error checking for NULL pointers
    if (!str || !datetime) {
        return FOSSIL_DATETIME_STATUS_FAILURE;
    }

    // Parse the string in 24-hour format
    if (sscanf(str, "%d-%d-%d %d:%d:%d %s",
               &datetime->year, &datetime->month, &datetime->day,
               &datetime->hour, &datetime->minute, &datetime->second,
               datetime->timezone) != 7) {
        return FOSSIL_DATETIME_STATUS_FAILURE; // Parsing failed
    }

    return FOSSIL_DATETIME_STATUS_SUCCESS; // Successful parsing
}

// Function to parse a DateTime string in 12-hour format with AM/PM
int32_t fossil_datetime_get_current_parse_12_hour(const char*  str, fossil_datetime_t *datetime) {
    // Error checking for NULL pointers
    if (!str || !datetime) {
        return FOSSIL_DATETIME_STATUS_FAILURE;
    }

    // Parse the string in 12-hour format with AM/PM
    if (sscanf(str, "%d-%d-%d %d:%d:%d %2d %s",
               &datetime->year, &datetime->month, &datetime->day,
               &datetime->hour, &datetime->minute, &datetime->second,
               &datetime->ampm, datetime->timezone) != 8) {
        return FOSSIL_DATETIME_STATUS_FAILURE; // Parsing failed
    }

    return FOSSIL_DATETIME_STATUS_SUCCESS; // Successful parsing
}

// Function to parse a DateTime string in human-readable format
int32_t fossil_datetime_get_current_parse_human_readable(const char*  str, fossil_datetime_t *datetime) {
    // Error checking for NULL pointers
    if (str == cnullptr || datetime == cnullptr) {
        return FOSSIL_DATETIME_STATUS_FAILURE;
    }

    // Parse the string in human-readable format
    if (sscanf(str, "%d-%3s-%d, %d:%d %2s",
               &datetime->year, fossil_datetime_get_current_month(datetime->month),
               &datetime->day, &datetime->hour, &datetime->minute,
               fossil_datetime_get_current_ampm(datetime->ampm)) != 6) {
        return FOSSIL_DATETIME_STATUS_FAILURE; // Parsing failed
    }

    return FOSSIL_DATETIME_STATUS_SUCCESS; // Successful parsing
} // end of func

// Function to format a fossil_datetime_t object into a custom string
void fossil_datetime_format_custom(const fossil_datetime_t *datetime, char*  str, size_t max_size) {
    // Error checking for NULL pointers
    if (!datetime || !str) {
        return;
    }

    // Format the fossil_datetime_t object into a custom string
    snprintf(str, max_size, "%04d-%02d-%02d %02d:%02d:%02d %s",
             datetime->year, datetime->month, datetime->day,
             datetime->hour, datetime->minute, datetime->second,
             datetime->timezone);
}

// Function to get the current date and time
void fossil_datetime_get_current(fossil_datetime_t *datetime) {
    // Error checking for NULL pointer
    if (!datetime) {
        return;
    }

    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    datetime->year = time_info->tm_year + 1900;
    datetime->month = time_info->tm_mon + 1;
    datetime->day = time_info->tm_mday;
    datetime->hour = time_info->tm_hour;
    datetime->minute = time_info->tm_min;
    datetime->second = time_info->tm_sec;
    datetime->ampm = -1; // Not applicable
    // datetime->timezone[0] = '\0';
}

// Function to sleep for the specified number of seconds
void fossil_datetime_sleep(uint32_t seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);  // Sleep takes milliseconds on Windows
#else
    sleep(seconds);
#endif
}

// Formats a fossil_calendar_t object into a string with the format "YYYY-MM-DD".
void fossil_datetime_format_yyyy_mm_dd(const fossil_calendar_t *calendar, char*  str, size_t max_size) {
    // Error checking for NULL pointer and buffer size
    if (!calendar || !str || max_size < 11) {
        return;
    }

    snprintf(str, max_size, "%04d-%02d-%02d", calendar->year, calendar->month, calendar->day);
} // end of func

// Checks if a given year is a leap year.
int32_t fossil_datetime_is_leap_year(int32_t year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
} // end of func
