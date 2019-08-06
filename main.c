#include "main.h"

int main(int argc, char *argv[])
{
    Uint32 ts, te, td;

    atexit(close_sdl);
    flags = 0;
    init_sdl();
    init_music();

    while (1)
    {
        ts = SDL_GetTicks();
        handle_events();
        draw();
        update();
        te = SDL_GetTicks();
        td = te - ts;
        
        if (td < TICKS_PER_FRAME)
            SDL_Delay(TICKS_PER_FRAME - td);
    }

    return 0;
}

void die(char *message)
{
    fprintf(stderr, "%s: %s", message, SDL_GetError());
    exit(1);
}
