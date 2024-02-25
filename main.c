#include "Matrix/matrixOperations.h"
#include <stdio.h>

double apply(double input) {
	return input * 3;
}

int main(int argc, char *argv[]) {

    Matrix *matrix = createMatrix(3, 2);
    fillMatrix(matrix, 1);
    printMatrix(matrix);
    matrix = transposeMatrix(matrix);
    printMatrix(matrix);
    freeMatrix(matrix);

    return 0;
}
