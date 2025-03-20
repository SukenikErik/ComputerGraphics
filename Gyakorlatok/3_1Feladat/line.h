// line.h
#ifndef LINE_H
#define LINE_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define MAX_LINE_COUNT 100

typedef struct {
    Uint8 r, g, b;
} Color;

typedef struct {
    int x1, y1, x2, y2;
    Color color;
} Line;

void draw_lines(SDL_Renderer *renderer);
void handle_mouse_event(SDL_Event *event);

#endif // LINE_H