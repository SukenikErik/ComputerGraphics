// line.c
#include "line.h"
#include <stdio.h>

Line lines[MAX_LINE_COUNT];
int line_count = 0;
bool is_first_click = true;
int temp_x, temp_y;
Color selected_color = {255, 255, 255};

void draw_lines(SDL_Renderer *renderer) {
    for (int i = 0; i < line_count; i++) {
        SDL_SetRenderDrawColor(renderer, lines[i].color.r, lines[i].color.g, lines[i].color.b, 255);
        SDL_RenderDrawLine(renderer, lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2);
    }
}

void handle_mouse_event(SDL_Event *event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        printf("Egér kattintás: x = %d, y = %d\n", x, y);
        
        if (is_first_click) {
            temp_x = x;
            temp_y = y;
        } else {
            if (line_count < MAX_LINE_COUNT) {
                lines[line_count].x1 = temp_x;
                lines[line_count].y1 = temp_y;
                lines[line_count].x2 = x;
                lines[line_count].y2 = y;
                lines[line_count].color = selected_color;
                line_count++;
            }
        }
        is_first_click = !is_first_click;
    }
}