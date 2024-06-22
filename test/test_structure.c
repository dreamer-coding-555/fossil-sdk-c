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
#include <fossil/structure/pqueue.h>
#include <fossil/structure/queue.h>
#include <fossil/structure/set.h>
#include <fossil/structure/stack.h>
#include <fossil/structure/tree.h>
#include <fossil/structure/vector.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts
#include <fossil/mockup.h>

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
fossil_dlist_t* mock_dlist;

FOSSIL_SETUP(struct_dlist_fixture) {
    mock_dlist = fossil_dlist_create("int");
}

FOSSIL_TEARDOWN(struct_dlist_fixture) {
    fossil_dlist_erase(mock_dlist);
}

FOSSIL_TEST(test_dlist_create_and_erase) {
    // Check if the doubly linked list is created with the expected values
    ASSUME_NOT_CNULL(mock_dlist);
    ASSUME_ITS_CNULL(mock_dlist->head);
    ASSUME_ITS_CNULL(mock_dlist->tail);
}

FOSSIL_TEST(test_dlist_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_dlist_insert(mock_dlist, element1));
    ASSUME_ITS_TRUE(fossil_dlist_insert(mock_dlist, element2));
    ASSUME_ITS_TRUE(fossil_dlist_insert(mock_dlist, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_dlist_size(mock_dlist));
}

