typedef struct
{
    double **data;
    int rows;
    int columns;
}Matrix;

Matrix* createMatrix(int rows, int columns);
void printMatrix(Matrix *matrix);
void fillMatrix(Matrix *matrix, double value);
void freeMatrix(Matrix *matrix);
Matrix* copyMatrix(Matrix *matrix);
void saveMatrix(Matrix *matrix, char* path);
Matrix* loadMatrix(char* path);
