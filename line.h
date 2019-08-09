#ifndef LINE_H
#define LINE_H

#include <stdlib.h>
#include "common.h"

#define LEFT 0
#define TOP 0
#define RIGHT SCREEN_WIDTH - 1
#define BOTTOM SCREEN_HEIGHT - 1

struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct line *next;
};

struct line *prepare_lines(void);
void destroy_lines(struct line *head);
struct line *create_line(int x1, int y1, int x2, int y2, struct line *p);
struct line *insert_line(int x1, int y1, int x2, int y2, struct line *h);

#endif /* LINE_H */
