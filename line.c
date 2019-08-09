#include "line.h"

struct line *prepare_lines()
{
    struct line *h = NULL;
    struct line *p = NULL;
    struct line *c = NULL;
    int q;

    for (q = 0; q < LINES_PER_QUADRANT; ++q)
    {
        c = create_line(
                LEFT,
                LINE_STEP * (LINES_PER_QUADRANT - q),
                LINE_STEP * q,
                TOP,
                p);
        if (!h) h = c;
        p = c;
    }

    for (q = 0; q < LINES_PER_QUADRANT; ++q)
    {
        c = create_line(
                RIGHT - LINE_STEP * (LINES_PER_QUADRANT - q),
                TOP,
                RIGHT,
                LINE_STEP * q,
                p);
        p = c;
    }

    for (q = 0; q < LINES_PER_QUADRANT; ++q)
    {
        c = create_line(
                RIGHT,
                BOTTOM - LINE_STEP * (LINES_PER_QUADRANT - q),
                RIGHT - LINE_STEP * q,
                BOTTOM,
                p);
        p = c;
    }

    for (q = 0; q < LINES_PER_QUADRANT; ++q)
    {
        c = create_line(
                LEFT + LINE_STEP * (LINES_PER_QUADRANT - q),
                BOTTOM,
                LEFT,
                BOTTOM - LINE_STEP * q,
                p);
        p = c;
    }

    p->next = h;
    return h;
}

void destroy_lines(struct line *head)
{
    struct line *c;
    struct line *n;

    c = head;
    while (c && c->next)
    {
        n = c->next;
        free(c);
        c->next = NULL;
        c = n;
    }
}

struct line *create_line(int x1, int y1, int x2, int y2, struct line *p)
{
    struct line *n;

    n = malloc(sizeof(struct line));
    n->x1 = x1;
    n->y1 = y1;
    n->x2 = x2;
    n->y2 = y2;
    if (p)
        p->next = n;

    return n;
}

struct line *insert_line(int x1, int y1, int x2, int y2, struct line *h)
{
    struct line *n;

    n = malloc(sizeof(struct line));
    n->x1 = x1;
    n->y1 = y1;
    n->x2 = x2;
    n->y2 = y2;
    n->next = h;
    return n;
}
