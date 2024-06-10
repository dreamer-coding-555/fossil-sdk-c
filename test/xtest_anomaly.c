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

#include <fossil/xjellyfish/anomaly.h> // library under test

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

XTEST(test_FOSSIL_jellyfish_anomaly_euclidean_distance) {
    jellyfish_matrix* a = FOSSIL_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* b = FOSSIL_jellyfish_create_matrix(1, 3);

    // Initialize vectors a and b with some dummy values
    a->data[0][0] = 1.0; a->data[0][1] = 2.0; a->data[0][2] = 3.0;
    b->data[0][0] = 4.0; b->data[0][1] = 5.0; b->data[0][2] = 6.0;

    double distance = FOSSIL_jellyfish_anomaly_euclidean_distance(a, b);

    // Expected distance calculation
    double expected_distance = sqrt(pow(4.0 - 1.0, 2) + pow(5.0 - 2.0, 2) + pow(6.0 - 3.0, 2));
    TEST_ASSUME_DOUBLE_WITHIN(1e-6, expected_distance, distance);

    FOSSIL_jellyfish_erase_matrix(a);
    FOSSIL_jellyfish_erase_matrix(b);
}

XTEST(test_FOSSIL_jellyfish_anomaly_mahalanobis_distance) {
    jellyfish_matrix* vec = FOSSIL_jellyfish_create_matrix(1, 2);
    jellyfish_matrix* mean = FOSSIL_jellyfish_create_matrix(1, 2);
    jellyfish_matrix* covariance = FOSSIL_jellyfish_create_matrix(2, 2);

    // Initialize vec, mean, and covariance with dummy values
    vec->data[0][0] = 1.0; vec->data[0][1] = 2.0;
    mean->data[0][0] = 0.0; mean->data[0][1] = 0.0;
    covariance->data[0][0] = 1.0; covariance->data[0][1] = 0.0;
    covariance->data[1][0] = 0.0; covariance->data[1][1] = 1.0;

    double distance = FOSSIL_jellyfish_anomaly_mahalanobis_distance(vec, mean, covariance);

    // Expected distance (since covariance is identity, should be same as Euclidean distance)
    double expected_distance = sqrt(pow(1.0, 2) + pow(2.0, 2));
    TEST_ASSUME_DOUBLE_WITHIN(1e-6, expected_distance, distance);

    FOSSIL_jellyfish_erase_matrix(vec);
    FOSSIL_jellyfish_erase_matrix(mean);
    FOSSIL_jellyfish_erase_matrix(covariance);
}

XTEST(test_FOSSIL_jellyfish_anomaly_kmeans) {
    jellyfish_matrix* data = FOSSIL_jellyfish_create_matrix(4, 2);
    int k = 2;
    int max_iterations = 100;
    jellyfish_matrix* centroids = FOSSIL_jellyfish_create_matrix(k, 2);
    int labels[4];

    // Initialize data with some dummy values
    data->data[0][0] = 1.0; data->data[0][1] = 1.0;
    data->data[1][0] = 1.5; data->data[1][1] = 2.0;
    data->data[2][0] = 3.0; data->data[2][1] = 4.0;
    data->data[3][0] = 5.0; data->data[3][1] = 7.0;

    FOSSIL_jellyfish_anomaly_kmeans(data, k, max_iterations, centroids, labels);

    // Check if centroids are not NULL and labels are correctly assigned
    TEST_ASSUME_NOT_CNULLPTR(centroids);
    TEST_ASSUME_EQUAL_INT(2, centroids->rows);
    TEST_ASSUME_EQUAL_INT(2, centroids->cols);

    FOSSIL_jellyfish_erase_matrix(data);
    FOSSIL_jellyfish_erase_matrix(centroids);
}

XTEST(test_FOSSIL_jellyfish_anomaly_identify_outliers) {
    jellyfish_matrix* data = FOSSIL_jellyfish_create_matrix(4, 2);
    jellyfish_matrix* centroids = FOSSIL_jellyfish_create_matrix(2, 2);
    double threshold = 3.0;

    // Initialize data and centroids with some dummy values
    data->data[0][0] = 1.0; data->data[0][1] = 1.0;
    data->data[1][0] = 1.5; data->data[1][1] = 2.0;
    data->data[2][0] = 3.0; data->data[2][1] = 4.0;
    data->data[3][0] = 5.0; data->data[3][1] = 7.0;

    centroids->data[0][0] = 1.0; centroids->data[0][1] = 1.5;
    centroids->data[1][0] = 4.0; centroids->data[1][1] = 5.5;

    jellyfish_matrix* outliers = FOSSIL_jellyfish_anomaly_identify_outliers(data, centroids, threshold);

    // Check if outliers matrix is not NULL
    TEST_ASSUME_NOT_CNULLPTR(outliers);

    FOSSIL_jellyfish_erase_matrix(data);
    FOSSIL_jellyfish_erase_matrix(centroids);
    FOSSIL_jellyfish_erase_matrix(outliers);
}

XTEST(test_FOSSIL_jellyfish_anomaly_reconstruction_error) {
    jellyfish_matrix* input = FOSSIL_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* reconstructed = FOSSIL_jellyfish_create_matrix(1, 3);

    // Initialize input and reconstructed with some dummy values
    input->data[0][0] = 1.0; input->data[0][1] = 2.0; input->data[0][2] = 3.0;
    reconstructed->data[0][0] = 1.1; reconstructed->data[0][1] = 1.9; reconstructed->data[0][2] = 3.05;

    double error = FOSSIL_jellyfish_anomaly_reconstruction_error(input, reconstructed);

    // Expected error calculation
    double expected_error = (pow(1.0 - 1.1, 2) + pow(2.0 - 1.9, 2) + pow(3.0 - 3.05, 2)) / 3;
    TEST_ASSUME_DOUBLE_WITHIN(1e-6, expected_error, error);

    FOSSIL_jellyfish_erase_matrix(input);
    FOSSIL_jellyfish_erase_matrix(reconstructed);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(anomaly_group) {
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_anomaly_euclidean_distance);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_anomaly_mahalanobis_distance);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_anomaly_kmeans);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_anomaly_identify_outliers);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_anomaly_reconstruction_error);
} // end of fixture
