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

            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                    case SDLK_p:
                        flags ^= PAUSED;
                        if (Mix_PausedMusic())
                            Mix_ResumeMusic();
                        else
                            Mix_PauseMusic();
                        break;
                }
        }
    }
}
