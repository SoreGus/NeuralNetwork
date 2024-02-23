#include "Matrix/matrixOperations.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Matrix *first = createMatrix(3,3);
    fillMatrix(first, 3);
    printMatrix(first);

    Matrix *second = createMatrix(3,3);
    fillMatrix(second, 2);
    printMatrix(second);

    Matrix *sunResult = applyMatrixOperation(first, second, SUN);
    Matrix *multResult = applyMatrixOperation(first, second, MULT);
    Matrix *subResult = applyMatrixOperation(first, second, SUB);

    printMatrix(sunResult);
    printMatrix(multResult);
    printMatrix(subResult);

    freeMatrix(first);
    freeMatrix(second);
    freeMatrix(sunResult);
    freeMatrix(multResult);
    freeMatrix(subResult);

    return 0;
}
