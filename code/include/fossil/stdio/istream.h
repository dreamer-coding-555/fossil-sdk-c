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
#ifndef FOSSIL_STDIO_ISTREAM_H
#define FOSSIL_STDIO_ISTREAM_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Get a line of input from the console.
 *
 * @return A dynamically allocated string containing the user input.
 */
char* fossil_console_in_get_line(void);

/**
 * Read a line of input from the console with a prompt.
 *
 * @param prompt The prompt displayed to the user.
 * @return       A dynamically allocated string containing the user input.
 */
char* fossil_console_in_read_line(const char *prompt);

/**
 * Read a password from the console with a prompt, masking input.
 *
 * @param prompt The prompt displayed to the user.
 * @return       A dynamically allocated string containing the user input.
 */
char* fossil_console_in_read_password(const char *prompt);

/**
 * Validate user input using a custom validator function.
 *
 * @param prompt    The prompt displayed to the user.
 * @param validator A function pointer to a custom validator function.
 * @return          True if the input is valid, false otherwise.
 */
int32_t fossil_console_in_valid_input(const char *prompt, bool (*validator)(const char*));

/**
 * Confirm a yes/no question with the user.
 *
 * @param question The question displayed to the user.
 * @return         True if the user confirms with "yes," false otherwise.
 */
int32_t fossil_console_in_confirm_yes_no(const char *question);

/**
 * Display a menu and get the user's selection.
 *
 * @param question    The question or prompt for the menu.
 * @param menu        An array of strings representing menu options.
 * @param num_options The number of options in the menu.
 * @return            The index of the selected option.
 */
int32_t fossil_console_in_confirm_menu(const char *question, const char** menu, int32_t num_options);

/**
 * Display a multi-choice menu and get the user's selections.
 *
 * @param question    The question or prompt for the menu.
 * @param menu        An array of strings representing menu options.
 * @param selections  An array of boolean values indicating user selections.
 * @param num_options The number of options in the menu.
 */
void fossil_console_in_confirm_multi_menu(const char *question, const char** menu, int32_t* selections, int32_t num_options);

/**
 * Confirm if the user wants to exit the program.
 *
 * @return True if the user confirms exit, false otherwise.
 */
int32_t fossil_console_in_confirm_exit(void);

/**
 * Read a date input from the console.
 *
 * @param prompt The prompt displayed to the user.
 * @param year   Pointer to store the entered year.
 * @param month  Pointer to store the entered month.
 * @param day    Pointer to store the entered day.
 * @return       True if the input is valid, false otherwise.
 */
int32_t fossil_console_in_read_date(const char *prompt, int32_t* year, int32_t* month, int32_t* day);

/**
 * Read a time input from the console.
 *
 * @param prompt The prompt displayed to the user.
 * @param hour   Pointer to store the entered hour.
 * @param minute Pointer to store the entered minute.
 * @param second Pointer to store the entered second.
 * @return       True if the input is valid, false otherwise.
 */
int32_t fossil_console_in_read_time(const char *prompt, int32_t* hour, int32_t* minute, int32_t* second);

#ifdef __cplusplus
}
#endif

#endif
