#include "Matrix/matrixOperations.h"
#include <stdio.h>
#include "Util/Image.h"
#include "NeuralNetwork/Activations.h"
#include "NeuralNetwork/NeuralNetwork.h"

int main(int argc, char *argv[]) {

    NeuralNetwork* network = createNeuralNetwork(30, 10, 10, 0.1);
    Matrix *matrix = network->hiddenWeights;
    printMatrix(matrix);
    saveNeuralNetwork(network, "NetworkData");
    freeMatrix(matrix);
    freeNeuralNetwork(network);

    return 0;
}
