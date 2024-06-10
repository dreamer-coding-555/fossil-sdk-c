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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

#include <fossil/xjellyfish/braincoral.h> // library under test

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define network architecture parameters
enum {
    NLG_TEST_INPUT_SIZE = 10,
    NLG_TEST_OUTPUT_SIZE = 20
};

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

XTEST(test_FOSSIL_jellyfish_braincoral_tom_update_belief) {
    jellyfish_matrix* belief = FOSSIL_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* observation = FOSSIL_jellyfish_create_matrix(1, 3);
    
    // Initialize belief and observation with some dummy values
    for (int i = 0; i < 3; i++) {
        belief->data[0][i] = i + 1;
        observation->data[0][i] = (i + 1) * 2;
    }

    FOSSIL_jellyfish_braincoral_tom_update_belief(belief, observation);

    // Check if the belief is updated correctly (dummy test, real test would check for correct values)
    TEST_ASSUME_NOT_CNULLPTR(belief);

    FOSSIL_jellyfish_erase_matrix(belief);
    FOSSIL_jellyfish_erase_matrix(observation);
}

XTEST(test_FOSSIL_jellyfish_braincoral_tom_combine_beliefs) {
    jellyfish_matrix* belief1 = FOSSIL_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* belief2 = FOSSIL_jellyfish_create_matrix(1, 3);

    // Initialize beliefs with some dummy values
    for (int i = 0; i < 3; i++) {
        belief1->data[0][i] = i + 1;
        belief2->data[0][i] = (i + 1) * 3;
    }

    jellyfish_matrix* combined_belief = FOSSIL_jellyfish_braincoral_tom_combine_beliefs(belief1, belief2);

    TEST_ASSUME_NOT_CNULLPTR(combined_belief);
    TEST_ASSUME_EQUAL_INT(1, combined_belief->rows);
    TEST_ASSUME_EQUAL_INT(3, combined_belief->cols);

    FOSSIL_jellyfish_erase_matrix(belief1);
    FOSSIL_jellyfish_erase_matrix(belief2);
    FOSSIL_jellyfish_erase_matrix(combined_belief);
}

XTEST(test_FOSSIL_jellyfish_braincoral_tom_infer_desire) {
    jellyfish_matrix* behavior = FOSSIL_jellyfish_create_matrix(1, 3);
    
    // Initialize behavior with some dummy values
    for (int i = 0; i < 3; i++) {
        behavior->data[0][i] = (i + 1) * 2;
    }

    jellyfish_matrix* desire = FOSSIL_jellyfish_braincoral_tom_infer_desire(behavior);

    TEST_ASSUME_NOT_CNULLPTR(desire);
    TEST_ASSUME_EQUAL_INT(1, desire->rows);
    TEST_ASSUME_EQUAL_INT(3, desire->cols);

    FOSSIL_jellyfish_erase_matrix(behavior);
    FOSSIL_jellyfish_erase_matrix(desire);
}

XTEST(test_FOSSIL_jellyfish_braincoral_tom_infer_intention) {
    jellyfish_matrix* behavior = FOSSIL_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* context = FOSSIL_jellyfish_create_matrix(1, 3);

    // Initialize behavior and context with some dummy values
    for (int i = 0; i < 3; i++) {
        behavior->data[0][i] = (i + 1) * 2;
        context->data[0][i] = (i + 1) * 3;
    }

    jellyfish_matrix* intention = FOSSIL_jellyfish_braincoral_tom_infer_intention(behavior, context);

    TEST_ASSUME_NOT_CNULLPTR(intention);
    TEST_ASSUME_EQUAL_INT(1, intention->rows);
    TEST_ASSUME_EQUAL_INT(3, intention->cols);

    FOSSIL_jellyfish_erase_matrix(behavior);
    FOSSIL_jellyfish_erase_matrix(context);
    FOSSIL_jellyfish_erase_matrix(intention);
}

XTEST(test_FOSSIL_jellyfish_braincoral_tom_recognize_emotion) {
    jellyfish_matrix* text_data = FOSSIL_jellyfish_create_matrix(1, 5);
    
    // Initialize text_data with some dummy values
    for (int i = 0; i < 5; i++) {
        text_data->data[0][i] = (i + 1) * 2;
    }

    jellyfish_matrix* emotion = FOSSIL_jellyfish_braincoral_tom_recognize_emotion(text_data);

    TEST_ASSUME_NOT_CNULLPTR(emotion);
    TEST_ASSUME_EQUAL_INT(1, emotion->rows);
    TEST_ASSUME_EQUAL_INT(5, emotion->cols);

    FOSSIL_jellyfish_erase_matrix(text_data);
    FOSSIL_jellyfish_erase_matrix(emotion);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(braincoral_group) {
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_braincoral_tom_update_belief);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_braincoral_tom_combine_beliefs);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_braincoral_tom_infer_desire);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_braincoral_tom_infer_intention);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_braincoral_tom_recognize_emotion);
} // end of fixture
