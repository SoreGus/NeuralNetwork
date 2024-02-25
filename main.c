#include "Matrix/matrixOperations.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    Matrix *matrix = createMatrix(5, 5);
    fillMatrix(matrix, 3);
    printMatrix(matrix);
    matrix = scaleMatrix(matrix, 2, SUN);
    printMatrix(matrix);
    matrix = scaleMatrix(matrix, 2, MULT);
    printMatrix(matrix);
    freeMatrix(matrix);

    return 0;
}
