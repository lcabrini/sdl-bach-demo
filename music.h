#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL_mixer.h>

#define TRACK "jesu-joy-of-mans-desiring.mp3"

Mix_Music *music;

void init_music(void);
void close_music(void);

extern void die(char *message);

#endif /* MUSIC_H */
