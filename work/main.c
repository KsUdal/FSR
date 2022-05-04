#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_INAGE_WRITH_IMPLEMENTATION
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

    /*
    //Демонстрационные опыты для семинара
    char * pixel = idata;
    // char red = pixel[0];
    // char blue = pixel[1];
    // char green = pixel[2];

    // переход к следующему пикселю - сдвиг на количество байтов, равное числу каналов.
    // В нашем случае n=3
    pixel = pixel + n;

    // здесь используется макроподстановка #define - см выше
    char * pixel = p(i, j);

    unsigned char* odata = (unsigned char *) malloc(iw * ih * n);

    // обзор окрестности размера d=3 относительно данного пикселя.
    // Осторожно - есть шанс вылезти за границы массива-изображения!

    int d = 3;
    for (int s = -d; s <= d; s++) {
        for (int t = -d; t<= d; t++) {
            p1 = p(i + s, j+ t);
            // мы считаем пороговое значение по красному каналу = 20.
            // Параметрами можно играть самостоятельно!
            if (abs (p1[0] - p[0] ) < 20 ) {
                ...
            }
        }
    }

    char* outputPath = "~/work/output.png";
    // записываем картинку
    stbi_write_png(outputPath, ow, oh, n, odata, 0);
    */

    printf("Изображение размера %d в высоту и %d в ширину с количеством каналов %d считано", ih, iw, n);
    stbi_image_free(idata);
    //stbi_image_free(idata);
    return 0;
}
