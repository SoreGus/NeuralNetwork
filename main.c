#include "Matrix/matrixOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include "Util/Image.h"
#include "NeuralNetwork/Activations.h"
#include "NeuralNetwork/NeuralNetwork.h"
#include <time.h>

int main(int argc, char *argv[]) {

    printf("NeuralNetwork - Kaggle - MNIST in CSV\nhttps://www.kaggle.com/datasets/oddrationale/mnist-in-csv\n");
    printf("1 - Traing\n");
    printf("2 - Predict\n");
    printf("Any Other - Exit\n");
    int option = 0;
    scanf("%d", &option);
    srand(time(NULL));
    NeuralNetwork* network;
    Image** images;
    printf("How mane images? (Max 60000)\n");
    int numberOfImages = 0;
    scanf("%d", &numberOfImages);
    if (numberOfImages > 60000) numberOfImages = 6000;
    switch (option)
    {
    case 1:
        images = readImagesFromFile("./data/mnist_train.csv", numberOfImages);
        network = createNeuralNetwork(784, 300, 10, 0.1);
        trainWithImages(network, images, numberOfImages);
        saveNeuralNetwork(network, "testing_net");
        break;
    case 2:
        images = readImagesFromFile("data/mnist_test.csv", numberOfImages);
        network = loadNeuralNetwork("testing_net");
        double score = predictOnImages(network, images, numberOfImages);
        printf("Score: %1.5f\n", score);
        break;
    default:
        break;
        exit(0);
    }

    freeImages(images, numberOfImages);
	freeNeuralNetwork(network);

    return 0;
}
