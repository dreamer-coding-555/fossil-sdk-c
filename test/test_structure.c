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
#include <fossil/structure/dlist.h>
#include <fossil/structure/dqueue.h>
#include <fossil/structure/flist.h>
#include <fossil/structure/map.h>
#include <fossil/structure/pqueue.h>
#include <fossil/structure/queue.h>
#include <fossil/structure/set.h>
#include <fossil/structure/stack.h>
#include <fossil/structure/tree.h>
#include <fossil/structure/vector.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts
#include <fossil/mockup/file.h>

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Double Linked List
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_dlist_fixture);
FOSSIL_SETUP(struct_dlist_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_dlist_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_dlist_create_and_erase) {
    fossil_dlist_t* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Check if the doubly linked list is created with the expected values
    ASSUME_NOT_CNULL(dlist);
    ASSUME_ITS_CNULL(dlist->head);
    ASSUME_ITS_CNULL(dlist->tail);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, dlist->list_type);

    fossil_dlist_erase(dlist);

    // Check if the doubly linked list is erased
    ASSUME_ITS_CNULL(dlist->head);
    ASSUME_ITS_CNULL(dlist->tail);
    ASSUME_ITS_CNULL(dlist);
}

FOSSIL_TEST(test_dlist_insert_and_size) {
    fossil_dlist_t* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dlist_insert(dlist, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dlist_insert(dlist, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dlist_insert(dlist, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_dlist_size(dlist));

    fossil_dlist_erase(dlist);
}

FOSSIL_TEST(test_dlist_remove) {
    fossil_dlist_t* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dlist_insert(dlist, element1);
    fossil_dlist_insert(dlist, element2);
    fossil_dlist_insert(dlist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dlist_remove(dlist, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_dlist_size(dlist));

    fossil_dlist_erase(dlist);
}

FOSSIL_TEST(test_dlist_reverse_forward) {
    fossil_dlist_t* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dlist_insert(dlist, element1);
    fossil_dlist_insert(dlist, element2);
    fossil_dlist_insert(dlist, element3);

    // Reverse the doubly linked list forward
    fossil_dlist_reverse_forward(dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(dlist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->data.int_type);

    fossil_dlist_erase(dlist);
}

FOSSIL_TEST(test_dlist_reverse_backward) {
    fossil_dlist_t* dlist = fossil_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dlist_insert(dlist, element1);
    fossil_dlist_insert(dlist, element2);
    fossil_dlist_insert(dlist, element3);

    // Reverse the doubly linked list backward
    fossil_dlist_reverse_backward(dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(dlist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->data.int_type);

    retrievedElement = fossil_dlist_getter(dlist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->data.int_type);

    fossil_dlist_erase(dlist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Double Queue
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_dqueue_fixture);
FOSSIL_SETUP(struct_dqueue_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_dqueue_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_dqueue_create_and_erase) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Check if the deque is created with the expected values
    ASSUME_NOT_CNULL(dqueue);
    ASSUME_ITS_CNULL(dqueue->front);
    ASSUME_ITS_CNULL(dqueue->rear);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, dqueue->list_type);

    fossil_dqueue_erase(dqueue);

    // Check if the deque is erased
    ASSUME_ITS_CNULL(dqueue->front);
    ASSUME_ITS_CNULL(dqueue->rear);
    ASSUME_ITS_CNULL(dqueue);
}

FOSSIL_TEST(test_dqueue_insert_and_size) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_dqueue_size(dqueue));

    fossil_dqueue_erase(dqueue);
}

FOSSIL_TEST(test_dqueue_remove) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_dqueue_insert(dqueue, element1);
    fossil_dqueue_insert(dqueue, element2);
    fossil_dqueue_insert(dqueue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_remove(dqueue, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_dqueue_size(dqueue));

    fossil_dqueue_erase(dqueue);
}

FOSSIL_TEST(test_dqueue_getter_and_setter) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element));

    // Get the value for an element
    fossil_tofu_t* retrievedElement = fossil_dqueue_getter(dqueue, element);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    // Update the value for an element
    fossil_tofu_t updatedElement = { TOFU_INT_TYPE, { .int_type = 50 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_setter(dqueue, updatedElement));

    // Get the updated value for the element
    retrievedElement = fossil_dqueue_getter(dqueue, updatedElement);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(50, retrievedElement->data.int_type);

    fossil_dqueue_erase(dqueue);
}

