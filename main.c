#include "Matrix/matrixOperations.h"
#include <stdio.h>
#include "Util/Image.h"
#include "NeuralNetwork/Activations.h"

int main(int argc, char *argv[]) {

    char buffer[100];
    Image** images = readImagesFromFile("data/mnist_train.csv", 10);
    Matrix *matrix = images[0]->data;
    Matrix* sigmoidedMatrix = sigmoidPrime(matrix);
    Image* image = imageFromMatrix(sigmoidedMatrix, -1);
    saveJPEGImage("test.jpg", image);
    freeImages(images, 10);
    freeImage(image);
    freeMatrix(matrix);

    return 0;
}
