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
#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

#include <fossil/jellyfish/anomaly.h> // library under test

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

FOSSIL_TEST(test_fossil_jellyfish_anomaly_euclidean_distance) {
    jellyfish_matrix_t* a = fossil_jellyfish_create_matrix(1, 3);
    jellyfish_matrix_t* b = fossil_jellyfish_create_matrix(1, 3);

    // Initialize vectors a and b with some dummy values
    a->data[0][0] = 1.0; a->data[0][1] = 2.0; a->data[0][2] = 3.0;
    b->data[0][0] = 4.0; b->data[0][1] = 5.0; b->data[0][2] = 6.0;

    double distance = fossil_jellyfish_anomaly_euclidean_distance(a, b);

    // Expected distance calculation
    double expected_distance = sqrt(pow(4.0 - 1.0, 2) + pow(5.0 - 2.0, 2) + pow(6.0 - 3.0, 2));
    ASSUME_ITS_WITHIN_RANGE_F64(1e-6, expected_distance, distance);

    fossil_jellyfish_erase_matrix(a);
    fossil_jellyfish_erase_matrix(b);
}

FOSSIL_TEST(test_fossil_jellyfish_anomaly_mahalanobis_distance) {
    jellyfish_matrix_t* vec = fossil_jellyfish_create_matrix(1, 2);
    jellyfish_matrix_t* mean = fossil_jellyfish_create_matrix(1, 2);
    jellyfish_matrix_t* covariance = fossil_jellyfish_create_matrix(2, 2);

    // Initialize vec, mean, and covariance with dummy values
    vec->data[0][0] = 1.0; vec->data[0][1] = 2.0;
    mean->data[0][0] = 0.0; mean->data[0][1] = 0.0;
    covariance->data[0][0] = 1.0; covariance->data[0][1] = 0.0;
    covariance->data[1][0] = 0.0; covariance->data[1][1] = 1.0;

    double distance = fossil_jellyfish_anomaly_mahalanobis_distance(vec, mean, covariance);

    // Expected distance (since covariance is identity, should be same as Euclidean distance)
    double expected_distance = sqrt(pow(1.0, 2) + pow(2.0, 2));
    ASSUME_ITS_WITHIN_RANGE_F64(1e-6, expected_distance, distance);

    fossil_jellyfish_erase_matrix(vec);
    fossil_jellyfish_erase_matrix(mean);
    fossil_jellyfish_erase_matrix(covariance);
}

FOSSIL_TEST(test_fossil_jellyfish_anomaly_kmeans) {
    jellyfish_matrix_t* data = fossil_jellyfish_create_matrix(4, 2);
    int k = 2;
    int max_iterations = 100;
    jellyfish_matrix_t* centroids = fossil_jellyfish_create_matrix(k, 2);
    int labels[4];

    // Initialize data with some dummy values
    data->data[0][0] = 1.0; data->data[0][1] = 1.0;
    data->data[1][0] = 1.5; data->data[1][1] = 2.0;
    data->data[2][0] = 3.0; data->data[2][1] = 4.0;
    data->data[3][0] = 5.0; data->data[3][1] = 7.0;

    fossil_jellyfish_anomaly_kmeans(data, k, max_iterations, centroids, labels);

    // Check if centroids are not NULL and labels are correctly assigned
    ASSUME_NOT_CNULL(centroids);
    ASSUME_ITS_EQUAL_I32(2, centroids->rows);
    ASSUME_ITS_EQUAL_I32(2, centroids->cols);

    fossil_jellyfish_erase_matrix(data);
    fossil_jellyfish_erase_matrix(centroids);
}

FOSSIL_TEST(test_fossil_jellyfish_anomaly_identify_outliers) {
    jellyfish_matrix_t* data = fossil_jellyfish_create_matrix(4, 2);
    jellyfish_matrix_t* centroids = fossil_jellyfish_create_matrix(2, 2);
    double threshold = 3.0;

    // Initialize data and centroids with some dummy values
    data->data[0][0] = 1.0; data->data[0][1] = 1.0;
    data->data[1][0] = 1.5; data->data[1][1] = 2.0;
    data->data[2][0] = 3.0; data->data[2][1] = 4.0;
    data->data[3][0] = 5.0; data->data[3][1] = 7.0;

    centroids->data[0][0] = 1.0; centroids->data[0][1] = 1.5;
    centroids->data[1][0] = 4.0; centroids->data[1][1] = 5.5;

    jellyfish_matrix_t* outliers = fossil_jellyfish_anomaly_identify_outliers(data, centroids, threshold);

    // Check if outliers matrix is not NULL
    ASSUME_NOT_CNULL(outliers);

    fossil_jellyfish_erase_matrix(data);
    fossil_jellyfish_erase_matrix(centroids);
    fossil_jellyfish_erase_matrix(outliers);
}

FOSSIL_TEST(test_fossil_jellyfish_anomaly_reconstruction_error) {
    jellyfish_matrix_t* input = fossil_jellyfish_create_matrix(1, 3);
    jellyfish_matrix_t* reconstructed = fossil_jellyfish_create_matrix(1, 3);

    // Initialize input and reconstructed with some dummy values
    input->data[0][0] = 1.0; input->data[0][1] = 2.0; input->data[0][2] = 3.0;
    reconstructed->data[0][0] = 1.1; reconstructed->data[0][1] = 1.9; reconstructed->data[0][2] = 3.05;

    double error = fossil_jellyfish_anomaly_reconstruction_error(input, reconstructed);

    // Expected error calculation
    double expected_error = (pow(1.0 - 1.1, 2) + pow(2.0 - 1.9, 2) + pow(3.0 - 3.05, 2)) / 3;
    ASSUME_ITS_WITHIN_RANGE_F64(1e-6, expected_error, error);

    fossil_jellyfish_erase_matrix(input);
    fossil_jellyfish_erase_matrix(reconstructed);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(anomaly_group) {
    ADD_TEST(test_fossil_jellyfish_anomaly_euclidean_distance);
    ADD_TEST(test_fossil_jellyfish_anomaly_mahalanobis_distance);
    ADD_TEST(test_fossil_jellyfish_anomaly_kmeans);
    ADD_TEST(test_fossil_jellyfish_anomaly_identify_outliers);
    ADD_TEST(test_fossil_jellyfish_anomaly_reconstruction_error);
} // end of fixture
