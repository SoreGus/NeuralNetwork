#include "Image.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

Image* imageFromMatrix(Matrix* matrix, int label) {
    Image* image = malloc(sizeof(Image*));
    image->data = matrix;
    image->label = label;
    return image;
}

Image** readImagesFromFile(char *path, int numberOfImages) {
    FILE* file;
    Image** images = malloc(numberOfImages * sizeof(Image*));
    int maxChar = 10000;
    char row[maxChar];
    file = fopen(path, "r");

    fgets(row, maxChar, file);
    int i = 0;
    while(feof(file) != 1 && i < numberOfImages) {
        images[i] = malloc(sizeof(Image*));
        int j = 0;
        fgets(row, maxChar, file);
        char * token = strtok(row, ",");
        images[i]->data = createMatrix(28, 28);
        while(token != NULL) {
            if (j == 0) {
                images[i]->label = atoi(token);
            } else {
                images[i]->data->data[(j - 1) / 28][(j - 1) % 28] = atoi(token) / 256.0;
            }
            token = strtok(NULL, ",");
            j++;
        }
        i++;
    }
    fclose(file);
    return images;
}

void freeImage(Image* image) {
    freeMatrix(image->data);
    free(image);
    image = NULL;
}

void freeImages(Image** images, int numberOfImages) {
    for (int i = 0; i < numberOfImages; i++) {
        freeImage(images[i]);
    }
    free(images);
    images = NULL;
}

void printImage(Image* image) {
    printMatrix(image->data);
    printf("Label: %d - Dimension: %dx%d\n", image->label, image->data->rows, image->data->columns);
}



void saveJPEGImage(char* path, Image* image) {
    FILE *outfile = fopen(path, "wb");
    
    if (!outfile) {
        fprintf(stderr, "Erro ao abrir o arquivo de saída.\n");
        return;
    }

    fprintf(outfile, "P5\n%d %d\n255\n", image->data->rows, image->data->columns);

    for (int i = 0; i < image->data->columns; i++) {
        for (int j = 0; j < image->data->rows; j++) {
            uint8_t pixel = (uint8_t)(image->data->data[i][j] * 255);
            fwrite(&pixel, sizeof(uint8_t), 1, outfile);
        }
    }

    fclose(outfile);
}