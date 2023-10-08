#include "graph.h"
#include <stdlib.h>
#include <unistd.h>

s_node *new_node(int x, int y, s_graph *gr)
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
    nod->h = 0;
    nod->dist = 0;
    nod->global_cost = 0;
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
s_node *searchnode(s_graph *g)
{
    s_node *tmp;
    tmp = g->nodelist;
    while (tmp != NULL && (tmp->open != 0 || tmp->orig != NULL))
    {
        tmp = tmp->next;
    }
    return (tmp);
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

void add_list(s_node *node, s_cpt *cpt)
{
    cpt->cpt = cpt->cpt - 1;
    cpt->sort[cpt->cpt] = node;
    return;
}
void explore(s_node *node, s_cpt *sort)
{
    node->open = 1;
    if (node->link == NULL && node->closed != 1)
    {
        node->closed = 1;
        add_list(node, sort);
        return;
    }
    while (node->link != NULL)
    {

        explore(node->link->link_to, sort);
        node->link = node->link->next;
    }
    if (node->closed != 1)
    {
        node->closed = 1;
        add_list(node, sort);
        return;
    }
    return;
}

void parcours(s_graph *g, s_cpt *sort)
{
    s_node *tmp;
    while (tmp != NULL)
    {
        tmp = searchnode(g);
        if (tmp != NULL && tmp->closed == 0)
        {
            explore(tmp, sort);
        }
    }
    return;
}

s_node **topological_sort(s_graph *g)
{
    s_node **sort;
    s_cpt *cpt;
    cpt = malloc(sizeof(s_cpt));
    cpt->cpt = g->nb_node;
    sort = malloc(g->nb_node * sizeof(s_node *));
    cpt->sort = sort;
    parcours(g, cpt);
    return (sort);
}