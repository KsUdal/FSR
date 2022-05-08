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
    int pixels[ih][iw]
    for (i = 0; i < ih*iw; i++) {
        k = i/iw;
        pixels[k][i-iw*k] = MyImage[i];
    }

    int j;
    for (i = 0; i < ih; i++) {
        for
    }
    */
    /*
    //Sobel Filter second part
    for (i = 0; i < ih; i++) {
        for (j = 0; j < iw; j++) {
            if (MyImage[iw*i+j] < 128) MyImage[iw*i+j] = 0;
            if (MyImage[iw*i+j] > 128) MyImage[iw*i+j] = 255;
        }
    }
    */
    /*
    for (i = 2; i < iw - 1; i++) {
        for (j = 2; j < ih - 1; j++) {
            x = -MyImage[(i-1)*(j-1)] - 2*MyImage[i*(j-1)] - MyImage[(i+1)*(j-1)];
            x = x + MyImage[(i-1)*(j+1)] + 2*MyImage[i*(j+1)] + MyImage[(i+1)*(j+1)];
            y = -MyImage[(i-1)*(j-1)] - 2*MyImage[(i-1)*j] - MyImage[(i-1)*(j+1)];
            y = y + MyImage[(i+1)*(j-1)] + 2*MyImage[(i+1)*j] + MyImage[(i+1)*(j+1)];
            MyImage[i*j] = sqrt(x*x + y*y);
            //odata[iw*i+j] = sqrt(x*x + y*y);
        }
    }
    */
    /*
    //фильтр Собеля
    unsigned char x, y;
    for (i = iw+1; i < ih*iw-iw-1; i++) {
        //for (j = 1; j < iw - 1; j++) {
            x = -MyImage[i-iw-1] - 2*MyImage[i-iw] - MyImage[i-iw+1];
            x = x + MyImage[i+iw-1] + 2*MyImage[i+iw] + MyImage[i+iw+1];
            y = -MyImage[i-iw-1] - 2*MyImage[i-1] - MyImage[i+iw-1];
            y = y + MyImage[i-iw+1] + 2*MyImage[i+1] + MyImage[i+iw+1];
            MyImage[i] = sqrt(x*x + y*y);
        //}
    }
    */

    //Sobel Filter second part
    for (i = 0; i < ih; i++) {
        for (j = 0; j < iw; j++) {
            if (MyImage[iw*i+j] < 128) MyImage[iw*i+j] = 0;
            if (MyImage[iw*i+j] > 128) MyImage[iw*i+j] = 255;
        }
    }

    unsigned char x, y;
    for (i = 2; i < iw - 1; i++) {
        for (j = 2; j < ih - 1; j++) {
            x = -MyImage[(i-1)*(j-1)] - 2*MyImage[i*(j-1)] - MyImage[(i+1)*(j-1)];
            x = x + MyImage[(i-1)*(j+1)] + 2*MyImage[i*(j+1)] + MyImage[(i+1)*(j+1)];
            y = -MyImage[(i-1)*(j-1)] - 2*MyImage[(i-1)*j] - MyImage[(i-1)*(j+1)];
            y = y + MyImage[(i+1)*(j-1)] + 2*MyImage[(i+1)*j] + MyImage[(i+1)*(j+1)];
            MyImage[i*j] = sqrt(x*x + y*y);
            //odata[iw*i+j] = sqrt(x*x + y*y);
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
