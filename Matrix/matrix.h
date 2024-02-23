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
double uniformDistribution(double low, double high);
void randomizeMatrix(Matrix *matrix, int number);
int flattenMatrixMaxValueIndex(Matrix *matrix);
Matrix* flattenMatrix(Matrix *matrix, int axis);
