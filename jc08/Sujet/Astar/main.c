#include "Astar.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int mannathan(s_point *end, s_node *n)
{
    int dman;
    int x;
    int y;
    x = (end->x - n->pos_x);
    if (x < 0)
    {
        x = x * -1;
    }
    y = (end->y - n->pos_y);
    if (y < 0)
    {
        y = y * -1;
    }
    dman = x + y;
    return (dman);
}

s_node *new_node(int x, int y, s_graph *gr, s_point *end)
{
    s_node *nod;
    nod = malloc(sizeof(s_node));
    nod->root = gr;
    nod->pos_x = x;
    nod->pos_y = y;
    nod->link = NULL;
    nod->next = NULL;
    nod->orig = NULL;
    nod->closed = 0;
    nod->open = 0;
    nod->h = mannathan(end, nod);
    nod->global_cost = 0;
    nod->dist = 0;
    add_node(gr, nod, end);
    return (nod);
}

s_graph *new_graph(void)
{
    s_graph *gr;
    gr = malloc(sizeof(s_graph));
    gr->nb_node = 0;
    gr->nodelist = NULL;
    return (gr);
}

s_link *new_link(void)
{
    s_link *lin;
    lin = malloc(sizeof(s_link));
    lin->cost = 0;
    lin->link_to = NULL;
    lin->next = NULL;
    return (lin);
}
void add_node(s_graph *gr, s_node *node, s_point *end)
{
    s_node *test;
    int i = 0;
    test = search_node(gr, node->pos_x, node->pos_y);
    if (test != NULL)
    {
        return;
    }
    gr->nb_node++;
    node->next = gr->nodelist;
    gr->nodelist = node;
    return;
}
s_link *search_link(s_node *node, s_node *tmp)
{
    while (node->link != NULL && (node->link->link_to->pos_x != tmp->pos_x || node->link->link_to->pos_y != tmp->pos_y))
    {
        node->link = node->link->next;
    }
    return (node->link);
}
void linkAtoB(s_node *A, s_node *B, s_link *lien, int cost)
{
    lien->link_to = B;
    lien->cost = cost;
    if (A->link != NULL)
    {
        lien->next = A->link;
    }
    A->link = lien;
    return;
}
void add_link(s_node *node, int x, int y, int cost, s_graph *gr, s_point *end)
{
    s_node *tmp;
    s_link *N1toN2;
    N1toN2 = new_link();
    tmp = node->root->nodelist;
    node = search_node(gr, node->pos_x, node->pos_y);
    tmp = search_node(gr, x, y);
    if (tmp == NULL)
    {
        tmp = new_node(x, y, gr, end);
    }
    linkAtoB(node, tmp, N1toN2, cost);
    return;
}

int main(int *argc, char **argv)
{
    s_graph *gr;
    s_node *node;
    s_point *end;
    s_point *start;
    start = malloc(sizeof(s_point));
    end = malloc(sizeof(s_point));
    start->x = 0;
    start->y = 0;
    end->x = 3;
    end->y = 3;
    gr = new_graph();
    node = new_node(0, 0, gr, end);
    add_link(node, 0, 1, 3, gr, end);
    add_link(node, 1, 1, 7, gr, end);
    node = new_node(0, 1, gr, end);
    add_link(node, 0, 2, 4, gr, end);
    node = new_node(0, 2, gr, end);
    add_link(node, 0, 3, 900, gr, end);
    node = new_node(0, 3, gr, end);
    add_link(node, 1, 3, 2, gr, end);
    node = new_node(1, 0, gr, end);
    add_link(node, 2, 0, 1, gr, end);
    node = new_node(1, 1, gr, end);
    add_link(node, 1, 0, 3, gr, end);
    add_link(node, 1, 2, 900, gr, end);
    add_link(node, 2, 1, 997, gr, end);
    node = new_node(1, 2, gr, end);
    add_link(node, 1, 3, 1, gr, end);
    add_link(node, 2, 2, 6, gr, end);
    node = new_node(1, 3, gr, end);
    add_link(node, 2, 3, 1, gr, end);
    node = new_node(2, 0, gr, end);
    add_link(node, 3, 0, 14, gr, end);
    node = new_node(2, 1, gr, end);
    add_link(node, 2, 2, 5, gr, end);
    node = new_node(2, 2, gr, end);
    add_link(node, 2, 3, 2, gr, end);
    add_link(node, 3, 2, 2, gr, end);
    node = new_node(2, 3, gr, end);
    add_link(node, 3, 3, 1, gr, end);
    node = new_node(3, 0, gr, end);
    add_link(node, 3, 1, 2, gr, end);
    node = new_node(3, 1, gr, end);
    add_link(node, 3, 2, 13, gr, end);
    node = new_node(3, 2, gr, end);
    add_link(node, 3, 3, 7, gr, end);
    node = new_node(3, 3, gr, end);
    printf("nb node = %i\n", gr->nb_node);
    Astar(gr, start, end);
        return (0);
}