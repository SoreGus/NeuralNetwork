#include "matrix.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Matrix *matrix = createMatrix(3,3);
    randomizeMatrix(matrix, 2);
    Matrix *flatten = flattenMatrix(matrix, 0);
    int maxValueIndex = flattenMatrixMaxValueIndex(flatten);
    printMatrix(matrix);
    printMatrix(flatten);
    printf("MaxIndex: %d", maxValueIndex);
    freeMatrix(matrix);
    return 0;
}
