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
#ifndef FOSSIL_STRUCTURES_TREE_H
#define FOSSIL_STRUCTURES_TREE_H

/**
 * @brief Tree Data Structure
 * 
 * This library provides functions for working with trees, which are hierarchical data structures
 * consisting of nodes connected by edges. Trees are often used for representing hierarchical
 * relationships or organizing data hierarchically.
 *
 * @defgroup create_delete CREATE and DELETE
 * @defgroup traversal Traversal Functions
 * @defgroup search Search Functions
 * @defgroup modify Modify Functions
 * @defgroup utility Utility Functions
 */

#include "fossil/tofu/tofu.h"

// Node structure for the binary search tree
typedef struct fossil_tree_node_t {
    fossil_tofu_t data;
    struct fossil_tree_node_t* left;
    struct fossil_tree_node_t* right;
} fossil_tree_node_t;

// Tree structure
typedef struct {
    fossil_tree_node_t* root;
    fossil_tofu_type tree; // Type of the tree
} fossil_tree_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new tree with the specified data type.
 *
 * @param tree The type of data the tree will store.
 * @return     The created tree.
 */
fossil_tree_t* fossil_tree_create(fossil_tofu_type tree);

/**
 * Erase the contents of the tree and free allocated memory.
 *
 * @param tree The tree to erase.
 */
void fossil_tree_erase(fossil_tree_t* tree);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the tree.
 *
 * @param tree The tree to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_tree_insert(fossil_tree_t* tree, fossil_tofu_t data);

/**
 * Remove data from the tree.
 *
 * @param tree The tree to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_tree_remove(fossil_tree_t* tree, fossil_tofu_t data);

/**
 * Search for data in the tree.
 *
 * @param tree The tree to search.
 * @param data The data to search for.
 * @return     The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_tree_search(const fossil_tree_t* tree, fossil_tofu_t data);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the tree.
 *
 * @param tree The tree for which to get the size.
 * @return     The size of the tree.
 */
size_t fossil_tree_size(const fossil_tree_t* tree);

/**
 * Get the data from the tree matching the specified data.
 *
 * @param tree The tree from which to get the data.
 * @param data The data to search for.
 * @return     A pointer to the matching data, or NULL if not found.
 */
fossil_tofu_t* fossil_tree_getter(const fossil_tree_t* tree, fossil_tofu_t data);

/**
 * Set data in the tree.
 *
 * @param tree The tree in which to set the data.
 * @param data The data to set.
 * @return     The error code indicating the success or failure of the operation.
 */
fossil_tofu_error_t fossil_tree_setter(fossil_tree_t* tree, fossil_tofu_t data);

/**
 * Check if the tree is not empty.
 *
 * @param tree The tree to check.
 * @return     True if the tree is not empty, false otherwise.
 */
bool fossil_tree_not_empty(const fossil_tree_t* tree);

/**
 * Check if the tree is not a null pointer.
 *
 * @param tree The tree to check.
 * @return     True if the tree is not a null pointer, false otherwise.
 */
bool fossil_tree_not_cnullptr(const fossil_tree_t* tree);

/**
 * Check if the tree is empty.
 *
 * @param tree The tree to check.
 * @return     True if the tree is empty, false otherwise.
 */
bool fossil_tree_is_empty(const fossil_tree_t* tree);

/**
 * Check if the tree is a null pointer.
 *
 * @param tree The tree to check.
 * @return     True if the tree is a null pointer, false otherwise.
 */
bool fossil_tree_is_cnullptr(const fossil_tree_t* tree);

/**
 * Check if the tree contains the specified data.
 *
 * @param tree The tree to check.
 * @param data The data to check for.
 * @return     True if the tree contains the data, false otherwise.
 */
bool fossil_tree_contains(const fossil_tree_t* tree, fossil_tofu_t data);

#ifdef __cplusplus
}
#endif

#endif
