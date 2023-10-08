#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void add_nodelist(s_graph *gr, s_node *n1)
{
    if (gr->nodelist != NULL)
    {
        n1->next = gr->nodelist;
    }
    gr->nodelist = n1;
}

s_graph *fillgraph(s_graph *gr)
{
    gr->nb_node = 6;
    s_node *n1;
    s_node *n2;
    s_node *n3;
    s_node *n4;
    s_node *n5;
    s_node *n6;
    n1 = new_node(1, 0, gr);
    n2 = new_node(2, 0, gr);
    n3 = new_node(3, 0, gr);
    n4 = new_node(4, 0, gr);
    n5 = new_node(5, 0, gr);
    n6 = new_node(6, 0, gr);
    s_link *L1;
    s_link *L2;
    s_link *L3;
    s_link *L4;
    s_link *L5;
    L1 = new_link();
    L2 = new_link();
    L3 = new_link();
    L4 = new_link();
    L5 = new_link();
    linkAtoB(n1, n5, L1, 1);
    linkAtoB(n2, n3, L2, 1);
    linkAtoB(n1, n4, L3, 1);
    linkAtoB(n4, n2, L4, 1);
    linkAtoB(n4, n6, L5, 1);
    add_nodelist(gr, n1);
    add_nodelist(gr, n2);
    add_nodelist(gr, n5);
    add_nodelist(gr, n6);
    add_nodelist(gr, n3);
    add_nodelist(gr, n4);
    return (gr);
}
int main(int argc, char **argv)
{
    s_graph *gr;
    s_node **sort;
    int i;
    gr = new_graph();
    gr = fillgraph(gr);
    sort = topological_sort(gr);
     while (i < gr->nb_node)
     {
         printf("node : %i \n", sort[i]->pos_x);
         i++;
     }
    return (0);
}