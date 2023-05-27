#ifndef MNIST_TESTER
#define MNIST_TESTER


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// #include "include/mnist_file.h"
#include "include/neural_network.h"
#include "trained_net.c"
#include "gen_test_set.c"

// const char * test_images_file = "data/t10k-images-idx3-ubyte";
// const char * test_labels_file = "data/t10k-labels-idx1-ubyte";


/**
 * Calculate the accuracy of the predictions of a neural network on a dataset.
 */
float calculate_accuracy(mnist_dataset_t * dataset, neural_network_t * network)
{
    float activations[MNIST_LABELS], max_activation;
    int i, j, correct, predict;

    // Loop through the dataset
    for (i = 0, correct = 0; i < dataset->size; i++) {
        // Calculate the activations for each image using the neural network
        neural_network_hypothesis(&dataset->images[i], network, activations);

        // Set predict to the index of the greatest activation
        for (j = 0, predict = 0, max_activation = activations[0]; j < MNIST_LABELS; j++) {
            if (max_activation < activations[j]) {
                max_activation = activations[j];
                predict = j;
            }
        }

        // Increment the correct count if we predicted the right label
        if (predict == dataset->labels[i]) {
            correct++;
        }
        else
            printf("%d: predicted %d insead of %d\n", i, predict, dataset->labels[i]);
    }

    // Return the percentage we predicted correctly as the accuracy
    return ((float) correct) / ((float) dataset->size);
}

int main(int argc, char *argv[])
{
    // mnist_dataset_t * test_dataset;
    // float accuracy;

    // Read the datasets from the files
    // test_dataset = mnist_get_dataset(test_images_file, test_labels_file);
    
    // accuracy = calculate_accuracy(test_dataset, &trained_net);
    // printf("Model Accuracy: %f\n", accuracy);

    printf("Model Accuracy: %f\n", calculate_accuracy(&test_set, &trained_net));


/*
    float activations[MNIST_LABELS], max_activation;
    int j, predict;
    neural_network_hypothesis(&(test_set.images[0]), &trained_net, activations);
    for (j = 0, predict = 0, max_activation = activations[0]; j < MNIST_LABELS; j++) {
        printf("%d: %f\n", j, activations[j]);
        if (max_activation < activations[j]) {
            max_activation = activations[j];
            predict = j;
        }
    }
    printf("Predicted: %d\n", predict);

*/

    // Cleanup
    // mnist_free_dataset(test_dataset);
    return 0;
}

#endif