FOSSIL_TEST(test_dqueue_not_empty_and_is_empty) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(dqueue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_insert(dqueue, element));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(dqueue));
    ASSUME_ITS_FALSE(fossil_dqueue_is_empty(dqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_dqueue_remove(dqueue, &removedElement));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(dqueue));

    fossil_dqueue_erase(dqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Forward List
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_flist_fixture);
FOSSIL_SETUP(struct_flist_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_flist_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_flist_create_and_erase) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Check if the linked list is created with the expected values
    ASSUME_ITS_CNULL(flist->head);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, flist->list_type);

    fossil_flist_erase(flist);
}

FOSSIL_TEST(test_flist_insert_and_size) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_insert(flist, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_flist_size(flist));

    fossil_flist_erase(flist);
}

FOSSIL_TEST(test_flist_remove) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_flist_insert(flist, element1);
    fossil_flist_insert(flist, element2);
    fossil_flist_insert(flist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_flist_remove(flist, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_flist_size(flist));

    fossil_flist_erase(flist);
}

FOSSIL_TEST(test_flist_reverse_forward) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_flist_insert(flist, element1);
    fossil_flist_insert(flist, element2);
    fossil_flist_insert(flist, element3);

    // Reverse the linked list forward
    fossil_flist_reverse_forward(flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(flist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    fossil_flist_erase(flist);
}

FOSSIL_TEST(test_flist_reverse_backward) {
    fossil_flist_t* flist = fossil_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_flist_insert(flist, element1);
    fossil_flist_insert(flist, element2);
    fossil_flist_insert(flist, element3);

    // Reverse the linked list backward
    fossil_flist_reverse_backward(flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(flist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->data.int_type);

    retrievedElement = fossil_flist_getter(flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->data.int_type);

    fossil_flist_erase(flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Map
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_map_fixture);
FOSSIL_SETUP(struct_map_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_map_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_map_create_and_erase) {
    fossil_map_t* map = fossil_map_create(TOFU_INT_TYPE);

    // Check if the map is created with the expected values
    ASSUME_NOT_CNULL(map);
    ASSUME_ITS_EQUAL_U32(0, map->size);

    fossil_map_erase(map);
}

FOSSIL_TEST(test_map_insert_and_size) {
    fossil_map_t* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert some key-value pairs
    fossil_tofu_t key1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value1 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t key2 = { TOFU_INT_TYPE, { .int_type = 5 } };
    fossil_tofu_t value2 = { TOFU_INT_TYPE, { .int_type = 20 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key1, value1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key2, value2));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_map_size(map));

    fossil_map_erase(map);
}

FOSSIL_TEST(test_map_remove) {
    fossil_map_t* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert some key-value pairs
    fossil_tofu_t key1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value1 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t key2 = { TOFU_INT_TYPE, { .int_type = 5 } };
    fossil_tofu_t value2 = { TOFU_INT_TYPE, { .int_type = 20 } };

    fossil_map_insert(map, key1, value1);
    fossil_map_insert(map, key2, value2);

    // Remove a key-value pair
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_remove(map, key1));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(1, fossil_map_size(map));

    fossil_map_erase(map);
}

FOSSIL_TEST(test_map_getter_and_setter) {
    fossil_map_t* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert a key-value pair
    fossil_tofu_t key = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value = { TOFU_INT_TYPE, { .int_type = 10 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key, value));

    // Get the value for a key
    fossil_tofu_t retrievedValue;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct
    ASSUME_ITS_EQUAL_I32(10, retrievedValue.data.int_type);

    // Update the value for a key
    fossil_tofu_t updatedValue = { TOFU_INT_TYPE, { .int_type = 50 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_setter(map, key, updatedValue));

    // Get the updated value for the key
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct after update
    ASSUME_ITS_EQUAL_I32(50, retrievedValue.data.int_type);

    fossil_map_erase(map);
}

FOSSIL_TEST(test_map_contains) {
    fossil_map_t* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert a key-value pair
    fossil_tofu_t key = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value = { TOFU_INT_TYPE, { .int_type = 10 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key, value));

    // Check if the map contains the key
    ASSUME_ITS_TRUE(fossil_map_contains(map, key));

    // Check for a non-existing key
    fossil_tofu_t nonExistingKey = { TOFU_INT_TYPE, { .int_type = 100 } };
    ASSUME_ITS_FALSE(fossil_map_contains(map, nonExistingKey));

    fossil_map_erase(map);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Priority Queue
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_pqueue_fixture);
FOSSIL_SETUP(struct_pqueue_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_pqueue_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_pqueue_create_and_erase) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Check if the priority queue is created with the expected values
    ASSUME_NOT_CNULL(pqueue);
    ASSUME_ITS_CNULL(pqueue->front);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, pqueue->queue_type);

    fossil_pqueue_erase(pqueue);
}

