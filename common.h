#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define LINES_PER_QUADRANT 30
#define LINE_STEP 10
#define LINE_COUNT (LINES_PER_QUADRANT * 2)

#define PAUSED 1

#ifdef DEBUG
#define dprint(...) \
    fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n");
#else
#define dprint(...)
#endif

unsigned char flags;

#endif /* COMMON_H */
