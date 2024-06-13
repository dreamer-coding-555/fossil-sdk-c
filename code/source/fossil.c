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
#include "fossil/core/fossil.h"
#include "fossil/common/common.h"

/**
 * @brief Sets an error in the parser context.
 * 
 * @param parser Pointer to the parser context.
 * @param error_code Error code to set.
 * @param message Error message.
 */
void fossil_dsl_set_error(fossil_dsl_parser *parser, fossil_dsl_status error_code, const char * restrict message) {
    parser->last_error = error_code;
    if (parser->error_message != cnull) {
        free(parser->error_message);
    }
    parser->error_message = _custom_fossil_strdup(message);
}

/**
 * @brief Creates a new token list.
 * 
 * @return Pointer to the newly created token list.
 */
fossil_dsl_tokens* fossil_dsl_tokens_create(void) {
    fossil_dsl_tokens *token_list = (fossil_dsl_tokens*)malloc(sizeof(fossil_dsl_tokens));
    if (!token_list) {
        return cnull;
    }
    token_list->tokens = cnull;
    token_list->token_count = 0;
    return token_list;
}

/**
 * @brief Erases a token list.
 * 
 * @param token_list Pointer to the token list to erase.
 */
void fossil_dsl_tokens_erase(fossil_dsl_tokens *token_list) {
    if (token_list) {
        for (int i = 0; i < token_list->token_count; i++) {
            free(token_list->tokens[i].value);
        }
        free(token_list->tokens);
        free(token_list);
    }
}

/**
 * @brief Creates a new parser context.
 * 
 * @return Pointer to the newly created parser context.
 */
fossil_dsl_parser* fossil_dsl_parser_create(void) {
    fossil_dsl_parser *parser = (fossil_dsl_parser*)malloc(sizeof(fossil_dsl_parser));
    if (!parser) {
        return cnull;
    }
    parser->commands = cnull;
    parser->command_count = 0;
    parser->last_error = FOSSIL_DSL_STATUS_NO_ERROR;
    parser->error_message = cnull;
    return parser;
}

/**
 * @brief Erases a parser context.
 * 
 * @param parser Pointer to the parser context to erase.
 */
void fossil_dsl_parser_erase(fossil_dsl_parser *parser) {
    if (parser) {
        if (parser->commands) {
            for (int i = 0; i < parser->command_count; i++) {
                free(parser->commands[i].command);
                for (int j = 0; j < parser->commands[i].arg_count; j++) {
                    free(parser->commands[i].arguments[j]);
                }
                free(parser->commands[i].arguments);
            }
            free(parser->commands);
        }
        if (parser->error_message) {
            free(parser->error_message);
        }
        free(parser);
    }
}

/**
 * @brief Determines the type of a token based on its value.
 * 
 * @param token The token value.
 * @return The type of the token.
 */
