#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main(void) {
    //
    int width, height, channels;
    unsigned char *img = stbi_load("sky.jpg", &width, &height, &channels, 0);
    if (img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    //convert image to sepia
    unsigned char *sepia_img = malloc(img_size);
    if (sepia_img == NULL) {
        printf("Unable to allocate memory for sepia image.\n");
        exit(1);
    }
    //sepia filter coefficients
    for (unsigned char *p = img, *pg = sepia_img; p != img + img_size; p += channels, pg += channels) {
        *pg = (uint8_t)fmin(0.393 * *p + 0.769 * *(p + 1) + 0.189 * *(p + 2), 255.0); //red
        *(pg + 1) = (uint8_t)fmin(0.349 * *p + 0.686 * *(p + 1) + 0.168 * *(p + 2), 255.0); //green
        *(pg + 2) = (uint8_t)fmin(0.272 * *p + 0.534 * *(p + 1) + 0.131 * *(p + 2), 255.0); //blue
        if (channels == 4) {
            *(pg + 3) = *(p + 3);
        }
    }

    stbi_write_jpg("sky_sepia.jpg", width, height, channels, sepia_img, 100);

    return 0;
}
