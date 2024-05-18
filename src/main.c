#include "window.h"

__attribute__((constructor)) static void init() {
    LOG_INIT;
}

__attribute__((destructor)) static void end() {
    LOG_END;
}

int main(int argc, char* argv[]) {
    Font* font = font_load_ppm("font.ppm", 10, 10);

    Window* window = window_new("Test", 600, 400, 600, 400, font);
    
    SDL_Color white = (SDL_Color){143, 0, 255, 255};
    SDL_Color black = (SDL_Color){0, 0, 0, 255};
    
    /*
    bool buffer[10][10];

    char* str = "Hello world!";

    for (int i = 0; str[i] != '\0'; i++) {
        font_get_char(font, str[i], buffer);
        

        window_set_color(window, white);
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 20; x++) {
                if (buffer[y / 2][x / 2]) {
                    window_put_pixel(window, x + i * 20, y);
                }
            }
        }
    }
    */

    //window_put_char(window, 0, 0, 'H', 1);
    
    window_refresh(window);
   
    bool quit = false;

    while (!quit){
        SDL_PollEvent(&window->event);
    
        switch(window->event.type) {
            case SDL_KEYDOWN:
                int key = window->event.key.keysym.sym;
                switch (key) {
                    case SDLK_q:
                        quit = true;
                        break;
                }
                break;
        }
    }

    return 0;
}
