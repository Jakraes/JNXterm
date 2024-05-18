#ifndef _PPM_IMAGE_H_
#define _PPM_IMAGE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} PPM_Color;

typedef struct {
    PPM_Color* data;
    size_t depth;
    size_t width;
    size_t height;
} PPM_Image;

PPM_Image* ppm_image_new(size_t depth, size_t width, size_t height);
void ppm_image_free(void* ppm_image);
void ppm_image_set(PPM_Image* ppm_image, size_t x, size_t y, PPM_Color color);
PPM_Color ppm_image_get(PPM_Image* ppm_image, size_t x, size_t y);
void ppm_image_save(PPM_Image* ppm_image, const char* filename);
PPM_Image* ppm_image_load(const char* filename);

#endif
