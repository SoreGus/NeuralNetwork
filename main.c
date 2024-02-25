#include "Matrix/matrixOperations.h"
#include <stdio.h>

double apply(double input) {
	return input * 3;
}

int main(int argc, char *argv[]) {

    Matrix *matrix = createMatrix(5, 5);
    fillMatrix(matrix, 3);
    printMatrix(matrix);
    matrix = applyFunctionOnMatrix(apply, matrix);
    printMatrix(matrix);
    freeMatrix(matrix);

    return 0;
}