token_type fossil_dsl_get_token_type(const char * restrict token) {
    if (strncmp(token, "class", 5) == 0) {
        return TOKEN_TYPE_CLASS;
    } else if (strncmp(token, "fossil", 6) == 0) {
        return TOKEN_TYPE_FUNCTION;
    } else if (strncmp(token, "struct", 6) == 0) {
        return TOKEN_TYPE_STRUCT;
    } else if (strncmp(token, "thread", 6) == 0) {
        return TOKEN_TYPE_THREAD;
    } else if (strncmp(token, "pointer", 7) == 0 || strncmp(token, "*", 1) == 0) {
        return TOKEN_TYPE_POINTER;
    } else if (strncmp(token, "reference", 9) == 0 || strncmp(token, "@", 1) == 0) {
        return TOKEN_TYPE_REFERENCE;
    } else if (strncmp(token, "if", 2) == 0 || strncmp(token, "else", 4) == 0 || strncmp(token, "else if", 7) == 0) {
        return TOKEN_TYPE_CONDITIONAL;
    } else if (strncmp(token, "for", 3) == 0) {
        return TOKEN_TYPE_FOR_LOOP;
    } else if (strncmp(token, "for", 3) == 0 && strncmp(token, "range", 5) == 0) {
        return TOKEN_TYPE_FOR_RANGE_LOOP;
    } else if (strncmp(token, "while", 5) == 0) {
        return TOKEN_TYPE_WHILE_LOOP;
    } else if (strncmp(token, "do", 2) == 0 && strncmp(token, "while", 5) == 0) {
        return TOKEN_TYPE_DO_WHILE_LOOP;
    } else if (strncmp(token, "until", 5) == 0) {
        return TOKEN_TYPE_UNTIL_LOOP;
    } else if (strncmp(token, "return", 6) == 0) {
        return TOKEN_TYPE_RETURN;
    } else if (strncmp(token, "pass", 4) == 0) {
        return TOKEN_TYPE_PASS;
    } else if (strncmp(token, "public", 6) == 0) {
        return TOKEN_TYPE_PUBLIC;
    } else if (strncmp(token, "private", 7) == 0) {
        return TOKEN_TYPE_PRIVATE;
    } else if (strncmp(token, "protected", 9) == 0) {
        return TOKEN_TYPE_PROTECTED;
    } else if (strncmp(token, "namespace", 9) == 0) {
        return TOKEN_TYPE_NAMESPACE;
    } else if (strncmp(token, "map<", 4) == 0) {
        return TOKEN_TYPE_MAP;
    } else if (strncmp(token, "array<", 6) == 0) {
        return TOKEN_TYPE_ARRAY;
    } else if (strncmp(token, "io", 2) == 0) {
        return TOKEN_TYPE_IOSTREAM;
    } else if (strncmp(token, "static_cast<", 12) == 0) {
        return TOKEN_TYPE_STATIC_CAST;
    } else if (strncmp(token, "::", 2) == 0) {
        return TOKEN_TYPE_NAMESPACE_OPERATOR;
    } else if (strncmp(token, ".", 1) == 0) {
        return TOKEN_TYPE_ACCESS_DOT;
    } else if (strncmp(token, "->", 2) == 0) {
        return TOKEN_TYPE_ACCESS_POINTER;
    } else if (strncmp(token, "(", 1) == 0) {
        return TOKEN_TYPE_OPEN_PAREN;
    } else if (strncmp(token, ")", 1) == 0) {
        return TOKEN_TYPE_CLOSE_PAREN;
    } else if (strncmp(token, ",", 1) == 0) {
        return TOKEN_TYPE_COMMA;
    } else if (strncmp(token, "{", 1) == 0) {
        return TOKEN_TYPE_OPEN_BRACE;
    } else if (strncmp(token, "}", 1) == 0) {
        return TOKEN_TYPE_CLOSE_BRACE;
    } else if (strncmp(token, "i8", 2)            == 0 || strncmp(token, "i16", 3)       == 0 ||
               strncmp(token, "i32", 3)           == 0 || strncmp(token, "i64", 3)       == 0 ||
               strncmp(token, "u8", 2)            == 0 || strncmp(token, "u16", 3)       == 0 ||
               strncmp(token, "u32", 3)           == 0 || strncmp(token, "u64", 3)       == 0 ||
               strncmp(token, "h8", 2)            == 0 || strncmp(token, "h16", 3)       == 0 ||
               strncmp(token, "h32", 3)           == 0 || strncmp(token, "h64", 3)       == 0 ||
               strncmp(token, "bool", 4)          == 0 || strncmp(token, "string", 6)    == 0 ||
               strncmp(token, "letter", 6)        == 0 || strncmp(token, "tofu", 4)      == 0 ||
               strncmp(token, "cnull", 5)         == 0 || strncmp(token, "unit", 4)      == 0 ||
               strncmp(token, "cthread", 7)       == 0 || strncmp(token, "cmutexes", 8)  == 0 ||
               strncmp(token, "hex", 3)           == 0 || strncmp(token, "oct", 3)       == 0 ||
               strncmp(token, "cthread_pool", 12) == 0 || strncmp(token, "qpoint", 6)    == 0 ||
               strncmp(token, "const", 5)         == 0 || strncmp(token, "async", 5)     == 0 ||
               strncmp(token, "static", 6)        == 0 || strncmp(token, "auto", 4)      == 0 ||
               strncmp(token, "create", 6)        == 0 || strncmp(token, "erase", 5)     == 0 ||
               strncmp(token, "volatile", 8)      == 0 || strncmp(token, "constexpr", 9) == 0 ||
               strncmp(token, "mutable", 7) == 0) {
        return TOKEN_TYPE_QUALIFIER;
    } else if (isalpha(token[0])) {
        return TOKEN_TYPE_COMMAND;
    } else {
        return TOKEN_TYPE_ARGUMENT;
    }
    return TOKEN_TYPE_UNKNOWN;
}

fossil_dsl_tokens* fossil_dsl_tokenize(const char * restrict script, fossil_dsl_parser *parser) {
    fossil_dsl_tokens *token_list = fossil_dsl_tokens_create();
    if (!token_list) {
        fossil_dsl_set_error(parser, FOSSIL_DSL_STATUS_MEMORY_ERROR, "Failed to allocate memory for token list.");
        return cnull;
    }

    const char *delimiters = " \t\n{}";
    char *script_copy = _custom_fossil_strdup(script);
    if (!script_copy) {
        fossil_dsl_set_error(parser, FOSSIL_DSL_STATUS_MEMORY_ERROR, "Failed to allocate memory for script copy.");
        fossil_dsl_tokens_erase(token_list);
        return cnull;
    }

    char *line = strtok(script_copy, "\n");
    while (line != cnull) {
        // Remove comments (everything after '#')
        char *comment_pos = strchr(line, '#');
        if (comment_pos) {
            *comment_pos = '\0';
        }

        // Tokenize the line
        char *token_str = strtok(line, delimiters);
        while (token_str != cnull) {
            token_type type;
            if (strcmp(token_str, "import") == 0) {
                type = TOKEN_TYPE_IMPORT;
            } else {
                type = fossil_dsl_get_token_type(token_str);
            }

            fossil_dsl_token new_token;
            new_token.type = type;
            new_token.value = _custom_fossil_strdup(token_str);
            if (!new_token.value) {
                fossil_dsl_set_error(parser, FOSSIL_DSL_STATUS_MEMORY_ERROR, "Failed to allocate memory for token value.");
                free(script_copy);
                fossil_dsl_tokens_erase(token_list);
                return cnull;
            }

            token_list->tokens = (fossil_dsl_token*)realloc(token_list->tokens, (token_list->token_count + 1) * sizeof(fossil_dsl_token));
            if (!token_list->tokens) {
                fossil_dsl_set_error(parser, FOSSIL_DSL_STATUS_MEMORY_ERROR, "Failed to reallocate memory for tokens.");
                free(new_token.value);
                free(script_copy);
                fossil_dsl_tokens_erase(token_list);
                return cnull;
            }

            token_list->tokens[token_list->token_count] = new_token;
            token_list->token_count++;
            token_str = strtok(cnull, delimiters);
        }

        line = strtok(cnull, "\n");
    }

    free(script_copy);
    return token_list;
}
