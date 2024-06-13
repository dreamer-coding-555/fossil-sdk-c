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
#include "fossil/stdio/istream.h"
#include "fossil/stdio/ostream.h"
#include "fossil/stdio/soap.h"
#include <fossil/common/common.h>
#include <fossil/common/limits.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#define _GNU_SOURCE // for getline function
#include <termios.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Function to get a line of text from the user.
char* fossil_console_in_get_line(void) {
    static char buffer[FOSSIL_BUFFER_MEDIUM];
    if (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove the trailing newline
        fossil_soap_sanitize(buffer); // Sanitize the input
        return buffer;
    }
    return cnullptr;
}

// Function to read a line of text from the user.
char* fossil_console_in_read_line(const char *prompt) {
    printf("%s: ", prompt);
    return fossil_console_in_get_line();
}

// Function to validate user input with a specific condition.
int32_t fossil_console_in_valid_input(const char *prompt, bool (*validator)(const char*)) {
    while (true) {
        char* input = fossil_console_in_read_line(prompt);
        if (input && validator(input)) {
            return true;
        }
        fossil_console_puts("Invalid input. Please try again.");
    }
}

// Function to confirm a yes/no question.
int32_t fossil_console_in_confirm_yes_no(const char *question) {
    while (true) {
        char* response = fossil_console_in_read_line(question);
        if (response) {
            fossil_soap_sanitize(response); // Sanitize the input
            if (strncmp(response, "yes", strlen("yes")) == 0 || strncmp(response, "y", strlen("y")) == 0) {
                return true;
            } else if (strncmp(response, "no", strlen("no")) == 0 || strncmp(response, "n", strlen("n")) == 0) {
                return false;
            }
            fossil_console_puts("Please answer with 'yes' or 'no'.");
        }
    }
}

// Function to confirm a selection from a menu.
int32_t fossil_console_in_confirm_menu(const char *question, const char** menu, int num_options) {
    fossil_console_out("%s:\n", question);
    for (int i = 0; i < num_options; i++) {
        fossil_console_out("%d. %s\n", i + 1, menu[i]);
    }

    int choice;
    while (true) {
        char* response = fossil_console_in_read_line("Enter your choice");
        if (response && sscanf(response, "%d", &choice) == 1 && choice >= 1 && choice <= num_options) {
            return choice - 1;
        }
        fossil_console_puts("Invalid choice. Please enter a valid option.");
    }
}

// Function to confirm multiple selections from a menu.
void fossil_console_in_confirm_multi_menu(const char *question, const char** menu, int32_t* selections, int32_t num_options) {
    fossil_console_out("%s (Choose options by entering their numbers, separated by spaces):\n", question);
    for (int i = 0; i < num_options; i++) {
        fossil_console_out("%d. %s\n", i + 1, menu[i]);
    }

    char* response = fossil_console_in_read_line("Enter your choices (e.g., '1 3 5')");

    if (response) {
        int choice;
        const char* token = strtok(response, " ");
        while (token != cnullptr) {
            if (sscanf(token, "%d", &choice) == 1 && choice >= 1 && choice <= num_options) {
                selections[choice - 1] = true;
            }
            token = strtok(cnullptr, " ");
        }
    }
}

// Function to confirm an exit action.
int32_t fossil_console_in_confirm_exit(void) {
    return fossil_console_in_confirm_yes_no("Do you want to exit?");
}

// Function to read a date from the user.
int32_t fossil_console_in_read_date(const char *prompt, int32_t* year, int32_t* month, int32_t* day) {
    fossil_console_out("%s", prompt);
    if (scanf("%d-%d-%d", year, month, day) == 3) {
        return true;
    } else {
        // Invalid input
        while (getchar() != '\n');  // Clear the input buffer
        return false;
    }
}

// Function to read a time from the user.
int32_t fossil_console_in_read_time(const char *prompt, int32_t* hour, int32_t* minute, int32_t* second) {
    fossil_console_out("%s", prompt);
    if (scanf("%d:%d:%d", hour, minute, second) == 3) {
        return true;
    } else {
        // Invalid input
        while (getchar() != '\n');  // Clear the input buffer
        return false;
    }
}

// Function to disable echoing for password input
void disable_echo(void) {
#ifdef _WIN32
    system("cls");  // Clear the screen to hide the password
#else
    struct termios term;
    tcgetattr(0, &term);  // Use file descriptor directly
    term.c_lflag &= ~ECHO;
    tfossil_set_tattr(0, TCSANOW, &term);
#endif
}

// Function to enable echoing after password input
void enable_echo(void) {
#ifdef _WIN32
    system("cls");  // Clear the screen to show the next output cleanly
#else
    struct termios term;
    tcgetattr(0, &term);  // Use file descriptor directly
    term.c_lflag |= ECHO;
    tfossil_set_tattr(0, TCSANOW, &term);
#endif
}

// Function to read a password without displaying it
char* fossil_console_in_read_password(const char *prompt) {
    fossil_console_out("%s", prompt);

    disable_echo();

    size_t bufsize = 64;  // Adjust this size as needed
    char* password = malloc(bufsize * sizeof(char));

    if (password == cnullptr) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (fgets(password, bufsize, stdin) == cnullptr) {
        perror("fgets");
        free(password);
        exit(EXIT_FAILURE);
    }

    enable_echo();

    // Remove newline character at the end of the password
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    fossil_soap_sanitize(password); // Sanitize the input

    return password;
}
