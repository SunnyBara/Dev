#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    s_graph *gr;
    printf("new graph\n");
    gr = new_graph();
    printf("add 0 : 0\n");
    add_node(gr, 0, 0);
    printf("add 1 : 0\n");
    add_node(gr, 1, 0);
    printf("add 0 : 1\n");
    add_node(gr, 0, 1);
    s_node *node;
    printf("new node 1 : 0\n");
    node = new_node(1, 0, gr);
    printf("add node 1 : 0\n");
    add_node(gr, node->pos_x, node->pos_y);
    printf("new node 1 : 1\n");
    node = new_node(1, 1, gr);
    printf("add node 1 : 1\n");
    add_node(gr, node->pos_x, node->pos_y);
    printf("add link 1 , 0 cost 3\n");
    add_link(node, 1, 0, 3);
    printf("add link 1 , 0 cost 2\n");
    add_link(node, 1, 0, 2);
    printf("print node \n");
    print_node(node);
    printf("print graph\n");
    print_graph(gr);
    printf("del link 1 , 0\n");
    del_link(node, 1, 0);
    printf("del link 1 , 0\n");
    del_link(node, 1, 0);
    printf("print node\n");
    print_node(node);
    printf("del node\n");
    del_node(gr, 0, 0);
    printf("del node\n");
    del_node(gr, 0, 0);
    printf("print graph\n");
    print_graph(gr);
    return (0);
}