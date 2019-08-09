#ifndef GFX_H
#define GFX_H

#include <SDL2/SDL.h>
#include "common.h"
#include "line.h"

#define SCREEN_TITLE "Bach"
#define AMIGA_RED 0
#define AMIGA_GREEN 80
#define AMIGA_BLUE 160

void init_sdl(void);
void close_sdl(void);
void draw(void);
void update(void);

extern void die(char *message);
extern void close_music(void);

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

struct line *current_line;
int line_count;

#endif /* GFX_H */
