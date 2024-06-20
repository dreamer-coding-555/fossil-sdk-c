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
#ifndef FOSSIL_TOOL_ARG_PARSER_H
#define FOSSIL_TOOL_ARG_PARSER_H

/**
 * @brief Functions for parsing command-line arguments and handling options.
 *
 * This file provides functions for printing usage information, checking for specific options,
 * parsing command-line arguments, checking for unrecognized arguments, printing parsed options,
 * resetting parsed flags, and creating arrays of options and combo choices for argument parsing.
 * It facilitates the parsing and handling of command-line arguments with support for various options.
 *
 * Usage:
 *  1. Include "fossil/core/arguments.h" in your source code.
 *  2. Use fossil_arg_parse_usage() to print usage information for command-line argument parsing.
 *  3. Use fossil_arg_parse_has() to check if a specific option is present in the parsed arguments.
 *  4. Use fossil_arg_parse() to parse command-line arguments based on available options.
 *  5. Use fossil_arg_check_unrecognized() to check for unrecognized arguments.
 *  6. Use fossil_arg_print_parsed_options() to print the parsed options along with their values.
 *  7. Use fossil_arg_reset_parsed_flags() to reset the parsed flags of options to their initial state.
 *  8. Use fossil_arg_create_fossil_combo_choice_ts() to create an array of fossil_combo_choice_t structures for combo-box style options.
 *  9. Use fossil_arg_create_options() to create an array of fossil_option_t structures for command-line argument parsing.
 *
 * Example:
 * ```c
 * #include "fossil/core/arguments.h"
 * #include <stdio.h>
 *
 * int main(int argc, char *argv[]) {
 *     // Define options
 *     const char* option_names[] = {"--verbose", "--help", "--output"};
 *     fossil_option_type_t option_types[] = {BOOL_OPTION, BOOL_OPTION, STRING_OPTION};
 *     fossil_option_value_t option_values[] = {0, 0, {"default"}};
 *     void* extra_data[] = {NULL, NULL, NULL};
 *     int num_options = sizeof(option_names) / sizeof(option_names[0]);
 *
 *     // Parse command-line arguments
 *     fossil_command_line_t cmd;
 *     fossil_arg_parse(&cmd, fossil_arg_create_options(option_names, option_types, option_values, extra_data, num_options), num_options);
 *
 *     // Check for specific options
 *     if (fossil_arg_parse_has(&cmd, "--help")) {
 *         fossil_arg_parse_usage(argv[0], fossil_arg_create_options(option_names, option_types, option_values, extra_data, num_options), num_options);
 *         return 0;
 *     }
 *
 *     // Print parsed options
 *     fossil_arg_print_parsed_options(fossil_arg_create_options(option_names, option_types, option_values, extra_data, num_options), num_options);
 *
 *     return 0;
 * }
 * ```
 *
 */

#include "fossil/common/common.h"

// Option types
typedef enum {
    COPTION_TYPE_INT,
    COPTION_TYPE_STRING,
    COPTION_TYPE_BOOL,
    COPTION_TYPE_COMBO,
    COPTION_TYPE_FEATURE
} fossil_option_type_t;

// Feature values
typedef enum {
    FEATURE_ENABLE,
    FEATURE_DISABLE,
    FEATURE_AUTO
} fossil_option_feature_t;

// Combo choice structure
typedef struct {
    const char* name;
    int32_t value;
} fossil_combo_choice_t;

// Option value union
typedef union {
    int32_t int_val;
    char* str_val;
    int32_t bool_val;
    int32_t combo_val;
    fossil_option_feature_t feature_val;
} fossil_option_value_t;

// Option structure
typedef struct {
    const char* name;
    fossil_option_type_t type;
    fossil_option_value_t value;
    void* extra_data; // Used for choices in COPTION_TYPE_COMBO
    int32_t num_choices;  // Used for choices in COPTION_TYPE_COMBO
    int32_t parsed;       // Flag to indicate if the option is parsed
} fossil_option_t;

// Command line structure
typedef struct {
    int argc;
    char** argv;
} fossil_command_line_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Available Functions
// =================================================================

/**
 * Print the usage information for command-line argument parsing.
 *
 * @param program_name The name of the program.
 * @param options      Array of fossil_option_t structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fossil_arg_parse_usage(const char* program_name, fossil_option_t* options, int32_t num_options);

/**
 * Check if a specific option is present in the parsed command-line arguments.
 *
 * @param options      Array of fossil_option_t structures representing available options.
 * @param num_options  The number of options in the array.
 * @param option_name  The name of the option to check for.
 * @return             1 if the option is present, 0 otherwise.
 */
int32_t fossil_arg_parse_has(fossil_option_t* options, int32_t num_options, const char*  option_name);

/**
 * Parse the command-line arguments based on the provided options.
 *
 * @param cmd          Pointer to the fossil_command_line_t structure representing parsed command-line arguments.
 * @param options      Array of fossil_option_t structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fossil_arg_parse(fossil_command_line_t* cmd, fossil_option_t* options, int32_t num_options);

/**
 * Check for unrecognized command-line arguments and print an error message if found.
 *
 * @param cmd          Pointer to the fossil_command_line_t structure representing parsed command-line arguments.
 * @param options      Array of fossil_option_t structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fossil_arg_check_unrecognized(fossil_command_line_t* cmd, fossil_option_t* options, int32_t num_options);

/**
 * Print the parsed options along with their values.
 *
 * @param options      Array of fossil_option_t structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fossil_arg_print_parsed_options(fossil_option_t* options, int32_t num_options);

/**
 * Reset the parsed flags of the options to their initial state.
 *
 * @param options      Array of fossil_option_t structures representing available options.
 * @param num_options  The number of options in the array.
 */
