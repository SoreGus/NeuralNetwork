#include "Matrix/matrixOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include "Util/Image.h"
#include "NeuralNetwork/Activations.h"
#include "NeuralNetwork/NeuralNetwork.h"
#include <time.h>

int main(int argc, char *argv[]) {

    srand(time(NULL));

    // int numberOfImages = 59000;
	// Image** images = readImagesFromFile("./data/mnist_train.csv", numberOfImages);
	// NeuralNetwork* network = createNeuralNetwork(784, 300, 10, 0.1);
	// trainWithImages(network, images, numberOfImages);
	// saveNeuralNetwork(network, "testing_net");

    int numberOfImages = 3000;
	Image** images = readImagesFromFile("data/mnist_test.csv", numberOfImages);
	NeuralNetwork* network = loadNeuralNetwork("testing_net");
	double score = predictOnImages(network, images, numberOfImages);
	printf("Score: %1.5f\n", score);

    freeImages(images, numberOfImages);
	freeNeuralNetwork(network);

    return 0;
}
