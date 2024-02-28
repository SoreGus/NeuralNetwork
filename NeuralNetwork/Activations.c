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