FOSSIL_TEST(test_dlist_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dlist_insert(mock_dlist, element1);
    fossil_dlist_insert(mock_dlist, element2);
    fossil_dlist_insert(mock_dlist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_dlist_remove(mock_dlist, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_dlist_size(mock_dlist));
}

FOSSIL_TEST(test_dlist_reverse_forward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dlist_insert(mock_dlist, element1);
    fossil_dlist_insert(mock_dlist, element2);
    fossil_dlist_insert(mock_dlist, element3);

    // Reverse the doubly linked list forward
    fossil_dlist_reverse_forward(mock_dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(mock_dlist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);

    retrievedElement = fossil_dlist_getter(mock_dlist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_dlist_getter(mock_dlist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);
}

FOSSIL_TEST(test_dlist_reverse_backward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dlist_insert(mock_dlist, element1);
    fossil_dlist_insert(mock_dlist, element2);
    fossil_dlist_insert(mock_dlist, element3);

    // Reverse the doubly linked list backward
    fossil_dlist_reverse_backward(mock_dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(mock_dlist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);

    retrievedElement = fossil_dlist_getter(mock_dlist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_dlist_getter(mock_dlist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Double Queue
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_dqueue_fixture);
fossil_dqueue_t* mock_dqueue;
FOSSIL_SETUP(struct_dqueue_fixture) {
    mock_dqueue = fossil_dqueue_create("int");
}

FOSSIL_TEARDOWN(struct_dqueue_fixture) {
    fossil_dqueue_erase(mock_dqueue);
}

FOSSIL_TEST(test_dqueue_create_and_erase) {
    // Check if the deque is created with the expected values
    ASSUME_NOT_CNULL(mock_dqueue);
    ASSUME_ITS_CNULL(mock_dqueue->front);
    ASSUME_ITS_CNULL(mock_dqueue->rear);
}

FOSSIL_TEST(test_dqueue_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_dqueue_insert(mock_dqueue, element1));
    ASSUME_ITS_TRUE(fossil_dqueue_insert(mock_dqueue, element2));
    ASSUME_ITS_TRUE(fossil_dqueue_insert(mock_dqueue, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_dqueue_size(mock_dqueue));
}

FOSSIL_TEST(test_dqueue_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dqueue_insert(mock_dqueue, element1);
    fossil_dqueue_insert(mock_dqueue, element2);
    fossil_dqueue_insert(mock_dqueue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_dqueue_remove(mock_dqueue, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_dqueue_size(mock_dqueue));
}

FOSSIL_TEST(test_dqueue_getter_and_setter) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(mock_dqueue, element));

    // Get the value for an element
    fossil_tofu_t* retrievedElement = fossil_dqueue_getter(mock_dqueue, element);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);

    // Update the value for an element
    fossil_tofu_t updatedElement = fossil_tofu_create("int", "50");
    ASSUME_ITS_TRUE(fossil_dqueue_setter(mock_dqueue, updatedElement));

    // Get the updated value for the element
    retrievedElement = fossil_dqueue_getter(mock_dqueue, updatedElement);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(50, retrievedElement->value.int_val);
}

FOSSIL_TEST(test_dqueue_not_empty_and_is_empty) {
    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(mock_dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(mock_dqueue));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(mock_dqueue, element));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(mock_dqueue));
    ASSUME_ITS_FALSE(fossil_dqueue_is_empty(mock_dqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_dqueue_remove(mock_dqueue, &removedElement));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(mock_dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(mock_dqueue));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Forward List
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_flist_fixture);
fossil_flist_t* mock_flist;

FOSSIL_SETUP(struct_flist_fixture) {
    mock_flist = fossil_flist_create("int");
}

FOSSIL_TEARDOWN(struct_flist_fixture) {
    fossil_flist_erase(mock_flist);
}

FOSSIL_TEST(test_flist_create_and_erase) {
    // Check if the linked list is created with the expected values
    ASSUME_ITS_CNULL(mock_flist->head);
}

FOSSIL_TEST(test_flist_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_flist_insert(mock_flist, element1));
    ASSUME_ITS_TRUE(fossil_flist_insert(mock_flist, element2));
    ASSUME_ITS_TRUE(fossil_flist_insert(mock_flist, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_flist_size(mock_flist));
}

FOSSIL_TEST(test_flist_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_flist_remove(mock_flist, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_flist_size(mock_flist));
}

FOSSIL_TEST(test_flist_reverse_forward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Reverse the linked list forward
    fossil_flist_reverse_forward(mock_flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(mock_flist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);
}

FOSSIL_TEST(test_flist_reverse_backward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Reverse the linked list backward
    fossil_flist_reverse_backward(mock_flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(mock_flist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Priority Queue
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_pqueue_fixture);
fossil_pqueue_t* mock_pqueue;

FOSSIL_SETUP(struct_pqueue_fixture) {
    mock_pqueue = fossil_pqueue_create("int");
}

FOSSIL_TEARDOWN(struct_pqueue_fixture) {
    fossil_pqueue_erase(mock_pqueue);
}

FOSSIL_TEST(test_pqueue_create_and_erase) {
    // Check if the priority queue is created with the expected values
    ASSUME_NOT_CNULL(mock_pqueue);
    ASSUME_ITS_CNULL(mock_pqueue->front);
}

FOSSIL_TEST(test_pqueue_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element1, 2));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element2, 1));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element3, 3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_pqueue_size(mock_pqueue));
}

FOSSIL_TEST(test_pqueue_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_pqueue_insert(mock_pqueue, element1, 2);
    fossil_pqueue_insert(mock_pqueue, element2, 1);
    fossil_pqueue_insert(mock_pqueue, element3, 3);

    // Remove an element
    fossil_tofu_t removedElement;
    int removedPriority;
    ASSUME_ITS_TRUE(fossil_pqueue_remove(mock_pqueue, &removedElement, &removedPriority));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_pqueue_size(mock_pqueue));
}

FOSSIL_TEST(test_pqueue_not_empty_and_is_empty) {
    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(mock_pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(mock_pqueue));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element, 2));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(mock_pqueue));
    ASSUME_ITS_FALSE(fossil_pqueue_is_empty(mock_pqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    int removedPriority;
    ASSUME_ITS_TRUE(fossil_pqueue_remove(mock_pqueue, &removedElement, &removedPriority));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(mock_pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(mock_pqueue));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Queue
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_queue_fixture);
fossil_queue_t *mock_queue;

FOSSIL_SETUP(struct_queue_fixture) {
    mock_queue = fossil_queue_create("int");
}

FOSSIL_TEARDOWN(struct_queue_fixture) {
    fossil_queue_erase(mock_queue);
}

FOSSIL_TEST(test_queue_create_and_erase) {
    // Check if the queue is created with the expected values
    ASSUME_NOT_CNULL(mock_queue);
    ASSUME_ITS_CNULL(mock_queue->front);
    ASSUME_ITS_CNULL(mock_queue->rear);
}

FOSSIL_TEST(test_queue_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element1));
    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element2));
    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_queue_size(mock_queue));
}

