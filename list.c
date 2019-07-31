#include "list.h"

struct node *build_list()
{
    struct node *h = NULL;
    struct node *p = NULL;
    struct node *c = NULL;
    int q;

    for (q = 0; q < LINES_PER_QUADRANT; ++q)
    {
        c = create_node(
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
        c = create_node(
                RIGHT - LINE_STEP * (LINES_PER_QUADRANT - q),
                TOP,
                RIGHT,
                LINE_STEP * q,
                p);
        p = c;
    }

    for (q = 0; q < LINES_PER_QUADRANT; ++q)
    {
        c = create_node(
                RIGHT,
                BOTTOM - LINE_STEP * (LINES_PER_QUADRANT - q),
                RIGHT - LINE_STEP * q,
                BOTTOM,
                p);
        p = c;
    }

    for (q = 0; q < LINES_PER_QUADRANT; ++q)
    {
        c = create_node(
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

void destroy_list(struct node *head)
{
    struct node *c;
    struct node *n;

    c = head;
    while (c && c->next)
    {
        n = c->next;
        free(c);
        c->next = NULL;
        c = n;
    }
}

struct node *create_node(int x1, int y1, int x2, int y2, struct node *p)
{
    struct node *n;

    n = malloc(sizeof(struct node*));
    n->x1 = x1;
    n->y1 = y1;
    n->x2 = x2;
    n->y2 = y2;
    if (p)
        p->next = n;

    return n;
}

struct node *insert_node(int x1, int y1, int x2, int y2, struct node *h)
{
    struct node *n;

    n = malloc(sizeof(struct node*));
    n->x1 = x1;
    n->y1 = y1;
    n->x2 = x2;
    n->y2 = y2;
    n->next = h;
    return n;
}
