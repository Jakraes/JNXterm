#include "font.h"

Font* font_load_ppm(const char* filename, size_t char_width, size_t char_height) {
    PPM_Image* img = ppm_image_load(filename);

    if (img) {
        Font* result = malloc(sizeof(Font));
        result->data = malloc(img->width * img->height * sizeof(bool));
        result->width = img->width;
        result->height = img->height;
        result->char_width = char_width;
        result->char_height = char_height;

        for (size_t y = 0; y < img->height; y++) {
            for (size_t x = 0; x < img->width; x++) {
                PPM_Color c = ppm_image_get(img, x, y);

                font_set(result, x, y, c.r && c.g && c.b);
            }
        }
        
        ppm_image_free(img);

        return result;
    }

    exit(1);
}

void font_free(void* font) {
    Font* ptr = (Font*) font;

    if (ptr) {
        free(ptr->data);
        ptr->data = NULL;

        free(ptr);
        font = NULL;
    }
}

void font_set(Font* font, size_t x, size_t y, bool b) {
    font->data[y * font->height + x] = b;
}

bool font_get(Font* font, size_t x, size_t y) {
    return font->data[y * font->height + x];
}

void font_get_char(Font* font, size_t char_index, bool** buffer) {
   size_t c_y = char_index / (font->height / font->char_height);
   size_t c_x = char_index - c_y * (font->width / font->char_height);

   for (size_t y = 0; y < font->char_height; y++) {
       for (size_t x = 0; x < font->char_width; x++) {
           buffer[y][x] = font_get(font, c_x * font->char_width + x, c_y * font->char_height + y);
       }
   }
}