FOSSIL_TEST(test_queue_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_queue_insert(mock_queue, element1);
    fossil_queue_insert(mock_queue, element2);
    fossil_queue_insert(mock_queue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_queue_remove(mock_queue, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_queue_size(mock_queue));
}

FOSSIL_TEST(test_queue_not_empty_and_is_empty) {
    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_queue_not_empty(mock_queue));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(mock_queue));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element));

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_queue_not_empty(mock_queue));
    ASSUME_ITS_FALSE(fossil_queue_is_empty(mock_queue));

    // Remove the element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_queue_remove(mock_queue, &removedElement));

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_queue_not_empty(mock_queue));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(mock_queue));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Set
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_set_fixture);
fossil_set_t* mock_set;

FOSSIL_SETUP(struct_set_fixture) {
    mock_set = fossil_set_create("int");
}

FOSSIL_TEARDOWN(struct_set_fixture) {
    fossil_set_erase(mock_set);
}

FOSSIL_TEST(test_set_create_and_erase) {
    // Check if the set is created with the expected values
    ASSUME_NOT_CNULL(mock_set);
    ASSUME_ITS_CNULL(mock_set->head);
}

FOSSIL_TEST(test_set_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_set_insert(mock_set, element1));
    ASSUME_ITS_TRUE(fossil_set_insert(mock_set, element2));
    ASSUME_ITS_TRUE(fossil_set_insert(mock_set, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_set_size(mock_set));
}

FOSSIL_TEST(test_set_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_set_insert(mock_set, element1);
    fossil_set_insert(mock_set, element2);
    fossil_set_insert(mock_set, element3);

    // Remove an element
    ASSUME_ITS_TRUE(fossil_set_remove(mock_set, element2));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_set_size(mock_set));
}

FOSSIL_TEST(test_set_contains) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_set_insert(mock_set, element1);
    fossil_set_insert(mock_set, element2);
    fossil_set_insert(mock_set, element3);

    // Check if elements are contained in the set
    ASSUME_ITS_TRUE(fossil_set_contains(mock_set, element1));
    ASSUME_ITS_TRUE(fossil_set_contains(mock_set, element3));

    // Check for non-existing element
    fossil_tofu_t nonExistingElement = fossil_tofu_create("int", "42");
    ASSUME_ITS_FALSE(fossil_set_contains(mock_set, nonExistingElement));

    fossil_tofu_erase(&nonExistingElement);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Stack
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_stack_fixture);
fossil_stack_t* mock_stack;

FOSSIL_SETUP(struct_stack_fixture) {
    mock_stack = fossil_stack_create("int");
}

FOSSIL_TEARDOWN(struct_stack_fixture) {
    fossil_stack_erase(mock_stack);
}

FOSSIL_TEST(test_stack_create_and_erase) {
    // Check if the stack is created with the expected values
    ASSUME_NOT_CNULL(mock_stack);
    ASSUME_ITS_CNULL(mock_stack->top);
}

FOSSIL_TEST(test_stack_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_stack_insert(mock_stack, element1));
    ASSUME_ITS_TRUE(fossil_stack_insert(mock_stack, element2));
    ASSUME_ITS_TRUE(fossil_stack_insert(mock_stack, element3));

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_stack_size(mock_stack));
}

FOSSIL_TEST(test_stack_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_stack_insert(mock_stack, element1);
    fossil_stack_insert(mock_stack, element2);
    fossil_stack_insert(mock_stack, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_stack_remove(mock_stack, &removedElement));

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_stack_size(mock_stack));
}

