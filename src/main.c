#include "window.h"
#include "utils.h"

__attribute__((constructor)) static void init() {
    LOG_INIT;
}

__attribute__((destructor)) static void end() {
    LOG_END;
}

int main(int argc, char* argv[]) {
    Font* font = font_load_ppm("./resources/font.ppm", 10, 10);

    Window* window = window_new("Test", 600, 400, 600, 400, font);
    
    SDL_Color white = (SDL_Color){255, 255, 255, 255};
    
    window_set_color(window, white);

    window_put_str_grid(window, 0, 0, "Ola", 4);
    window_put_str_grid(window, 0, 1, "E da padaria", 4);

    window_put_char_grid(window, 0, 2, CP_SMILE_1, 4);
    
    window_refresh(window);
   
    bool quit = false;

    while (!quit){
        SDL_PollEvent(&window->event);
    
        switch(window->event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (window->event.key.keysym.sym) {
                    case SDLK_q:
                        quit = true;
                        break;
                }
                break;
        }

        usleep(1);
    }

    return 0;
}
