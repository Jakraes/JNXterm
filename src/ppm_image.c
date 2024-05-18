#include "ppm_image.h"

PPM_Image* ppm_image_new(size_t depth, size_t width, size_t height) {
    PPM_Image* result = malloc(sizeof(PPM_Image));

    result->data = malloc(width * height * sizeof(PPM_Color));
    result->depth = depth;
    result->width = width;
    result->height = height;

    return result;
}

void ppm_image_free(void* ppm_image) {
    PPM_Image* ptr = (PPM_Image*) ppm_image;

    if (ptr) {
        free(ptr->data);
        ptr->data = NULL;

        free(ptr);
        ppm_image = NULL;
    }
}

void ppm_image_set(PPM_Image* ppm_image, size_t x, size_t y, PPM_Color color) {
    ppm_image->data[y * ppm_image->height + x] = color;
}

PPM_Color ppm_image_get(PPM_Image* ppm_image, size_t x, size_t y) {
    return ppm_image->data[y * ppm_image->height + x];
}

void ppm_image_save(PPM_Image* ppm_image, const char* filename) {
    FILE* f = fopen(filename, "wb");

    if (f) {
        fprintf(f, "P6\n%lu %lu\n%lu\n", ppm_image->width, ppm_image->height, ppm_image->depth);

        for (size_t y = 0; y < ppm_image->height; y++) {
            for (size_t x = 0; x < ppm_image->width; x++) {
                PPM_Color color = ppm_image_get(ppm_image, x, y);
                
                fwrite(&color, 1, sizeof(PPM_Color), f);
            }
        }

        fclose(f);
    }
}

PPM_Image* ppm_image_load(const char* filename) {
    FILE* f = fopen(filename, "rb");

    if (f) {
        size_t width, height, depth;

        fscanf(f, "P6\n%lu %lu\n%lu\n", &width, &height, &depth);

        PPM_Image* result = ppm_image_new(depth, width, height);

        for (size_t y = 0; y < height; y++) {
            for (size_t x = 0; x < width; x++) {
                PPM_Color c;
                
                fread(&c, 1, sizeof(PPM_Color), f);

                ppm_image_set(result, x, y, c);
            }
        }
        
        fclose(f);

        return result;
    }

    exit(1);
}
