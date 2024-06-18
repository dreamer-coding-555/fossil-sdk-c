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
#ifndef FOSSIl_CORE_FOSSIL_FSON_H
#define FOSSIl_CORE_FOSSIL_FSON_H

/**
 * FSON (Fossil Logic Simple Object Notation) is a lightweight data interchange format inspired by JSON
 * (JavaScript Object Notation) but designed to be language-agnostic. Developed
 * by Fossil Logic, FSON extends the functionality of JSON by introducing additional
 * features while eliminating the dependency on JavaScript, hence making it suitable
 * for a wide range of programming languages and environments.
 * 
 * FSON retains the simplicity and readability of JSON while introducing new concepts
 * such as data types and namespaces to provide more expressive power and flexibility
 * in representing structured data. It allows developers to serialize complex data
 * structures in a human-readable format, facilitating data exchange between different
 * systems and components.
 * 
 * Key Features of FSON:
 * - Simplicity: FSON syntax closely resembles JSON, making it easy to understand
 *   and work with for both humans and machines.
 * - Language-agnostic: FSON does not rely on JavaScript, making it compatible
 *   with a wide range of programming languages and environments.
 * - Data Types: FSON introduces support for specifying data types such as strings,
 *   numbers, boolean values, and null, providing more flexibility in representing
 *   different types of data.
 * - Namespaces: FSON allows data to be organized into logical groups called namespaces,
 *   enabling developers to manage and access related data more efficiently.
 * 
 * FSON is particularly well-suited for applications such as configuration files,
 * data exchange between heterogeneous systems, and serialization of complex data
 * structures in various programming languages.
 * 
 * As a lightweight and versatile data interchange format, FSON simplifies the
 * process of working with structured data, offering a standardized and interoperable
 * solution for data representation and exchange.
 */

/**
 * FSON introduces support for various data types to provide more flexibility in
 * representing different kinds of data. These data types include:
 * 
 * - Strings: Represented by sequences of characters enclosed in single quotes.
 * - Numbers: Represented as integer or floating-point values.
 * - Boolean Values: Represented by the keywords 'true' and 'false'.
 * - Null: Represents a null or empty value.
 * 
 * Additionally, FSON supports extended data types such as:
 * 
 * - Integers of various sizes: Represented by keywords such as 'i8', 'i16', 'i32',
 *   and 'i64' to specify signed integers of 8, 16, 32, and 64 bits respectively.
 * - Unsigned Integers: Represented similarly to signed integers, but with the
 *   prefix 'u' (e.g., 'u8', 'u16').
 * - Octal and Binary Numbers: Represented by keywords such as 'o8', 'o16', 'o32',
 *   and 'o64' for octal numbers and 'b8', 'b16', 'b32', and 'b64' for binary numbers.
 * - Hexadecimal Numbers: Represented by keywords such as 'h8', 'h16', 'h32', and
 *   'h64' for hexadecimal numbers.
 * - Floating-point Numbers: Represented by keywords 'float' and 'double' for
 *   single-precision and double-precision floating-point numbers respectively.
 * 
 * These data types provide developers with the flexibility to represent a wide
 * range of data structures and ensure compatibility across different programming
 * languages and environments.
 */

/**
 * FSON provides a lightweight and human-readable alternative to JSON for
 * representing structured data. Here are a few samples of FSON syntax:
 * 
 * Sample 1:
 * {
 *     'name': {'value': 'John Doe', 'type': 'str'},
 *     'age': {'value': 30, 'type': 'i32'},
 *     'is_student': {'value': true, 'type': 'bool'}
 * }
 * 
 * Sample 2:
 * {
 *     'coordinates': {
 *         'latitude': {'value': 37.7749, 'type': 'double'},
 *         'longitude': {'value': -122.4194, 'type': 'double'}
 *     },
 *     'city': {'value': 'San Francisco', 'type': 'str'}
 * }
 * 
 * Sample 3:
 * {
 *     'colors': ['red', 'green', 'blue'],
 *     'dimensions': {
 *         'width': {'value': 800, 'type': 'i32'},
 *         'height': {'value': 600, 'type': 'i32'}
 *     }
 * }
 * 
 * These samples demonstrate the simplicity and flexibility of FSON syntax,
 * allowing developers to represent various types of data structures with ease.
 */

/**
 * FSON provides a namespace-based structure for organizing data. Here are
 * some namespace samples:
 * 
 * Namespace 1: User Information
 * {
 *     'user': {
 *         'name': {'value': 'John Doe', 'type': 'str'},
 *         'email': {'value': 'johndoe@example.com', 'type': 'str'}
 *     },
 *     'preferences': {
 *         'theme': {'value': 'dark', 'type': 'str'},
 *         'notifications': {'value': true, 'type': 'bool'}
 *     }
 * }
 * 
 * Namespace 2: Geographic Information
 * {
 *     'location': {
 *         'city': {'value': 'New York', 'type': 'str'},
 *         'country': {'value': 'USA', 'type': 'str'}
 *     },
 *     'coordinates': {
 *         'latitude': {'value': 40.7128, 'type': 'double'},
 *         'longitude': {'value': -74.0060, 'type': 'double'}
 *     }
 * }
 * 
 * Namespace 3: Product Information
 * {
 *     'product': {
 *         'name': {'value': 'Smartphone', 'type': 'str'},
 *         'price': {'value': 599.99, 'type': 'double'}
 *     },
 *     'inventory': {
 *         'quantity': {'value': 100, 'type': 'i32'},
 *         'location': {'value': 'Warehouse A', 'type': 'str'}
 *     }
 * }
 * 
 * These namespace samples illustrate how FSON allows developers to organize
 * data into logical groupings, making it easier to manage and access
 * information within complex data structures.
 */

