#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Макроподстановка, меняющая p(i, j) на  idata[(i)+(j)*iw]

//#define p(i, j)  idata[(i)+(j)*iw] условное обозначение, которое может и не понадобиться

int main() {

    // строка, путь к файлу
    char*inputPath = "hampster.png";
    int iw, ih, n; //ширина, высота и количество цветовых каналов

    // Загружаем изображение, чтобы получить информацию о ширине, высоте и цветовом канале
    unsigned char *idata = stbi_load(inputPath, &iw, &ih, &n, 0);
    if (idata == NULL) {
        printf("ERROR: can't read file %s\n", inputPath );
        return 1;
    }

    int i, k, j;
    k = 0;
    unsigned char* MyImage = (unsigned char*)malloc(ih*iw*sizeof(unsigned char));
    for (i = 0; i < ih*iw*n; i = i + n) {
        MyImage[k] = 0.299*idata[i] + 0.587*idata[i + 1] + 0.114*idata[i + 2];
        k = k + 1;
    }
    /*
    //coloring
    for (i = 0; i < ih; i++) {
        for (j = 0; j < iw; j++) {
            if (MyImage[iw*i+j] < 112) MyImage[iw*i+j] = 0;
            if (MyImage[iw*i+j] > 156) MyImage[iw*i+j] = 255;
        }
    }
    */

    //Roberts
    unsigned char x, y;
    for (i = 2; i < ih; i++) {
        for (j = 2; j < iw; j++) {
            x = MyImage[iw*i+j] - MyImage[iw*(i-1)+j];
            y = MyImage[iw*i+j] - MyImage[iw*i+(j-1)];
            MyImage[i*iw] = sqrt(x*x + y*y);
        }
    }

    //coloring
    for (i = 0; i < ih; i++) {
        for (j = 0; j < iw; j++) {
            if (MyImage[iw*i+j] < 112) MyImage[iw*i+j] = 0;
            if (MyImage[iw*i+j] > 156) MyImage[iw*i+j] = 255;
        }
    }

    char* outputPath = "output.png";
    // записываем картинку
    int one = 1; int zero = 0;
    stbi_write_png(outputPath, iw, ih, one, MyImage, zero);
    //stbi_image_write(outputPath, iw, ih, 2, MyImage, 0);
    //printf("Изображение размера %d в высоту и %d в ширину с количеством каналов %d считано", ih, iw, n);
    stbi_image_free(idata);
    stbi_image_free(MyImage);
    return 0;
}
