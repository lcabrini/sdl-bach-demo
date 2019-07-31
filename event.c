#include "event.h"

void handle_events(void)
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
        }
    }
}
