#pragma once

#include "../Matrix/matrix.h"
#include "../Util/Image.h"

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
NeuralNetwork* loadNeuralNetwork(char* path);
Matrix* predict(NeuralNetwork* network, Matrix* input);
Matrix* predictFromImage(NeuralNetwork* network, Image* image);
double predictOnImages(NeuralNetwork* network, Image** images, int number);

