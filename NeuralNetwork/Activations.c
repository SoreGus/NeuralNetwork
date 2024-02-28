#include "Activations.h"
#include <math.h>
#include "../Matrix/matrixOperations.h"

double sigmoid(double value) {
    return 1.0 / (1 + exp(-1 * value));
}

Matrix* sigmoidPrime(Matrix* matrix) {
    Matrix* ones = createMatrix(matrix->rows, matrix->columns);
    fillMatrix(ones, 1);
    Matrix* subtracted = applyMatrixOperation(ones, matrix, SUB);
    Matrix* multiplied = applyMatrixOperation(matrix, subtracted, MULT);
    freeMatrix(ones);
    freeMatrix(subtracted);
    return multiplied;
}

Matrix* softmax(Matrix* matrix) {
    double total;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            total += exp(matrix->data[i][j]);
        }
    }
    Matrix* newMatrix = createMatrix(matrix->rows, matrix->columns);
    for (int i = 0; i < newMatrix->rows; i++) {
        for (int j = 0; j < newMatrix->columns; j++) {
            newMatrix->data[i][j] = exp(matrix->data[i][j]) / total;
        }
    }
    return newMatrix;
}
