#include "main.h"

int main(int argc, char *argv[])
{
    atexit(close_sdl);
    flags = 0;
    init_sdl();
    init_music();

    while (1)
    {
        handle_events();
        draw();
        update();
        SDL_Delay(50);
    }

    return 0;
}

void die(char *message)
{
    fprintf(stderr, "%s: %s", message, SDL_GetError());
    exit(1);
}
