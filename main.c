#include "matrix.h"

int main(int argc, char *argv[]) {
    Matrix *m = create(10, 10);
    fill(m, 2);
    print(m);
    return 0;
}
