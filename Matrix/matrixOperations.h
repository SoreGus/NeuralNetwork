#include "matrix.h"

typedef enum {
    SUN,
    SUB,
    MULT
} MatrixOperation;

Matrix* applyMatrixOperation(Matrix* firstMatrix, Matrix* secondMatrix, MatrixOperation operation);
Matrix* scaleMatrix(Matrix* matrix, double value, MatrixOperation operation);
Matrix* transposeMatrix(Matrix* matrix);
Matrix* applyFunctionOnMatrix(double (*func)(double), Matrix* matrix);
Matrix* dot(Matrix* firstMatrix, Matrix* secondMatrix);