FOSSIL_TEST(test_stack_top) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");
    fossil_tofu_t default_element = fossil_tofu_create("int", "-1");

    fossil_stack_insert(mock_stack, element1);
    fossil_stack_insert(mock_stack, element2);
    fossil_stack_insert(mock_stack, element3);

    // Check the top element
    fossil_tofu_t topElement = fossil_stack_top(mock_stack, default_element);
    ASSUME_ITS_EQUAL_I32(5, topElement.value.int_val);

    // Remove an element
    fossil_stack_remove(mock_stack, xnull);

    // Check the top element after removal
    topElement = fossil_stack_top(mock_stack, default_element);
    ASSUME_ITS_EQUAL_I32(5, topElement.value.int_val);

    fossil_tofu_erase(&default_element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Tree
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_tree_fixture);
fossil_tree_t* mock_tree;

FOSSIL_SETUP(struct_tree_fixture) {
    mock_tree = fossil_tree_create("int");
}

FOSSIL_TEARDOWN(struct_tree_fixture) {
    fossil_tree_erase(mock_tree);
}

FOSSIL_TEST(test_tree_create_and_erase) {    
    // Check if the tree is created with the expected values
    ASSUME_NOT_CNULL(mock_tree);
    ASSUME_ITS_CNULL(mock_tree->root);
}

FOSSIL_TEST(test_tree_insert_and_search) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_tree_insert(mock_tree, element1));
    ASSUME_ITS_TRUE(fossil_tree_insert(mock_tree, element2));
    ASSUME_ITS_TRUE(fossil_tree_insert(mock_tree, element3));

    // Search for elements
    ASSUME_ITS_TRUE(fossil_tree_search(mock_tree, element1));
    ASSUME_ITS_TRUE(fossil_tree_search(mock_tree, element2));
    ASSUME_ITS_TRUE(fossil_tree_search(mock_tree, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = fossil_tofu_create("int", "100");
    ASSUME_ITS_EQUAL_SIZE(3 ,fossil_tree_search(mock_tree, nonExistingElement));

    fossil_tofu_erase(&nonExistingElement);
}

FOSSIL_TEST(test_tree_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_tree_insert(mock_tree, element1);
    fossil_tree_insert(mock_tree, element2);
    fossil_tree_insert(mock_tree, element3);

    // Remove an element
    ASSUME_ITS_TRUE(fossil_tree_remove(mock_tree, element2));
    ASSUME_ITS_TRUE(fossil_tree_search(mock_tree, element3));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Vector
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_vect_fixture);
fossil_vector_t* mock_vector;

FOSSIL_SETUP(struct_vect_fixture) {
    mock_vector = fossil_vector_create("int");
}

FOSSIL_TEARDOWN(struct_vect_fixture) {
    fossil_vector_erase(mock_vector);
}

FOSSIL_TEST(test_vector_create_and_erase) {    
    // Check if the vector is created with the expected values
    ASSUME_ITS_EQUAL_U32(0, mock_vector->size);
    ASSUME_ITS_EQUAL_U32(INITIAL_CAPACITY, mock_vector->capacity);
}

FOSSIL_TEST(test_vector_push_back) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(&mock_vector, element1);
    fossil_vector_push_back(&mock_vector, element2);
    fossil_vector_push_back(&mock_vector, element3);

    // Check if the elements are added correctly
    ASSUME_ITS_EQUAL_U32(3, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, mock_vector->data[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[2].value.int_val);
}

FOSSIL_TEST(test_vector_search) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(&mock_vector, element1);
    fossil_vector_push_back(&mock_vector, element2);
    fossil_vector_push_back(&mock_vector, element3);

    // Search for elements
    ASSUME_ITS_EQUAL_I32(0, fossil_vector_search(&mock_vector, element1));
    ASSUME_ITS_EQUAL_I32(1, fossil_vector_search(&mock_vector, element2));
    ASSUME_ITS_EQUAL_I32(2, fossil_vector_search(&mock_vector, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = fossil_tofu_create("int", "100");
    ASSUME_ITS_EQUAL_I32(-1, fossil_vector_search(&mock_vector, nonExistingElement));

    fossil_tofu_erase(&nonExistingElement);
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