#include "fossil/common/common.h"

// Define token types
typedef enum {
    FOSSIL_FSON_TOKEN_STRING,
    FOSSIL_FSON_TOKEN_NUMBER,
    FOSSIL_FSON_TOKEN_IDENTIFIER,
    FOSSIL_FSON_TOKEN_SYMBOL,
    FOSSIL_FSON_TOKEN_EOF
} fson_token_type;

typedef enum {
    FOSSIL_FSON_TYPE_UNKNOWN = 0,
    FOSSIL_FSON_TYPE_I8,
    FOSSIL_FSON_TYPE_I16,
    FOSSIL_FSON_TYPE_I32,
    FOSSIL_FSON_TYPE_I64,
    FOSSIL_FSON_TYPE_U8,
    FOSSIL_FSON_TYPE_U16,
    FOSSIL_FSON_TYPE_U32,
    FOSSIL_FSON_TYPE_U64,
    FOSSIL_FSON_TYPE_O8,
    FOSSIL_FSON_TYPE_O16,
    FOSSIL_FSON_TYPE_O32,
    FOSSIL_FSON_TYPE_O64,
    FOSSIL_FSON_TYPE_B8,
    FOSSIL_FSON_TYPE_B16,
    FOSSIL_FSON_TYPE_B32,
    FOSSIL_FSON_TYPE_B64,
    FOSSIL_FSON_TYPE_H8,
    FOSSIL_FSON_TYPE_H16,
    FOSSIL_FSON_TYPE_H32,
    FOSSIL_FSON_TYPE_H64,
    FOSSIL_FSON_TYPE_STR,
    FOSSIL_FSON_TYPE_CNULL,
    FOSSIL_FSON_TYPE_FLOAT,
    FOSSIL_FSON_TYPE_DOUBLE,
    FOSSIL_FSON_TYPE_BOOL
} fson_type;

// Define token structure
typedef struct {
    fson_token_type type;
    char* value;
} fson_token;

// Define FSON value structure
typedef struct {
    char* key;
    char* value;
    fson_type type;
} fson_value;

// Define FSON namespace structure
typedef struct {
    char* name;
    fson_value* values;
    int32_t count;
} fson_namespace;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Tokenizes an input XSON string and returns an array of tokens.
 * 
 * @param input The input XSON string to tokenize.
 * @return An array of tokens representing the input XSON string.
 */
fson_token* fossil_fson_tokenize(const char*  input);

/**
 * Frees the memory allocated for an array of tokens.
 * 
 * @param tokens The array of tokens to free.
 */
void fossil_fson_erase_tokens(fson_token* tokens);

/**
 * Finds a value in a namespace by its key.
 * 
 * @param ns The namespace to search in.
 * @param key The key of the value to find.
 * @return A pointer to the value if found, otherwise NULL.
 */
fson_value* fossil_fson_value_find(fson_namespace* ns, const char*  key);

// Namespace-specific functions

/**
 * Parses a namespace from a sequence of tokens.
 * 
 * @param tokens A pointer to a pointer to the tokens representing the namespace.
 * @return A pointer to the parsed namespace, or NULL if parsing fails.
 */
fson_namespace* fossil_fson_namespace_parse(fson_token** tokens);

/**
 * Finds a namespace by its name.
 * 
 * @param namespaces An array of namespaces to search in.
 * @param count The number of namespaces in the array.
 * @param name The name of the namespace to find.
 * @return A pointer to the found namespace, or NULL if not found.
 */
fson_namespace* fossil_fson_namespace_find(fson_namespace* namespaces, int32_t count, const char*  name);

/**
 * Frees the memory allocated for a namespace.
 * 
 * @param ns The namespace to erase.
 */
void fossil_fson_namespace_erase(fson_namespace* ns);

// Data manipulation functions

/**
 * Inserts data into a namespace.
 * 
 * @param namespaces The namespace to insert data into.
 * @param key The key of the data to insert.
 * @param value The value of the data to insert.
 * @param type The type of the data to insert.
 * @return 1 if insertion is successful, -1 if insertion fails.
 */
int32_t fossil_fson_insert_data(fson_namespace* namespaces, const char*  key, const char*  value, const char*  type);

/**
 * Updates data in a namespace.
 * 
 * @param namespaces The namespace containing the data to update.
 * @param key The key of the data to update.
 * @param value The new value of the data.
 * @return 1 if update is successful, -1 if update fails.
 */
int32_t fossil_fson_update_data(fson_namespace* namespaces, const char*  key, const char*  value);

/**
 * Removes data from a namespace.
 * 
 * @param namespaces The namespace containing the data to remove.
 * @param key The key of the data to remove.
 * @return 1 if removal is successful, 0 if key does not exist, -1 if removal fails.
 */
int32_t fossil_fson_remove_data(fson_namespace* namespaces, const char*  key);

/**
 * Searches for data in a namespace by its key.
 * 
 * @param ns The namespace to search in.
 * @param key The key of the data to search for.
 * @return A pointer to the found data if it exists, otherwise NULL.
 */
fson_value* fossil_fson_search_data(fson_namespace* ns, const char*  key);

#ifdef __cplusplus
}
#endif

#endif
