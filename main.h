#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "common.h"

#define FPS 20
#define TICKS_PER_FRAME (1000 / FPS)

void die(char *message);

extern void init_sdl(void);
extern void close_sdl(void);
extern void draw(void);
extern void update(void);
extern void handle_events(void);
extern void init_music(void);

#endif /* MAIN_H */