FOSSIL_TEST(test_pqueue_insert_and_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element1, 2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element2, 1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element3, 3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_pqueue_size(pqueue));

    fossil_pqueue_erase(pqueue);
}

FOSSIL_TEST(test_pqueue_remove) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_pqueue_insert(pqueue, element1, 2);
    fossil_pqueue_insert(pqueue, element2, 1);
    fossil_pqueue_insert(pqueue, element3, 3);

    // Remove an element
    fossil_tofu_t removedElement;
    int removedPriority;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_pqueue_size(pqueue));

    fossil_pqueue_erase(pqueue);
}

FOSSIL_TEST(test_pqueue_not_empty_and_is_empty) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_insert(pqueue, element, 2));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue));
    ASSUME_ITS_FALSE(fossil_pqueue_is_empty(pqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    int removedPriority;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue));

    fossil_pqueue_erase(pqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Queue
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_queue_fixture);
FOSSIL_SETUP(struct_queue_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_queue_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_queue_create_and_erase) {
    fossil_queue_t* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Check if the queue is created with the expected values
    ASSUME_NOT_CNULL(queue);
    ASSUME_ITS_CNULL(queue->front);
    ASSUME_ITS_CNULL(queue->rear);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, queue->queue_type);

    fossil_queue_erase(queue);
}

FOSSIL_TEST(test_queue_insert_and_size) {
    fossil_queue_t* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_queue_size(queue));

    fossil_queue_erase(queue);
}

FOSSIL_TEST(test_queue_remove) {
    fossil_queue_t* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_queue_insert(queue, element1);
    fossil_queue_insert(queue, element2);
    fossil_queue_insert(queue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_queue_remove(queue, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_queue_size(queue));

    fossil_queue_erase(queue);
}

FOSSIL_TEST(test_queue_not_empty_and_is_empty) {
    fossil_queue_t* queue = fossil_queue_create(TOFU_INT_TYPE);

    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_queue_not_empty(queue));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue));

    // Insert an element
    fossil_tofu_t element = { TOFU_INT_TYPE, { .int_type = 42 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_queue_insert(queue, element));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue));
    ASSUME_ITS_FALSE(fossil_queue_is_empty(queue));

    // Remove the element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_queue_remove(queue, &removedElement));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_queue_not_empty(queue));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue));

    fossil_queue_erase(queue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Set
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_set_fixture);
FOSSIL_SETUP(struct_set_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_set_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_set_create_and_erase) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Check if the set is created with the expected values
    ASSUME_NOT_CNULL(set);
    ASSUME_ITS_CNULL(set->head);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, set->set_type);

    fossil_set_erase(set);
}

FOSSIL_TEST(test_set_insert_and_size) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_insert(set, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_insert(set, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_insert(set, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_set_size(set));

    fossil_set_erase(set);
}

FOSSIL_TEST(test_set_remove) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_set_insert(set, element1);
    fossil_set_insert(set, element2);
    fossil_set_insert(set, element3);

    // Remove an element
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_set_remove(set, element2));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_set_size(set));

    fossil_set_erase(set);
}

