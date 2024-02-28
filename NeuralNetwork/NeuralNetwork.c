#include "NeuralNetwork.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAXCHAR 100

NeuralNetwork* createNeuralNetwork(int inputSize, int hiddenSize, int outputSize, double learingRate) {
    NeuralNetwork* network = malloc(sizeof(NeuralNetwork*));
    network->inputSize = inputSize;
    network->hiddenSize = hiddenSize;
    network->learningRate = learingRate;
    Matrix* hiddenLayer = createMatrix(hiddenSize, inputSize);
    Matrix* outputLayer = createMatrix(outputSize, hiddenSize);
    randomizeMatrix(hiddenLayer, hiddenSize);
    randomizeMatrix(outputLayer, outputSize);
    network->hiddenWeights = hiddenLayer;
    network->outputWeights = outputLayer;
    return network;
}

void freeNeuralNetwork(NeuralNetwork* network) {
    freeMatrix(network->hiddenWeights);
    network->hiddenWeights = NULL;

    freeMatrix(network->outputWeights);
    network->outputWeights = NULL;

    free(network);
    network = NULL;
}

void printNeuralNetwork(NeuralNetwork* network) {
    printf("# of Inputs: %d\n", network->inputSize);
	printf("# of Hidden: %d\n", network->hiddenSize);
	printf("# of Output: %d\n", network->outputSize);
	printf("Hidden Weights: \n");
	printMatrix(network->hiddenWeights);
	printf("Output Weights: \n");
	printMatrix(network->hiddenWeights);
}

void saveNeuralNetwork(NeuralNetwork* network, char* path) {
	mkdir(path, 0777);
	chdir(path);
	FILE* file = fopen("descriptor", "w");
	fprintf(file, "%d\n", network->inputSize);
	fprintf(file, "%d\n", network->hiddenSize);
	fprintf(file, "%d\n", network->outputSize);
	fclose(file);
	saveMatrix(network->hiddenWeights, "hidden");
	saveMatrix(network->outputWeights, "output");
	printf("Successfully written to '%s'\n", path);
	chdir("-");
}

NeuralNetwork* loadNeuralNetwork(char* path) {
	NeuralNetwork* network = malloc(sizeof(NeuralNetwork*));
	char entry[MAXCHAR];
	chdir(path);

	FILE* descriptorFile = fopen("descriptor", "r");
	fgets(entry, MAXCHAR, descriptorFile);
	network->inputSize = atoi(entry);
	fgets(entry, MAXCHAR, descriptorFile);
	network->hiddenSize = atoi(entry);
	fgets(entry, MAXCHAR, descriptorFile);
	network->outputSize = atoi(entry);
	fclose(descriptorFile);
	network->hiddenWeights = loadMatrix("hidden");
	network->outputWeights = loadMatrix("output");
	printf("Successfully loaded network from '%s'\n", path);
	chdir("-");
	return network;
}

