#include "window.h"

Window* window_new(const char* title, size_t screen_width, size_t screen_height, size_t render_width, size_t render_height, Font* font) {
    Window* result = malloc(sizeof(Window));
    result->font = font;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        LOG_ERR("Failed to initialize SDL: %s", SDL_GetError());
        LOG_EXIT(1);
    }

    result->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    if (result->window == NULL) {
        LOG_ERR("Failed to create SDL window: %s", SDL_GetError());
        LOG_EXIT(1);
    }

    result->renderer = SDL_CreateRenderer(result->window, -1, SDL_RENDERER_ACCELERATED);
    if (result->renderer == NULL) {
        LOG_ERR("Failed to create SDL renderer: %s", SDL_GetError());
        LOG_EXIT(1);
    }

    SDL_RenderSetLogicalSize(result->renderer, render_width, render_height);

    return result;
}

void window_free(void* window) {
    Window* ptr = (Window*) window;

    if (ptr) {
        SDL_DestroyRenderer(ptr->renderer);
        ptr->renderer = NULL;

        SDL_DestroyWindow(ptr->window);
        ptr->window = NULL;
        
        font_free(ptr->font);
        ptr->font = NULL;

        free(ptr);
        window = NULL;
    }
}

void window_refresh(Window* window) {
    SDL_RenderPresent(window->renderer);
}

void window_clear(Window* window) {
    SDL_RenderClear(window->renderer);
}

void window_set_color(Window* window, SDL_Color color) {
    SDL_SetRenderDrawColor(window->renderer, color.r, color.g, color.b, color.a);
}

void window_put_pixel(Window* window, size_t x, size_t y) {
    SDL_RenderDrawPoint(window->renderer, x, y);
}

void window_put_line(Window* window, size_t x1, size_t y1, size_t x2, size_t y2) {
    SDL_RenderDrawLine(window->renderer, x1, y1, x2, y2);
}

void window_put_char(Window* window, size_t x, size_t y, char c, float size) {
    bool** buffer = malloc(sizeof(bool) * window->font->char_height);

    for (size_t i = 0; i < window->font->char_height; i++) {
        buffer[i] = malloc(sizeof(bool) * window->font->char_width);
    } 

    font_get_char(window->font, c, buffer);

    for (size_t y = 0; y < window->font->char_height * size; y++) {
        for (size_t x = 0; x < window->font->char_width * size; x++) {
            if (buffer[(int)(y / size)][(int)(x / size)]) {
                window_put_pixel(window, x, y);
            }
        }
    }


    for (size_t i = 0; i < window->font->char_height; i++) {
        free(buffer[i]);
    }

    free(buffer);
}
