#include "matrix.h"
typedef enum {
    SUN,
    SUB,
    MULT
} MatrixOperation;


Matrix* applyMatrixOperation(Matrix* firstMatrix, Matrix* secondMatrix, MatrixOperation operation);
