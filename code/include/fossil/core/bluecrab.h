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
 * @brief Blue fossil_crabdb_t Database Library
 * 
 * This library provides functions to manage a Blue fossil_crabdb_t database, a lightweight and efficient key-value store.
 * It supports creating databases, managing namespaces, and performing CRUD (Create, Read, Update, Delete) operations on data.
 * 
 * Key Features:
 * - Create and manage databases.
 * - fossil_crabdb_namespace_t management within the database.
 * - Insert, update, search, and remove data within namespaces.
 * - Execute custom queries on the database.
 * 
 * Usage:
 * 
 * 1. Creating a database:
 *    @code
 *    fossil_crabdb_t_t* db = fossil_crabdb_create("my_database");
 *    if (db != NULL) {
 *        // Database created successfully
 *    }
 *    @endcode
 * 
 * 2. Creating a namespace:
 *    @code
 *    int32_t result = fossil_crabdb_create_namespace(db, "my_namespace");
 *    if (result == 1) {
 *        // fossil_crabdb_namespace_t created successfully
 *    } else if (result == 0) {
 *        // fossil_crabdb_namespace_t already exists
 *    } else {
 *        // fossil_crabdb_namespace_t creation failed
 *    }
 *    @endcode
 * 
 * 3. Inserting data:
 *    @code
 *    result = fossil_crabdb_insert_data(db, "my_namespace", "key1", "value1", "string");
 *    if (result == 1) {
 *        // Data inserted successfully
 *    } else if (result == 0) {
 *        // fossil_crabdb_namespace_t or key already exists
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
 *        // fossil_crabdb_namespace_t or key does not exist
 *    } else {
 *        // Data update failed
 *    }
 *    @endcode
 * 
 * 5. Searching for data:
 *    @code
 *    fson_value* value = fossil_crabdb_t_search_data(db, "my_namespace", "key1");
 *    if (value != NULL) {
 *        // Data found
 *    } else {
 *        // Data not found
 *    }
 *    @endcode
 * 
 * 6. Removing data:
 *    @code
 *    result = fossil_crabdb_t_remove_data(db, "my_namespace", "key1");
 *    if (result == 1) {
 *        // Data removed successfully
 *    } else if (result == 0) {
 *        // fossil_crabdb_namespace_t or key does not exist
 *    } else {
 *        // Data removal failed
 *    }
 *    @endcode
 * 
 * 7. Displaying namespace contents:
 *    @code
 *    fossil_crabdb_t_display_namespace(db, "my_namespace");
 *    @endcode
 * 
 * 8. Executing custom queries:
 *    @code
 *    fossil_crabdb_execute_query(db, "SELECT * FROM my_namespace WHERE key='key1'");
 *    @endcode
 * 
 */

#include "fossil/common/common.h"

