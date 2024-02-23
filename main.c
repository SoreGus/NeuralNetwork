#include "matrix.h"

int main(int argc, char *argv[]) {
    Matrix *m = createMatrix(10, 10);
    Matrix *m2 = copyMatrix(m);
    fillMatrix(m, 0);
    printMatrix(m2);
    fillMatrix(m, 9);
    printMatrix(m);;
    printMatrix(m2);
    freeMatrix(m);
    freeMatrix(m2);
    return 0;
}
