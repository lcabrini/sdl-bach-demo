#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "common.h"

#define LEFT 0
#define TOP 0
#define RIGHT SCREEN_WIDTH - 1
#define BOTTOM SCREEN_HEIGHT - 1

struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct node *next;
};

struct node *build_list(void);
void destroy_list(struct node *head);
struct node *create_node(int x1, int y1, int x2, int y2, struct node *p);
struct node *insert_node(int x1, int y1, int x2, int y2, struct node *h);

#endif /* LIST_H */
