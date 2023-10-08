#include "Astar.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

s_node *search_node(s_graph *gr, int x, int y)
{
    s_node *tmp;
    int i = 0;
    tmp = gr->nodelist;
    while (i < gr->nb_node && (tmp->pos_x != x || tmp->pos_y != y))
    {
        tmp = tmp->next;
        i++;
    }
    if (i == gr->nb_node)
    {
        tmp = NULL;
    }
    return (tmp);
}
/*
s_node *path(s_graph *g, s_point *position)
{
    s_node *nod;
    nod = search_node(g, position->x, position->y);
    if (nod->link->next == NULL)
    {
        nod->link->link_to->orig = nod;
        nod->link->link_to->open = 1;
        nod->link->link_to->global_cost = nod->global_cost + nod->link->link_to->h + nod->link->cost;
    }
    return (nod->link->link_to);
}*/
s_openlist *createlist(void)
{
    s_openlist *list;
    list = malloc(sizeof(s_openlist));
    list->globalcost = 0;
    list->next = NULL;
    list->prev = NULL;
    list->node = NULL;
    return (list);
}

s_openlist *add_list(s_openlist *list, s_node *nod)
{
    s_openlist *tmp;
    s_openlist *save;
    tmp = list;
    if (tmp->node != NULL)
    {
        s_openlist *newlist;
        newlist = createlist();
        newlist->next = tmp;
        tmp->prev = newlist;
        tmp = newlist;
    }
    tmp->node = nod;
    tmp->globalcost = nod->global_cost;
    return (tmp);
}

s_node *search_next(s_openlist *list)
{
    int min;
    s_node *nextnode;
    s_openlist *tmp;
    min = list->globalcost;
    nextnode = list->node;
    tmp = list;
    while (tmp != NULL)
    {
        if (min > tmp->globalcost)
        {
            min = tmp->globalcost;
            nextnode = tmp->node;
        }
        tmp = tmp->next;
    }
    return (nextnode);
}

void printparcours(s_node *node)
{
    if (node == NULL)
    {
        return;
    }
    printparcours(node->orig);
    printf("(%d,%d) ", node->pos_x, node->pos_y);
    return;
}

s_openlist *delist(s_openlist *list, s_node *node)
{
    node->closed = 1;
    s_openlist *tmp;
    tmp = list;
    while ((tmp->node->pos_x != node->pos_x) || (node->pos_y != tmp->node->pos_y))
    {
        tmp = tmp->next;
    }
    if (tmp->next != NULL)
    {
        tmp->next->prev = tmp->prev;
    }
    if (tmp->prev != NULL)
    {
        tmp->prev->next = tmp->next;
    }
    else if (tmp->prev == NULL)
    {
        list = tmp->next;
    }
    return (list);
}

void parcours(s_node *node, s_openlist *list, s_point *end)
{
    s_node *path;
    if (node->pos_x == end->x && node->pos_y == end->y)
    {
        printf("Path: \n");
        printparcours(node);
        printf("\n");
        return;
    }
    while (node->link != NULL)
    {
        node->link->link_to->global_cost = node->global_cost + node->link->link_to->h + node->link->cost;
        node->link->link_to->orig = node;
        if (node->link->link_to->closed == 0 && node->link->link_to->open == 0)
        {
            node->link->link_to->open = 1;
            list = add_list(list, node->link->link_to);
        }
        node->link = node->link->next;
    }
    path = search_next(list);
    list = delist(list, path);
    parcours(path, list, end);

    return;
}

void Astar(s_graph *g, s_point *start, s_point *end)
{
    int cpt = 0;
    s_openlist *liste;
    liste = createlist();

    s_node *star;
    star = search_node(g, start->x, start->y);
    parcours(star, liste, end);
    return;
}