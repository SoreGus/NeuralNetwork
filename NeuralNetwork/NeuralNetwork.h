#pragma once

#include "../Matrix/matrix.h"

typedef struct {
    int inputSize;
    int hiddenSize;
    int outputSize;
    double learningRate;
    Matrix* hiddenWeights;
    Matrix* outputWeights;
} NeuralNetwork;

NeuralNetwork* createNeuralNetwork(int inputSize, int hiddenSize, int outputSize, double learingRate);
void freeNeuralNetwork(NeuralNetwork* network);
void printNeuralNetwork(NeuralNetwork* network);
void saveNeuralNetwork(NeuralNetwork* network, char* path);


