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
#ifndef FOSSIl_CORE_BLUECRAB_H
#define FOSSIl_CORE_BLUECRAB_H

/**
 * @brief Blue CrabDB Database Library
 * 
 * This library provides functions to manage a Blue CrabDB database, a lightweight and efficient key-value store.
 * It supports creating databases, managing namespaces, and performing CRUD (Create, Read, Update, Delete) operations on data.
 * 
 * Key Features:
 * - Create and manage databases.
 * - Namespace management within the database.
 * - Insert, update, search, and remove data within namespaces.
 * - Execute custom queries on the database.
 * 
 * Usage:
 * 
 * 1. Creating a database:
 *    @code
 *    fossil_crabdb_t* db = fossil_crabdb_create("my_database");
 *    if (db != NULL) {
 *        // Database created successfully
 *    }
 *    @endcode
 * 
 * 2. Creating a namespace:
 *    @code
 *    int32_t result = fossil_crabdb_create_namespace(db, "my_namespace");
 *    if (result == 1) {
 *        // Namespace created successfully
 *    } else if (result == 0) {
 *        // Namespace already exists
 *    } else {
 *        // Namespace creation failed
 *    }
 *    @endcode
 * 
 * 3. Inserting data:
 *    @code
 *    result = fossil_crabdb_insert_data(db, "my_namespace", "key1", "value1", "string");
 *    if (result == 1) {
 *        // Data inserted successfully
 *    } else if (result == 0) {
 *        // Namespace or key already exists
 *    } else {
 *        // Data insertion failed
 *    }
 *    @endcode
 * 
 * 4. Updating data:
 *    @code
 *    result = fossil_crabdb_update_data(db, "my_namespace", "key1", "new_value");
 *    if (result == 1) {
 *        // Data updated successfully
 *    } else if (result == 0) {
 *        // Namespace or key does not exist
 *    } else {
 *        // Data update failed
 *    }
 *    @endcode
 * 
 * 5. Searching for data:
 *    @code
 *    fson_value* value = fossil_crabdb_search_data(db, "my_namespace", "key1");
 *    if (value != NULL) {
 *        // Data found
 *    } else {
 *        // Data not found
 *    }
 *    @endcode
 * 
 * 6. Removing data:
 *    @code
 *    result = fossil_crabdb_remove_data(db, "my_namespace", "key1");
 *    if (result == 1) {
 *        // Data removed successfully
 *    } else if (result == 0) {
 *        // Namespace or key does not exist
 *    } else {
 *        // Data removal failed
 *    }
 *    @endcode
 * 
 * 7. Displaying namespace contents:
 *    @code
 *    fossil_crabdb_display_namespace(db, "my_namespace");
 *    @endcode
 * 
 * 8. Executing custom queries:
 *    @code
 *    fossil_crabdb_execute_query(db, "SELECT * FROM my_namespace WHERE key='key1'");
 *    @endcode
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "fson.h"

// Blue CrabDB structure
typedef struct {
    char* name; // Name of the database
    fson_namespace* namespaces; // Array of namespaces
    int32_t count; // Number of namespaces
} fossil_crabdb_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Creates a new Blue CrabDB database with a given name.
 * 
 * @param name The name of the database.
 * @return A pointer to the created database.
 */
fossil_crabdb_t* fossil_crabdb_create(const char* name);

/**
 * Releases all resources associated with a Blue CrabDB database.
 * 
 * @param db The database to release.
 */
void fossil_crabdb_erase(fossil_crabdb_t* db);

/**
 * Creates a new namespace in the Blue CrabDB database.
 * 
 * @param db The database to create the namespace in.
 * @param name The name of the namespace to create.
 * @return 1 if the namespace is created successfully, 0 if the namespace already exists, -1 if creation fails.
 */
int32_t fossil_crabdb_create_namespace(fossil_crabdb_t* db, const char* name);

/**
 * Inserts data into a namespace in the Blue CrabDB database.
 * 
 * @param db The database containing the namespace.
 * @param namespace_name The name of the namespace to insert data into.
 * @param key The key of the data to insert.
 * @param value The value of the data to insert.
 * @param type The type of the data to insert.
 * @return 1 if insertion is successful, 0 if the namespace or key already exists, -1 if insertion fails.
 */
int32_t fossil_crabdb_insert_data(fossil_crabdb_t* db, const char* namespace_name, const char* key, const char* value, const char* type);

/**
 * Updates data in a namespace in the Blue CrabDB database.
 * 
 * @param db The database containing the namespace.
 * @param namespace_name The name of the namespace containing the data to update.
 * @param key The key of the data to update.
 * @param value The new value of the data.
 * @return 1 if update is successful, 0 if the namespace or key does not exist, -1 if update fails.
 */
int32_t fossil_crabdb_update_data(fossil_crabdb_t* db, const char* namespace_name, const char* key, const char* value);

/**
 * Removes data from a namespace in the Blue CrabDB database.
 * 
 * @param db The database containing the namespace.
 * @param namespace_name The name of the namespace containing the data to remove.
 * @param key The key of the data to remove.
 * @return 1 if removal is successful, 0 if the namespace or key does not exist, -1 if removal fails.
 */
int32_t fossil_crabdb_remove_data(fossil_crabdb_t* db, const char* namespace_name, const char* key);

/**
 * Searches for data in a namespace in the Blue CrabDB database by its key.
 * 
 * @param db The database containing the namespace.
 * @param namespace_name The name of the namespace to search in.
 * @param key The key of the data to search for.
 * @return A pointer to the found data if it exists, otherwise NULL.
 */
fson_value* fossil_crabdb_search_data(fossil_crabdb_t* db, const char* namespace_name, const char* key);

/**
 * Displays all data within a namespace in the Blue CrabDB database.
 * 
 * @param db The database containing the namespace.
 * @param namespace_name The name of the namespace to display.
 */
void fossil_crabdb_display_namespace(fossil_crabdb_t* db, const char* namespace_name);

/**
 * Executes a query on the Blue CrabDB database and returns the result.
 * 
 * @param db The database to execute the query on.
 * @param query The query string.
 */
void fossil_crabdb_execute_query(fossil_crabdb_t* db, const char* query);

#ifdef __cplusplus
}
#endif

#endif
