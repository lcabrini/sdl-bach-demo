#include "music.h"

void init_music(void)
{
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        die("Could not initialize mixer");

    music = Mix_LoadMUS(TRACK);
    if (!music)
        die("Could not load music");

    if (Mix_PlayMusic(music, -1) == -1)
        die("Could not play music");
}

void close_music(void)
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}
