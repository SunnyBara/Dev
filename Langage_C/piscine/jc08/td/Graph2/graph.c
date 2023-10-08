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
        return (NULL);
    }
    return (tmp);
}
s_link *search_link(s_node *node, s_node *tmp)
{
    while (node->link != NULL && node->link->link_to->pos_x != tmp->pos_x && node->link->link_to->pos_y != tmp->pos_y)
    {
        node->link = node->link->next;
    }
    if (node->link != NULL)
    {
        return (node->link);
    }
    return (NULL);
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
void add_link(s_node *node, int x, int y, int cost)
{
    s_node *tmp;
    s_link *N1toN2;
    s_link *test;
    N1toN2 = new_link();
    tmp = node->root->nodelist;
    node = search_node(node->root, node->pos_x, node->pos_y);
    tmp = search_node(node->root, x, y);
    if (tmp == NULL)
    {
        write(STDOUT_FILENO, "Node not existant\n", 19);
    }
    test = search_link(node, tmp);
    if (test != NULL)
    {
        write(STDOUT_FILENO, "Link_already_exist\n", 20);
        return;
    }
    linkAtoB(node, tmp, N1toN2, cost);
    s_link *N2toN1;
    N2toN1 = new_link();
    linkAtoB(tmp, node, N2toN1, cost);
    return;
}

void delAtoB(s_node *A, s_node *B, s_link *lien)
{
    s_link *search;
    if (A->link == lien)
    {
        A->link = A->link->next;
    }
    else
    {
        search = A->link;
        while (search->next != lien)
        {
            search = search->next;
        }
        search->next = search->next->next;
    }
    lien->cost = 0;
    lien->link_to = NULL;
    lien->next = NULL;
}
void del_link(s_node *node, int x, int y)
{
    s_node *tmp;
    s_link *lien;

    tmp = node->root->nodelist;
    tmp = search_node(node->root, x, y);
    node = search_node(node->root, node->pos_x, node->pos_y);
    lien = search_link(node, tmp);
    if (lien == NULL)
    {
        write(STDOUT_FILENO, "Link doesn't exist\n", 20);
        return;
    }
    delAtoB(node, tmp, lien);
    lien = search_link(tmp, node);
    delAtoB(tmp, node, lien);
    free(lien);
    return;
}

void add_node(s_graph *gr, int x, int y)
{
    s_node *test;
    int i = 0;
    test = search_node(gr, x, y);
    if (test != NULL)
    {
        write(STDOUT_FILENO, "Node already exist\n", 20);
    }
    else
    {
        test = new_node(x, y, gr);
        gr->nb_node++;
        test->next = gr->nodelist;
        gr->nodelist = test;
    }
    return;
}

void del_node(s_graph *gr, int x, int y)
{
    s_node *test;
    s_node *search;
    int i = 0;
    test = search_node(gr, x, y);
    if (test == NULL)
    {
        write(STDOUT_FILENO, "Node doesn't exist\n", 20);
        return;
    }
    gr->nb_node--;
    if (test == gr->nodelist)
    {
        gr->nodelist = gr->nodelist->next;
    }
    else
    {
        search = gr->nodelist;
        while (search->next != test)
        {
            search = search->next;
        }
        search->next = search->next->next;
    }
    test->link = NULL;
    test->root = NULL;
    test->next = NULL;
    test->pos_x = 0;
    test->pos_y = 0;
    free(test);
}

void print_node(s_node *n)
{
    char writ[1];
    s_link *tmp;
    tmp = n->link;
    write(STDOUT_FILENO, "Node : x = ", 12);
    writ[0] = n->pos_x + 48;
    write(STDOUT_FILENO, writ, 1);
    writ[0] = n->pos_y + 48;
    write(STDOUT_FILENO, " and y = ", 10);
    write(STDOUT_FILENO, writ, 1);
    write(STDOUT_FILENO, " is Bind to\n", 13);
    if (tmp == NULL)
    {
        write(STDOUT_FILENO, "Nothing\n", 9);
    }
    while (tmp != NULL)
    {
        write(STDOUT_FILENO, "Node : x = ", 12);
        writ[0] = tmp->link_to->pos_x + 48;
        write(STDOUT_FILENO, writ, 1);
        writ[0] = tmp->link_to->pos_y + 48;
        write(STDOUT_FILENO, " and y = ", 10);
        write(STDOUT_FILENO, writ, 1);
        write(STDOUT_FILENO, "with a cost of : ", 18);
        writ[0] = tmp->cost + 48;
        write(STDOUT_FILENO, writ, 1);
        write(STDOUT_FILENO, "\n", 1);
        tmp = tmp->next;
    }
}

void print_graph(s_graph *gr)
{
    char writ[1];
    s_node *tmp;
    if (gr == NULL)
    {
        write(STDOUT_FILENO, "Invalid graph", 14);
        return;
    }
    write(STDOUT_FILENO, " This graphe is composed of ", 29);
    writ[0] = gr->nb_node + 48;
    write(STDOUT_FILENO, writ, 1);
    write(STDOUT_FILENO, " Nodes\n", 8);
    tmp = gr->nodelist;
    if (tmp == NULL)
    {
        write(STDOUT_FILENO, "This graph is empty\n", 21);
    }
    while (tmp != NULL)
    {
        print_node(tmp);
        tmp = tmp->next;
    }
    return;
}