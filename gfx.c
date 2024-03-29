#include "gfx.h"

void init_sdl(void)
{
    int wf = 0;
    int rf = SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE;
    int tf = SDL_TEXTUREACCESS_TARGET;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        die("Could not initialize SDL");

    window = SDL_CreateWindow(
            SCREEN_TITLE,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            wf);
    if (!window)
        die("Could not create window");

    renderer = SDL_CreateRenderer(window, -1, rf);
    if (!renderer)
        die("Could not create renderer");

    texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_ARGB8888,
            tf,
            SCREEN_WIDTH,
            SCREEN_HEIGHT);
    if (!texture)
        die("Could not create texture");

    current_line = prepare_lines();
    line_count = 1;
}

void close_sdl(void)
{
    close_music();

    if (texture)
        SDL_DestroyTexture(texture);

    if (renderer)
        SDL_DestroyRenderer(renderer);

    if (window)
        SDL_DestroyWindow(window);

    destroy_lines(current_line);
}

void draw(void)
{
    struct line *l;
    int i;
    int r, g, b;
    float rs, gs, bs;

    rs = (255 - AMIGA_RED) / line_count; //LINE_COUNT;
    gs = (255 - AMIGA_GREEN) / line_count; //LINE_COUNT;
    bs = (255 - AMIGA_BLUE) / line_count; //LINE_COUNT;

    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(
            renderer, 
            AMIGA_RED, 
            AMIGA_GREEN, 
            AMIGA_BLUE, 
            255);
    SDL_RenderClear(renderer);

    l = current_line;
    r = AMIGA_RED;
    g = AMIGA_GREEN;
    b = AMIGA_BLUE;

    for (i = 0; i < line_count; ++i)
    {
        r += rs;
        g += gs;
        b += bs;
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, l->x1, l->y1, l->x2, l->y2);
        l = l->next;
    }

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderTarget(renderer, NULL);
}

void update(void)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    if (!(flags & PAUSED)) {
        current_line = current_line->next;
        ++line_count;
        if (line_count > LINE_COUNT)
            line_count = LINE_COUNT;
    }
}
