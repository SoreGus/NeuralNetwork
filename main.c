#include "Matrix/matrixOperations.h"
#include <stdio.h>
#include "Util/Image.h"

int main(int argc, char *argv[]) {

    char buffer[100];
    Image** images = readImagesFromFile("data/mnist_train.csv", 10000);
    for (int i = 0; i < 10; i++) {
        sprintf(buffer, "output%d.jpg", i);
        saveJPEGImage(buffer, images[i]);
    }
    freeImages(images, 10000);

    return 0;
}
