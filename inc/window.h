#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <stdlib.h>
#include <SDL.h>

#include "logger.h"
#include "font.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    Font* font;
} Window;

Window* window_new(const char* title, size_t screen_width, size_t screen_height, size_t render_width, size_t render_height, Font* font);
void window_free(void* window);
void window_refresh(Window* window);
void window_clear(Window* window);
void window_set_color(Window* window, SDL_Color color);
void window_put_pixel(Window* window, size_t x, size_t y);
void window_put_line(Window* window, size_t x1, size_t y1, size_t x2, size_t y2);
void window_put_char(Window* window, size_t x, size_t y, char c, float font_size);
void window_put_char_grid(Window* window, size_t x, size_t y, char c, float font_size);
void window_put_str(Window* window, size_t x, size_t y, char* str, float size);
void window_put_str_grid(Window* window, size_t x, size_t y, char* str, float size);

#endif
