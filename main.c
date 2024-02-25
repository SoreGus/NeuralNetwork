#include "Matrix/matrixOperations.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    Matrix *matrix = createMatrix(5, 5);
    randomizeMatrix(matrix, 2);
    printMatrix(matrix);
    matrix = transposeMatrix(matrix);
    printMatrix(matrix);
    freeMatrix(matrix);

    return 0;
}
