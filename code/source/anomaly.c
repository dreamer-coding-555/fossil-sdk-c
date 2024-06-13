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
#include "fossil/jellyfish/anomaly.h"
#include <math.h>
#include <stdlib.h>

// Calculate the Euclidean distance between two vectors
double fossil_jellyfish_anomaly_euclidean_distance(jellyfish_matrix_t* a, jellyfish_matrix_t* b) {
    double distance = 0.0;
    for (int i = 0; i < a->cols; i++) {
        double diff = a->data[0][i] - b->data[0][i];
        distance += diff * diff;
    }
    return sqrt(distance);
}

// Calculate the Mahalanobis distance between a vector and a distribution
double fossil_jellyfish_anomaly_mahalanobis_distance(jellyfish_matrix_t* vec, jellyfish_matrix_t* mean, jellyfish_matrix_t* covariance) {
    jellyfish_matrix_t* diff = fossil_jellyfish_subtract(vec, mean);
    jellyfish_matrix_t* trans_diff = fossil_jellyfish_transpose(diff);
    jellyfish_matrix_t* inv_cov = fossil_jellyfish_inverse(covariance); // Assume fossil_jellyfish_inverse is implemented
    jellyfish_matrix_t* left_mult = fossil_jellyfish_multiply(trans_diff, inv_cov);
    jellyfish_matrix_t* result = fossil_jellyfish_multiply(left_mult, diff);
    double distance = sqrt(result->data[0][0]);
    fossil_jellyfish_erase_matrix(diff);
    fossil_jellyfish_erase_matrix(trans_diff);
    fossil_jellyfish_erase_matrix(inv_cov);
    fossil_jellyfish_erase_matrix(left_mult);
    fossil_jellyfish_erase_matrix(result);
    return distance;
}

// Perform k-means clustering
void fossil_jellyfish_anomaly_kmeans(jellyfish_matrix_t* data, int k, int max_iterations, jellyfish_matrix_t* centroids, int* labels) {
    int n = data->rows;
    int dims = data->cols;
    
    // Initialize centroids randomly
    for (int i = 0; i < k; i++) {
        int index = rand() % n;
        for (int j = 0; j < dims; j++) {
            centroids->data[i][j] = data->data[index][j];
        }
    }

    for (int iter = 0; iter < max_iterations; iter++) {
        // Assign labels based on closest centroid
        for (int i = 0; i < n; i++) {
            double min_dist = INFINITY;
            int best_centroid = -1;
            for (int j = 0; j < k; j++) {
                double dist = fossil_jellyfish_anomaly_euclidean_distance(&data[i], &centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    best_centroid = j;
                }
            }
            labels[i] = best_centroid;
        }

        // Update centroids
        jellyfish_matrix_t* new_centroids = fossil_jellyfish_create_matrix(k, dims);
        int* counts = (int*)calloc(k, sizeof(int));
        
        for (int i = 0; i < n; i++) {
            int label = labels[i];
            for (int j = 0; j < dims; j++) {
                new_centroids->data[label][j] += data->data[i][j];
            }
            counts[label]++;
        }
        
        for (int i = 0; i < k; i++) {
            if (counts[i] == 0) continue;
            for (int j = 0; j < dims; j++) {
                new_centroids->data[i][j] /= counts[i];
            }
        }
        
        fossil_jellyfish_erase_matrix(centroids);
        centroids = new_centroids;
        free(counts);
    }
}

// Identify outliers based on distance to cluster centroids
jellyfish_matrix_t* fossil_jellyfish_anomaly_identify_outliers(jellyfish_matrix_t* data, jellyfish_matrix_t* centroids, double threshold) {
    int n = data->rows;
    jellyfish_matrix_t* outliers = fossil_jellyfish_create_matrix(n, 1); // 1 column for binary outlier flag
    
    for (int i = 0; i < n; i++) {
        double min_dist = INFINITY;
        for (int j = 0; j < centroids->rows; j++) {
            double dist = fossil_jellyfish_anomaly_euclidean_distance(&data[i], &centroids[j]);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
        outliers->data[i][0] = (min_dist > threshold) ? 1.0 : 0.0;
    }
    
    return outliers;
}

// Train an autoencoder for anomaly detection
void fossil_jellyfish_anomaly_train_autoencoder(jellyfish_matrix_t* data, jellyfish_layer_t* encoder, jellyfish_layer_t* decoder, int epochs, double learning_rate) {
    for (int epoch = 0; epoch < epochs; epoch++) {
        for (int i = 0; i < data->rows; i++) {
            jellyfish_matrix_t* input = &data[i];
            jellyfish_matrix_t* encoded = fossil_jellyfish_forward(input, encoder);
            jellyfish_matrix_t* reconstructed = fossil_jellyfish_forward(encoded, decoder);
            
            // Compute loss and backpropagate
            fossil_jellyfish_mse(input, reconstructed);
            jellyfish_matrix_t* d_loss = fossil_jellyfish_subtract(reconstructed, input);
            fossil_jellyfish_backward(decoder, encoded, input, d_loss, learning_rate);
            fossil_jellyfish_backward(encoder, input, input, d_loss, learning_rate);
            
            fossil_jellyfish_erase_matrix(encoded);
            fossil_jellyfish_erase_matrix(reconstructed);
            fossil_jellyfish_erase_matrix(d_loss);
        }
    }
}

// Detect anomalies using an autoencoder
jellyfish_matrix_t* fossil_jellyfish_anomaly_detect_with_autoencoder(jellyfish_matrix_t* data, jellyfish_layer_t* encoder, jellyfish_layer_t* decoder, double threshold) {
    jellyfish_matrix_t* anomalies = fossil_jellyfish_create_matrix(data->rows, 1); // 1 column for binary anomaly flag
    
    for (int i = 0; i < data->rows; i++) {
        jellyfish_matrix_t* input = &data[i];
        jellyfish_matrix_t* encoded = fossil_jellyfish_forward(input, encoder);
        jellyfish_matrix_t* reconstructed = fossil_jellyfish_forward(encoded, decoder);
        
        double error = fossil_jellyfish_anomaly_reconstruction_error(input, reconstructed);
        anomalies->data[i][0] = (error > threshold) ? 1.0 : 0.0;
        
        fossil_jellyfish_erase_matrix(encoded);
        fossil_jellyfish_erase_matrix(reconstructed);
    }
    
    return anomalies;
}

// Reconstruction error
double fossil_jellyfish_anomaly_reconstruction_error(jellyfish_matrix_t* input, jellyfish_matrix_t* reconstructed) {
    return fossil_jellyfish_mse(input, reconstructed);
}