FOSSIL_TEST(test_set_contains) {
    fossil_set_t* set = fossil_set_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_set_insert(set, element1);
    fossil_set_insert(set, element2);
    fossil_set_insert(set, element3);

    // Check if elements are contained in the set
    ASSUME_ITS_TRUE(fossil_set_contains(set, element1));
    ASSUME_ITS_TRUE(fossil_set_contains(set, element3));

    // Check for non-existing element
    fossil_tofu_t nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    ASSUME_ITS_FALSE(fossil_set_contains(set, nonExistingElement));

    fossil_set_erase(set);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Stack
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_stack_fixture);
FOSSIL_SETUP(struct_stack_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_stack_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_stack_create_and_erase) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Check if the stack is created with the expected values
    ASSUME_NOT_CNULL(stack);
    ASSUME_ITS_CNULL(stack->top);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, stack->stack_type);

    fossil_stack_erase(stack);
}

FOSSIL_TEST(test_stack_insert_and_size) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element1));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element2));
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_insert(stack, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(3, fossil_stack_size(stack));

    fossil_stack_erase(stack);
}

FOSSIL_TEST(test_stack_remove) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_stack_insert(stack, element1);
    fossil_stack_insert(stack, element2);
    fossil_stack_insert(stack, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_stack_remove(stack, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.data.int_type);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_U32(2, fossil_stack_size(stack));

    fossil_stack_erase(stack);
}

FOSSIL_TEST(test_stack_top) {
    fossil_stack_t* stack = fossil_stack_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_stack_insert(stack, element1);
    fossil_stack_insert(stack, element2);
    fossil_stack_insert(stack, element3);

    // Check the top element
    fossil_tofu_t topElement = fossil_stack_top(stack, (fossil_tofu_t){TOFU_INT_TYPE, {.int_type = -1}});
    ASSUME_ITS_EQUAL_I32(5, topElement.data.int_type);

    // Remove an element
    fossil_stack_remove(stack, NULL);

    // Check the top element after removal
    topElement = fossil_stack_top(stack, (fossil_tofu_t){TOFU_INT_TYPE, {.int_type = -1}});
    ASSUME_ITS_EQUAL_I32(5, topElement.data.int_type);

    fossil_stack_erase(stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Tree
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_tree_fixture);
FOSSIL_SETUP(struct_tree_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_tree_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_tree_create_and_erase) {
    fossil_tree_t* tree = fossil_tree_create(TOFU_INT_TYPE);
    
    // Check if the tree is created with the expected values
    ASSUME_NOT_CNULL(tree);
    ASSUME_ITS_CNULL(tree->root);
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, tree->tree);

    fossil_tree_erase(tree);
}

FOSSIL_TEST(test_tree_insert_and_search) {
    fossil_tree_t* tree = fossil_tree_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_tree_insert(tree, element1));
    ASSUME_ITS_TRUE(fossil_tree_insert(tree, element2));
    ASSUME_ITS_TRUE(fossil_tree_insert(tree, element3));

    // Search for elements
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_OK, fossil_tree_search(tree, element1));
    ASSUME_ITS_TRUE(fossil_tree_search(tree, element2));
    ASSUME_ITS_TRUE(fossil_tree_search(tree, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS, fossil_tree_search(tree, nonExistingElement));

    fossil_tree_erase(tree);
}

FOSSIL_TEST(test_tree_remove) {
    fossil_tree_t* tree = fossil_tree_create(TOFU_INT_TYPE);

    // Insert some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_tree_insert(tree, element1);
    fossil_tree_insert(tree, element2);
    fossil_tree_insert(tree, element3);

    // Remove an element
    ASSUME_ITS_TRUE(fossil_tree_remove(tree, element2));
    ASSUME_ITS_TRUE(fossil_tree_search(tree, element3));

    fossil_tree_erase(tree);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Vector
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_vect_fixture);
FOSSIL_SETUP(struct_vect_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(struct_vect_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_vector_create_and_erase) {
    fossil_vector_t vector = fossil_vector_create(TOFU_INT_TYPE);
    
    // Check if the vector is created with the expected values
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, vector.expected_type);
    ASSUME_ITS_EQUAL_U32(0, vector.size);
    ASSUME_ITS_EQUAL_U32(INITIAL_CAPACITY, vector.capacity);

    fossil_vector_erase(&vector);
}

