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
#include "fossil/structures/tree.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
ctree* fossil_tree_create(fossil_tofu_type tree) {
    ctree* new_tree = (ctree*)malloc(sizeof(ctree));
    if (new_tree == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_tree->root = cnullptr;
    new_tree->tree = tree;

    return new_tree;
}

// Helper function to recursively erase nodes
void fossil_tree_erase_recursive(ctree_node* node) {
    if (node == cnullptr) {
        return;
    }

    fossil_tree_erase_recursive(node->left);
    fossil_tree_erase_recursive(node->right);

    free(node);
}

void fossil_tree_erase(ctree* tree) {
    if (tree == cnullptr) {
        return;
    }

    // Recursively erase nodes starting from the root
    fossil_tree_erase_recursive(tree->root);

    free(tree);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Helper function to find the minimum node in a subtree
ctree_node* fossil_tree_find_min(ctree_node* node) {
    while (node->left != cnullptr) {
        node = node->left;
    }
    return node;
}

// Helper function to recursively remove a node
fossil_tofu_error_t fossil_tree_remove_recursive(ctree_node** root, fossil_tofu_t data) {
    if (*root == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Element not found
    }

    fossil_tofu_error_t comparison_error = fossil_tofu_compare(&data, &(*root)->data);
    if (comparison_error != FOSSIL_TOFU_ERROR_OK) {
        return comparison_error;
    }

    if (comparison_error < 0) {
        return fossil_tree_remove_recursive(&(*root)->left, data);
    } else if (comparison_error > 0) {
        return fossil_tree_remove_recursive(&(*root)->right, data);
    } else {
        // Node with the key found

        // Case 1: Node with only one child or no child
        if ((*root)->left == cnullptr) {
            ctree_node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == cnullptr) {
            ctree_node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Case 3: Node with two children
            ctree_node* temp = fossil_tree_find_min((*root)->right);
            (*root)->data = temp->data;
            return fossil_tree_remove_recursive(&(*root)->right, temp->data);
        }

        return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
    }
}

// Helper function to recursively insert a node
fossil_tofu_error_t fossil_tree_insert_recursive(ctree_node** root, fossil_tofu_t* data) {
    if (root == cnullptr || data == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (*root == cnullptr) {
        *root = (ctree_node*)malloc(sizeof(ctree_node));
        if (*root == cnullptr) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_MEMORY_CORRUPTION);  // Handle memory allocation failure
        }

        (*root)->data = *data;
        (*root)->left = cnullptr;
        (*root)->right = cnullptr;

        return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
    }

    fossil_tofu_error_t comparison_error = fossil_tofu_compare(data, &(*root)->data);
    if (comparison_error != FOSSIL_TOFU_ERROR_OK) {
        return comparison_error;
    }

    if (comparison_error < 0) {
        return fossil_tree_insert_recursive(&(*root)->left, data);
    } else if (comparison_error > 0) {
        return fossil_tree_insert_recursive(&(*root)->right, data);
    } else {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS);  // Duplicate element
    }
}

fossil_tofu_error_t fossil_tree_insert(ctree* tree, fossil_tofu_t data) {
    if (tree == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    return fossil_tree_insert_recursive(&tree->root, &data);
}

fossil_tofu_error_t fossil_tree_remove(ctree* tree, fossil_tofu_t data) {
    if (tree == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    return fossil_tree_remove_recursive(&tree->root, data);
}

// Helper function to recursively search for a node
fossil_tofu_error_t fossil_tree_search_recursive(ctree_node* root, fossil_tofu_t data) {
    if (root == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Element not found
    }

    int compare_result = fossil_tofu_compare(&data, &root->data);

    if (compare_result == 0) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Element found
    } else if (compare_result < 0) {
        return fossil_tree_search_recursive(root->left, data);
    } else {
        return fossil_tree_search_recursive(root->right, data);
    }
}

fossil_tofu_error_t fossil_tree_search(const ctree* tree, fossil_tofu_t data) {
    if (tree == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    return fossil_tree_search_recursive(tree->root, data);
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fossil_tree_size_recursive(ctree_node* root) {
    if (root == cnullptr) {
        return 0;
    }

    return 1 + fossil_tree_size_recursive(root->left) + fossil_tree_size_recursive(root->right);
}

size_t fossil_tree_size(const ctree* tree) {
    if (tree == cnullptr) {
        return 0;
    }

    return fossil_tree_size_recursive(tree->root);
}

// Helper function to recursively get a pointer to a node's data
fossil_tofu_t* fossil_tree_getter_recursive(ctree_node* root, fossil_tofu_t data) {
    if (root == cnullptr) {
        return cnullptr;
    }

    int compare_result = fossil_tofu_compare(&data, &root->data);

    if (compare_result == 0) {
        return (fossil_tofu_t*)&root->data;
    } else if (compare_result < 0) {
        return fossil_tree_getter_recursive(root->left, data);
    } else {
        return fossil_tree_getter_recursive(root->right, data);
    }
}

fossil_tofu_t* fossil_tree_getter(const ctree* tree, fossil_tofu_t data) {
    if (tree == cnullptr) {
        return cnullptr;
    }

    return fossil_tree_getter_recursive(tree->root, data);
}

// Helper function to recursively set the data of a node
fossil_tofu_error_t fossil_tree_setter_recursive(ctree_node* root, fossil_tofu_t data) {
    if (root == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Element not found
    }

    int compare_result = fossil_tofu_compare(&data, &root->data);
    
    if (compare_result == 0) {
        root->data = data; // Update the element
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
    } else if (compare_result < 0) {
        return fossil_tree_setter_recursive(root->left, data);
    } else {
        return fossil_tree_setter_recursive(root->right, data);
    }
}

fossil_tofu_error_t fossil_tree_setter(ctree* tree, fossil_tofu_t data) {
    if (tree == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    return fossil_tree_setter_recursive(tree->root, data);
}

bool fossil_tree_not_empty(const ctree* tree) {
    return tree != cnullptr && tree->root != cnullptr;
}

bool fossil_tree_not_cnullptr(const ctree* tree) {
    return tree != cnullptr;
}

bool fossil_tree_is_empty(const ctree* tree) {
    return tree == cnullptr || tree->root == cnullptr;
}

bool fossil_tree_is_cnullptr(const ctree* tree) {
    return tree == cnullptr;
}

// Helper function to recursively check if the tree contains an element
bool fossil_tree_contains_recursive(ctree_node* root, fossil_tofu_t data) {
    if (root == cnullptr) {
        return false;
    }

    int compare_result = fossil_tofu_compare(&data, &root->data);

    if (compare_result == 0) {
        return true; // Element found
    } else if (compare_result < 0) {
        return fossil_tree_contains_recursive(root->left, data);
    } else {
        return fossil_tree_contains_recursive(root->right, data);
    }
}

bool fossil_tree_contains(const ctree* tree, fossil_tofu_t data) {
    if (tree == cnullptr) {
        return false;
    }

    return fossil_tree_contains_recursive(tree->root, data);
}
