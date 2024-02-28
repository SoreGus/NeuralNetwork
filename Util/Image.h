#pragma once

#include "../Matrix/matrix.h"

typedef struct {
    Matrix* data;
    int label;
} Image;

Image** readImagesFromFile(char *path, int numberOfImages);
Image* imageFromMatrix(Matrix* matrix, int label);
void freeImage(Image* image);
void freeImages(Image** images, int numberOfImages);
void printImage(Image* image);
void saveJPEGImage(char* path, Image* image);
