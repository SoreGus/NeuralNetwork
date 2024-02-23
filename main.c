#include "matrix.h"

int main(int argc, char *argv[]) {
    Matrix *first = createMatrix(5,5);
    fillMatrix(first, 1);
    saveMatrix(first, "matrix");
    freeMatrix(first);

    Matrix *second = loadMatrix("matrix");
    printMatrix(second);
    freeMatrix(second);
    return 0;
}
