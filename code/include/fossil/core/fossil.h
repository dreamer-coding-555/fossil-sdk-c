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
#ifndef FOSSIl_CORE_DSL_H
#define FOSSIl_CORE_DSL_H

/**
 * @brief Header file for the Fossil DSL parser.
 * 
 * This header defines the structures and functions used for parsing the Fossil DSL.
 * 
 * The Fossil DSL supports a variety of constructs for defining classes, functions,
 * and other elements typically found in high-level programming languages.
 * 
 * Keywords and symbols supported:
 * - class, fossil, struct, thread, pointer, reference, if, else, else if, for, while,
 *   do while, until, return, pass, public, private, protected, namespace, map, array,
 *   static_cast, ::, ., ->, (, ), ,, {, }
 * 
 * Types and qualifiers supported:
 * - i8, i16, i32, i64, u8, u16, u32, u64, h8, h16, h32, h64, bool, string, letter, tofu,
 *   cnull, unit, cthread, cmutexes, hex, oct, cthread_pool, qpoint, const, async,
 *   static, auto, create, erase, volatile, constexpr, mutable
 * 
 * Example DSL script:
 * 
 * ```fossil
 * namespace MyNamespace {
 *     class HelloWorld {
 *         public:
 *             fossil say_hello() -> unit {
 *                 print("Hello, world!");
 *             }
 *         private:
 *             string message = "Hey, world!";
 *     }
 * }
 * 
 * fossil main() -> unit {
 *     MyNamespace::HelloWorld hw;
 *     hw.say_hello();
 * }
 * ```
 * 
 * - The above example defines a namespace `MyNamespace` containing a class `HelloWorld`.
 * - The `HelloWorld` class has a public function `say_hello` and a private member `message`.
 * - The `main` function creates an instance of `HelloWorld` and calls the `say_hello` function.
 */

/**
 * @brief Determines the type of a token based on its value.
 * 
 * This function takes a token string as input and returns the corresponding
 * token type. It supports a wide variety of keywords and symbols used in the
 * DSL, each with its specific purpose. The recognized token types include:
 * 
 * - **class**: Declares a class.
 * - **fossil**: Declares a function.
 * - **struct**: Declares a structure.
 * - **thread**: Declares a thread.
 * - **pointer** or **\***: Declares a pointer.
 * - **reference** or **@**: Declares a reference.
 * - **if**, **else**, **else if**: Conditional statements.
 * - **for**: Declares a for loop.
 * - **for range**: Declares a range-based for loop.
 * - **while**: Declares a while loop.
 * - **do while**: Declares a do-while loop.
 * - **until**: Declares an until loop.
 * - **return**: Return statement.
 * - **pass**: Pass statement (no operation).
 * - **public**, **private**, **protected**: Access modifiers for class members.
 * - **namespace**: Declares a namespace.
 * - **map<**: Declares a map (associative array).
 * - **array<**: Declares an array.
 * - **static_cast<**: Static cast operator for type casting.
 * - **::**: Namespace scope resolution operator.
 * - **.**: Member access operator.
 * - **->**: Pointer member access operator.
 * - **(**: Open parenthesis.
 * - **)**: Close parenthesis.
 * - **,**: Comma separator.
 * - **{**: Open brace.
 * - **}**: Close brace.
 * - **i8**, **i16**, **i32**, **i64**: Signed integer types.
 * - **u8**, **u16**, **u32**, **u64**: Unsigned integer types.
 * - **h8**, **h16**, **h32**, **h64**: Hexadecimal types.
 * - **bool**: Boolean type.
 * - **string**: String type.
 * - **letter**: Character type.
 * - **tofu**: Generic type.
 * - **cnull**: Null type.
 * - **unit**: Unit type (void).
 * - **cthread**: C thread type.
 * - **cmutexes**: C mutexes type.
 * - **hex**, **oct**: Hexadecimal and octal literals.
 * - **cthread_pool**: Custom thread pool type.
 * - **qpoint**: Fixed point float type.
 * - **const**, **async**, **static**, **auto**, **volatile**, **constexpr**, **mutable**: Various qualifiers and
 *   type modifiers.
 * - **create**, **erase**: Memory management
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Represents different error codes returned by the DSL parser.
 */
typedef enum {
    FOSSIL_DSL_STATUS_NO_ERROR,       /**< Has no error */
    FOSSIL_DSL_STATUS_ERROR,          /**< Has an error */
    FOSSIL_DSL_STATUS_MEMORY_ERROR,   /**< Memory allocation error */
    FOSSIL_DSL_STATUS_SYNTAX_ERROR,   /**< Syntax error in DSL script */
    FOSSIL_DSL_STATUS_UNKNOWN_COMMAND,/**< Unknown command encountered */
    FOSSIL_DSL_STATUS_UNKNOWN_ERROR   /**< Unknown error */
} fossil_dsl_status;

/**
 * @brief Represents the type of a token in the DSL script.
 */
