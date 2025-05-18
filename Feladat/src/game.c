#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <stdio.h>



void init_game() {
    // SDL inicializálás
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL hiba: %s\n", SDL_GetError());
        return;
    }

    SDL_DisplayMode dm;
    if (SDL_GetCurrentDisplayMode(0, &dm) != 0) {
        printf("Képernyő méret lekérési hiba: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    int window_width = dm.w / 2;
    int window_height = dm.h / 2;

    // OpenGL-es ablak létrehozása
    SDL_Window* window = SDL_CreateWindow("Ablak",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          window_width, window_height,
                                          SDL_WINDOW_OPENGL);
    if (!window) {
        printf("Ablak hiba: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    // OpenGL Context létrehozása
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        printf("OpenGL Context hiba: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // OpenGL beállítások
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Háttérszín

    // ** Teljes képernyő állapot **
    int fullscreen = 0;

    // Fő ciklus
    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_f) {
                    // Teljes képernyő mód váltása
                    fullscreen = !fullscreen;
                    if (fullscreen) {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    } else {
                        SDL_SetWindowFullscreen(window, 0);
                    }
                }
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = 0;
                }
            }
        }

        // Képernyő törlése és frissítése
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
    }

    // Erőforrások felszabadítása
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