void fossil_arg_reset_parsed_flags(fossil_option_t* options, int32_t num_options);

/**
 * Create an array of fossil_combo_choice_t structures for combo-box style options.
 *
 * @param names        Array of names for the combo choices.
 * @param values       Array of values associated with each choice.
 * @param num_choices  The number of combo choices in the arrays.
 * @return             Pointer to the created array of fossil_combo_choice_t structures.
 */
fossil_combo_choice_t* fossil_arg_create_fossil_combo_choice_ts(const char* names[], const int32_t values[], int32_t num_choices);

/**
 * Create an array of fossil_option_t structures for command-line argument parsing.
 *
 * @param names        Array of names for the options.
 * @param types        Array of fossil_option_type_t indicating the types of the options.
 * @param values       Array of fossil_option_value_t representing default values for the options.
 * @param extra_data   Array of pointers to extra data associated with each option (can be NULL).
 * @param num_options  The number of options in the arrays.
 * @return             Pointer to the created array of fossil_option_t structures.
 */
fossil_option_t* fossil_arg_create_options(const char* names[], fossil_option_type_t types[], fossil_option_value_t values[], void* extra_data[], int32_t num_options);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>
#include <vector>

namespace fossil {

class ArgParser {
public:
    ArgParser(int argc, char* argv[]) : cmd{argc, argv} {}

    void parse_usage(const std::string& program_name, const std::vector<Option>& options) {
        fossil_arg_parse_usage(program_name.c_str(), options.data(), options.size());
    }

    bool has_option(const std::vector<Option>& options, const std::string& option_name) {
        return fossil_arg_parse_has(options.data(), options.size(), option_name.c_str()) != 0;
    }

    void parse(const std::vector<Option>& options) {
        fossil_arg_parse(&cmd, options.data(), options.size());
    }

    void check_unrecognized(const std::vector<Option>& options) {
        fossil_arg_check_unrecognized(&cmd, options.data(), options.size());
    }

    void print_parsed_options(const std::vector<Option>& options) {
        fossil_arg_print_parsed_options(options.data(), options.size());
    }

    void reset_parsed_flags(const std::vector<Option>& options) {
        fossil_arg_reset_parsed_flags(options.data(), options.size());
    }

    std::vector<ComboChoice> create_combo_choices(const std::vector<std::string>& names, const std::vector<int>& values) {
        std::vector<const char*> name_ptrs;
        std::vector<int32_t> value_ints;

        for (const auto& name : names) {
            name_ptrs.push_back(name.c_str());
        }

        for (const auto& value : values) {
            value_ints.push_back(value);
        }

        fossil_combo_choice_t* choices = fossil_arg_create_fossil_combo_choice_ts(name_ptrs.data(), value_ints.data(), name_ptrs.size());

        std::vector<ComboChoice> combo_choices;
        for (size_t i = 0; i < name_ptrs.size(); ++i) {
            combo_choices.push_back({choices[i].name, choices[i].value});
        }

        return combo_choices;
    }

    std::vector<Option> create_options(const std::vector<std::string>& names, const std::vector<OptionType>& types, const std::vector<OptionValue>& values, const std::vector<void*>& extra_data) {
        std::vector<const char*> name_ptrs;
        std::vector<fossil_option_type_t> type_enums;
        std::vector<fossil_option_value_t> value_unions;

        for (const auto& name : names) {
            name_ptrs.push_back(name.c_str());
        }

        for (const auto& type : types) {
            type_enums.push_back(static_cast<fossil_option_type_t>(type));
        }

        for (const auto& value : values) {
            fossil_option_value_t value_union;
            switch (value.index()) {
                case 0:
                    value_union.int_val = std::get<int>(value);
                    break;
                case 1:
                    value_union.str_val = const_cast<char*>(std::get<std::string>(value).c_str());
                    break;
                case 2:
                    value_union.bool_val = std::get<bool>(value);
                    break;
                case 3:
                    value_union.combo_val = std::get<int>(value);
                    break;
                case 4:
                    value_union.feature_val = static_cast<fossil_option_feature_t>(std::get<int>(value));
                    break;
                default:
                    throw std::runtime_error("Invalid option value type");
            }
            value_unions.push_back(value_union);
        }

        fossil_option_t* options = fossil_arg_create_options(name_ptrs.data(), type_enums.data(), value_unions.data(), extra_data.data(), name_ptrs.size());

        std::vector<Option> wrapped_options;
        for (size_t i = 0; i < name_ptrs.size(); ++i) {
            wrapped_options.push_back({options[i].name, static_cast<OptionType>(options[i].type), options[i].value, options[i].extra_data, options[i].num_choices, options[i].parsed});
        }

        return wrapped_options;
    }

private:
    fossil_command_line_t cmd;
};

} // namespace fossil

#endif

#endif