FOSSIL_TEST(test_vector_push_back) {
    fossil_vector_t vector = fossil_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_vector_push_back(&vector, element1);
    fossil_vector_push_back(&vector, element2);
    fossil_vector_push_back(&vector, element3);

    // Check if the elements are added correctly
    ASSUME_ITS_EQUAL_U32(3, vector.size);
    ASSUME_ITS_EQUAL_I32(42, vector.data[0].data.int_type);
    ASSUME_ITS_EQUAL_I32(10, vector.data[1].data.int_type);
    ASSUME_ITS_EQUAL_I32(5, vector.data[2].data.int_type);

    fossil_vector_erase(&vector);
}

FOSSIL_TEST(test_vector_search) {
    fossil_vector_t vector = fossil_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_vector_push_back(&vector, element1);
    fossil_vector_push_back(&vector, element2);
    fossil_vector_push_back(&vector, element3);

    // Search for elements
    ASSUME_ITS_EQUAL_I32(0, fossil_vector_search(&vector, element1));
    ASSUME_ITS_EQUAL_I32(1, fossil_vector_search(&vector, element2));
    ASSUME_ITS_EQUAL_I32(2, fossil_vector_search(&vector, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    ASSUME_ITS_EQUAL_I32(-1, fossil_vector_search(&vector, nonExistingElement));

    fossil_vector_erase(&vector);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_structure_tests) {    
    // Double List Fixture
    ADD_TESTF(test_flist_create_and_erase, struct_flist_fixture);
    ADD_TESTF(test_flist_insert_and_size, struct_flist_fixture);
    ADD_TESTF(test_flist_remove, struct_flist_fixture);
    ADD_TESTF(test_flist_reverse_forward, struct_flist_fixture);
    ADD_TESTF(test_flist_reverse_backward, struct_flist_fixture);

    // Map Fixture
    ADD_TESTF(test_map_create_and_erase, struct_map_fixture);
    ADD_TESTF(test_map_insert_and_size, struct_map_fixture);
    ADD_TESTF(test_map_remove, struct_map_fixture);
    ADD_TESTF(test_map_getter_and_setter, struct_map_fixture);
    ADD_TESTF(test_map_contains, struct_map_fixture);

    // Priority Queue Fixture
    ADD_TESTF(test_pqueue_create_and_erase, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_insert_and_size, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_remove, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_not_empty_and_is_empty, struct_pqueue_fixture);

    // Queue Fixture
    ADD_TESTF(test_queue_create_and_erase, struct_queue_fixture);
    ADD_TESTF(test_queue_insert_and_size, struct_queue_fixture);
    ADD_TESTF(test_queue_remove, struct_queue_fixture);
    ADD_TESTF(test_queue_not_empty_and_is_empty, struct_queue_fixture);

    // Set Fixture
    ADD_TESTF(test_set_create_and_erase, struct_set_fixture);
    ADD_TESTF(test_set_insert_and_size, struct_set_fixture);
    ADD_TESTF(test_set_remove, struct_set_fixture);
    ADD_TESTF(test_set_contains, struct_set_fixture);

    // Stack Fixture
    ADD_TESTF(test_stack_create_and_erase, struct_stack_fixture);
    ADD_TESTF(test_stack_insert_and_size, struct_stack_fixture);
    ADD_TESTF(test_stack_remove, struct_stack_fixture);
    ADD_TESTF(test_stack_top, struct_stack_fixture);

    // Tree Fixture
    ADD_TESTF(test_tree_create_and_erase, struct_tree_fixture);
    ADD_TESTF(test_tree_insert_and_search, struct_tree_fixture);
    ADD_TESTF(test_tree_remove, struct_tree_fixture);

    // Vector Fixture
    ADD_TESTF(test_vector_create_and_erase, struct_vect_fixture);
    ADD_TESTF(test_vector_push_back, struct_vect_fixture);
    ADD_TESTF(test_vector_search, struct_vect_fixture);
} // end of tests