#ifdef __cplusplus
extern "C" {
#endif

// Error codes
typedef enum {
    CRABDB_OK = 0, /**< Operation completed successfully */
    CRABDB_ERR_MEM, /**< Memory allocation error */
    CRABDB_ERR_NS_NOT_FOUND, /**< Namespace not found */
    CRABDB_ERR_NS_EXISTS, /**< Namespace already exists */
    CRABDB_ERR_SUB_NS_NOT_FOUND, /**< Sub-namespace not found */
    CRABDB_ERR_SUB_NS_EXISTS, /**< Sub-namespace already exists */
    CRABDB_ERR_KEY_NOT_FOUND, /**< Key not found */
    CRABDB_ERR_INVALID_QUERY /**< Invalid query */
} fossil_crabdb_error_t;

typedef struct fossil_crabdb_keyvalue_t {
    char *key; /**< Key of the key-value pair */
    char *value; /**< Value of the key-value pair */
    struct fossil_crabdb_keyvalue_t *next; /**< Pointer to the next key-value pair */
} fossil_crabdb_keyvalue_t;

typedef struct fossil_crabdb_namespace_t {
    char *name; /**< Name of the namespace */
    struct fossil_crabdb_namespace_t *sub_namespaces; /**< Pointer to the sub-namespaces */
    size_t sub_namespace_count; /**< Number of sub-namespaces */
    struct fossil_crabdb_namespace_t *next; /**< Pointer to the next namespace */
    fossil_crabdb_keyvalue_t *data; /**< Linked list of key-value pairs */
} fossil_crabdb_namespace_t;

typedef struct {
    fossil_crabdb_namespace_t *namespaces; /**< Pointer to the namespaces */
} fossil_crabdb_t;

/**
 * @brief Create a new fossil_crabdb_t database.
 * 
 * @return Pointer to the newly created fossil_crabdb_t database.
 */
fossil_crabdb_t* fossil_crabdb_create();

/**
 * @brief Erase the fossil_crabdb_t database.
 * 
 * @param db Pointer to the fossil_crabdb_t database to erase.
 */
void fossil_crabdb_erase(fossil_crabdb_t *db);

/**
 * @brief Create a new namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the new namespace.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_create_namespace(fossil_crabdb_t *db, const char *namespace_name);

/**
 * @brief Create a new sub-namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the parent namespace.
 * @param sub_namespace_name Name of the new sub-namespace.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_create_sub_namespace(fossil_crabdb_t *db, const char *namespace_name, const char *sub_namespace_name);

/**
 * @brief Erase a namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the namespace to erase.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_erase_namespace(fossil_crabdb_t *db, const char *namespace_name);

/**
 * @brief Erase a sub-namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the parent namespace.
 * @param sub_namespace_name Name of the sub-namespace to erase.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_erase_sub_namespace(fossil_crabdb_t *db, const char *namespace_name, const char *sub_namespace_name);

/**
 * @brief Insert data into a namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the namespace.
 * @param key Key of the data to insert.
 * @param value Value of the data to insert.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_insert(fossil_crabdb_t *db, const char *namespace_name, const char *key, const char *value);

/**
 * @brief Get data from a namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the namespace.
 * @param key Key of the data to get.
 * @param value Pointer to store the retrieved value.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_get(fossil_crabdb_t *db, const char *namespace_name, const char *key, char **value);

/**
 * @brief Update data in a namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the namespace.
 * @param key Key of the data to update.
 * @param value New value for the data.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_update(fossil_crabdb_t *db, const char *namespace_name, const char *key, const char *value);

/**
 * @brief Delete data from a namespace.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param namespace_name Name of the namespace.
 * @param key Key of the data to delete.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_delete(fossil_crabdb_t *db, const char *namespace_name, const char *key);

/**
 * @brief Execute a custom query.
 * 
 * @param db Pointer to the fossil_crabdb_t database.
 * @param query Custom query to execute.
 * @return Error code indicating the result of the operation.
 */
fossil_crabdb_error_t fossil_crabdb_execute_query(fossil_crabdb_t *db, const char *query);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

class BlueCrabDB {
public:
    BlueCrabDB() {
        db = fossil_crabdb_create();
    }

    ~BlueCrabDB() {
        try {
            fossil_crabdb_erase(db);
        } catch (...) {
            // Handle the exception here
        }
    }

    /**
     * @brief Create a new namespace.
     * 
     * @param namespace_name Name of the new namespace.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t create_namespace(const std::string& namespace_name) {
        try {
            return fossil_crabdb_create_namespace(db, namespace_name.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Create a new sub-namespace.
     * 
     * @param namespace_name Name of the parent namespace.
     * @param sub_namespace_name Name of the new sub-namespace.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t create_subnamespace(const std::string& namespace_name, const std::string& sub_namespace_name) {
        try {
            return fossil_crabdb_create_sub_namespace(db, namespace_name.c_str(), sub_namespace_name.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Erase a namespace.
     * 
     * @param namespace_name Name of the namespace to erase.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t erase_subnamespace(const std::string& namespace_name) {
        try {
            return fossil_crabdb_erase_namespace(db, namespace_name.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Erase a sub-namespace.
     * 
     * @param namespace_name Name of the parent namespace.
     * @param sub_namespace_name Name of the sub-namespace to erase.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t erase_subnamespace(const std::string& namespace_name, const std::string& sub_namespace_name) {
        try {
            return fossil_crabdb_erase_sub_namespace(db, namespace_name.c_str(), sub_namespace_name.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Insert data into a namespace.
     * 
     * @param namespace_name Name of the namespace.
     * @param key Key of the data to insert.
     * @param value Value of the data to insert.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t insert(const std::string& namespace_name, const std::string& key, const std::string& value) {
        try {
            return fossil_crabdb_insert(db, namespace_name.c_str(), key.c_str(), value.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Get data from a namespace.
     * 
     * @param namespace_name Name of the namespace.
     * @param key Key of the data to get.
     * @param value Pointer to store the retrieved value.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t get(const std::string& namespace_name, const std::string& key, std::string& value) {
        try {
            char* result;
            fossil_crabdb_error_t error = fossil_crabdb_get(db, namespace_name.c_str(), key.c_str(), &result);
            if (error == CRABDB_OK) {
                value = result;
                free(result);
            }
            return error;
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Update data in a namespace.
     * 
     * @param namespace_name Name of the namespace.
     * @param key Key of the data to update.
     * @param value New value for the data.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t update(const std::string& namespace_name, const std::string& key, const std::string& value) {
        try {
            return fossil_crabdb_update(db, namespace_name.c_str(), key.c_str(), value.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Delete data from a namespace.
     * 
     * @param namespace_name Name of the namespace.
     * @param key Key of the data to delete.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t remove(const std::string& namespace_name, const std::string& key) {
        try {
            return fossil_crabdb_delete(db, namespace_name.c_str(), key.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

    /**
     * @brief Execute a custom query.
     * 
     * @param query Custom query to execute.
     * @return Error code indicating the result of the operation.
     */
    fossil_crabdb_error_t execute_query(const std::string& query) {
        try {
            return fossil_crabdb_execute_query(db, query.c_str());
        } catch (...) {
            // Handle the exception here
            return CRABDB_ERR_INVALID_QUERY;
        }
    }

private:
    fossil_crabdb_t* db;
};

} // namespace fossil

#endif

#endif