typedef enum {
    TOKEN_TYPE_COMMAND,            /**< Command token */
    TOKEN_TYPE_ARGUMENT,           /**< Argument token */
    TOKEN_TYPE_THREAD,             /**< Thread declaration token */
    TOKEN_TYPE_POINTER,            /**< Pointer declaration token */
    TOKEN_TYPE_IOSTREAM,           /**< IO declaration token */
    TOKEN_TYPE_TYPE,               /**< Type declaration token */
    TOKEN_TYPE_QUALIFIER,          /**< Qualifier declaration token */
    TOKEN_TYPE_CONDITIONAL,        /**< Conditional statement token */
    TOKEN_TYPE_LINK,               /**< Linking directive token */
    TOKEN_TYPE_ACCESS_DOT,         /**< Access operator . token */
    TOKEN_TYPE_ACCESS_POINTER,     /**< Access operator -> token */
    TOKEN_TYPE_IDENTIFIER,         /**< Identifier token */
    TOKEN_TYPE_OPERATOR,           /**< Operator token */
    TOKEN_TYPE_IMPORT,             /**< Import statement token */
    TOKEN_TYPE_RETURN,             /**< Return statement token */
    TOKEN_TYPE_PASS,               /**< Pass statement token */
    TOKEN_TYPE_STATIC_CAST,        /**< Static cast token */
    TOKEN_TYPE_REFERENCE,          /**< Refrence @ token */
    // Token type declarations for types
    TOKEN_TYPE_ARRAY,              /**< Array array<type> token */
    TOKEN_TYPE_MAP,                /**< Map map<type, type> token */
    TOKEN_TYPE_STRING,             /**< String literal token */
    TOKEN_TYPE_NUMBER,             /**< Number literal token */

    // Token type declarations for functions
    TOKEN_TYPE_FUNCTION,           /**< Function declaration token */
    TOKEN_TYPE_OPEN_BRACE,         /**< open brace { token */
    TOKEN_TYPE_CLOSE_BRACE,        /**< open brace } token */
    TOKEN_TYPE_OPEN_PAREN,         /**< Opening parenthesis token */
    TOKEN_TYPE_CLOSE_PAREN,        /**< Closing parenthesis token */
    TOKEN_TYPE_COMMA,              /**< Comma token */
    // Token type declarations for loops
    TOKEN_TYPE_NAMESPACE_OPERATOR, /**< Namespace operator :: token */
    TOKEN_TYPE_NAMESPACE,          /**< Namespace token */
    TOKEN_TYPE_STRUCT,             /**< Struct declaration token */
    TOKEN_TYPE_CLASS,              /**< Class declaration token */
    TOKEN_TYPE_PUBLIC,             /**< Public token */
    TOKEN_TYPE_PROTECTED,          /**< Protected token */
    TOKEN_TYPE_PRIVATE,            /**< Private token */
    // Token type declarations for loops
    TOKEN_TYPE_UNTIL_LOOP,         /**< Until loop token */
    TOKEN_TYPE_DO_WHILE_LOOP,      /**< Do while loop token */
    TOKEN_TYPE_WHILE_LOOP,         /**< While loop token */
    TOKEN_TYPE_FOR_RANGE_LOOP,     /**< Range based loop token */
    TOKEN_TYPE_FOR_LOOP,           /**< For loop token */
    TOKEN_TYPE_UNKNOWN             /**< Unknown token type */
} token_type;

/**
 * @brief Represents a token parsed from the DSL script.
 */
typedef struct {
    token_type type;    /**< Type of the token */
    char *value;        /**< Value of the token */
} fossil_dsl_token;

/**
 * @brief Represents a list of tokens parsed from the DSL script.
 */
typedef struct {
    fossil_dsl_token *tokens; /**< Array of tokens */
    int token_count;    /**< Number of tokens */
} fossil_dsl_tokens;

/**
 * @brief Represents a parsed DSL command.
 */
typedef struct {
    char *command;      /**< Command string */
    char **arguments;   /**< Array of arguments */
    int arg_count;      /**< Number of arguments */
    token_type type;    /**< Type of the command */
} fossil_dsl_command;

/**
 * @brief Represents a DSL parser context.
 */
typedef struct {
    fossil_dsl_command *commands;     /**< Array of parsed commands */
    int command_count;          /**< Number of parsed commands */
    fossil_dsl_status last_error;     /**< Last error encountered */
    char *error_message;        /**< Error message */
} fossil_dsl_parser;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// DSL functions
// =================================================================

/**
 * @brief Sets an error in the parser context.
 * 
 * @param parser Pointer to the parser context.
 * @param error_code Error code to set.
 * @param message Error message.
 */
void fossil_dsl_set_error(fossil_dsl_parser *parser, fossil_dsl_status error_code, const char * restrict message);

/**
 * @brief Creates a new token list.
 * 
 * @return Pointer to the newly created token list.
 */
fossil_dsl_tokens* fossil_dsl_tokens_create(void);

/**
 * @brief Erases a token list.
 * 
 * @param token_list Pointer to the token list to erase.
 */
void fossil_dsl_tokens_erase(fossil_dsl_tokens *token_list);

/**
 * @brief Creates a new parser context.
 * 
 * @return Pointer to the newly created parser context.
 */
fossil_dsl_parser* fossil_dsl_parser_create(void);

/**
 * @brief Erases a parser context.
 * 
 * @param parser Pointer to the parser context to erase.
 */
void fossil_dsl_parser_erase(fossil_dsl_parser *parser);

/**
 * @brief Determines the type of a token based on its value.
 * 
 * @param token The token value.
 * @return The type of the token.
 */
token_type fossil_dsl_get_token_type(const char * restrict token);

/**
 * @brief Tokenizes the DSL script.
 * 
 * @param script The DSL script to tokenize.
 * @param parser Pointer to the parser context.
 * @return Pointer to the token list.
 */
fossil_dsl_tokens* fossil_dsl_tokenize(const char * restrict script, fossil_dsl_parser *parser);

#ifdef __cplusplus
}
#endif

#endif
