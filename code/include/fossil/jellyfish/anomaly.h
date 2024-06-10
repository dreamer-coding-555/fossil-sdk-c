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
#ifndef FOSSIL_JELLYFISH_AI_ANOMALY_H
#define FOSSIL_JELLYFISH_AI_ANOMALY_H

#include "jellyfish.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ========================================================================
// create and erase functions
// ========================================================================

/** Calculate the Euclidean distance between two matrices.
 * Parameters:
 * - a: The first matrix.
 * - b: The second matrix.
 * Returns:
 * - The Euclidean distance between the two matrices.
 */
double fossil_jellyfish_anomaly_euclidean_distance(jellyfish_matrix* a, jellyfish_matrix* b);

/** Calculate the Mahalanobis distance between a vector and a distribution.
 * Parameters:
 * - vec: The vector.
 * - mean: The mean of the distribution.
 * - covariance: The covariance matrix of the distribution.
 * Returns:
 * - The Mahalanobis distance between the vector and the distribution.
 */
double fossil_jellyfish_anomaly_mahalanobis_distance(jellyfish_matrix* vec, jellyfish_matrix* mean, jellyfish_matrix* covariance);

/** Perform k-means clustering on the given data.
 * Parameters:
 * - data: The data matrix.
 * - k: The number of clusters.
 * - max_iterations: The maximum number of iterations.
 * - centroids: The matrix to store the resulting centroids.
 * - labels: The array to store the resulting labels.
 */
void fossil_jellyfish_anomaly_kmeans(jellyfish_matrix* data, int k, int max_iterations, jellyfish_matrix* centroids, int* labels);

/** Identify outliers based on the distance to cluster centroids.
 * Parameters:
 * - data: The data matrix.
 * - centroids: The matrix of cluster centroids.
 * - threshold: The threshold for identifying outliers.
 * Returns:
 * - A matrix containing the identified outliers.
 */
jellyfish_matrix* fossil_jellyfish_anomaly_identify_outliers(jellyfish_matrix* data, jellyfish_matrix* centroids, double threshold);

/** Train an autoencoder for anomaly detection.
 * Parameters:
 * - data: The training data matrix.
 * - encoder: The encoder layer of the autoencoder.
 * - decoder: The decoder layer of the autoencoder.
 * - epochs: The number of training epochs.
 * - learning_rate: The learning rate for training.
 */
void fossil_jellyfish_anomaly_train_autoencoder(jellyfish_matrix* data, jellyfish_layer* encoder, jellyfish_layer* decoder, int epochs, double learning_rate);

/** Detect anomalies using an autoencoder.
 * Parameters:
 * - data: The data matrix.
 * - encoder: The encoder layer of the autoencoder.
 * - decoder: The decoder layer of the autoencoder.
 * - threshold: The threshold for detecting anomalies.
 * Returns:
 * - A matrix containing the detected anomalies.
 */
jellyfish_matrix* fossil_jellyfish_anomaly_detect_with_autoencoder(jellyfish_matrix* data, jellyfish_layer* encoder, jellyfish_layer* decoder, double threshold);

/** Calculate the reconstruction error between the input and the reconstructed matrix.
 * Parameters:
 * - input: The input matrix.
 * - reconstructed: The reconstructed matrix.
 * Returns:
 * - The reconstruction error.
 */
double fossil_jellyfish_anomaly_reconstruction_error(jellyfish_matrix* input, jellyfish_matrix* reconstructed);

#ifdef __cplusplus
}
#endif

#endif
