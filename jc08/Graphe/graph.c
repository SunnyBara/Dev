#include "graph.h"
#include <stdlib.h>
#include <unistd.h>

void initialise(int **mat, int nb_node)
{
    int i = 0;
    int j = 0;
    while (i < nb_node)
    {
        while (j < nb_node)
        {
            mat[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
}

s_adja *create_adja(unsigned int nb_node)
{
    s_adja *adja;
    int **matr;
    int i = 0;
    adja = malloc(sizeof(s_adja));
    matr = malloc(nb_node*sizeof(int *));
    while (i < nb_node)
    {
        matr[i] = malloc(sizeof(int));
        i++;
    }
    initialise(matr, nb_node);
    adja->nb_node = nb_node;
    adja->mat = matr;
}
void add_link(s_adja *adj, int x, int y, int cost)
{
    if (x > adj->nb_node || y > adj->nb_node)
    {
        write(STDOUT_FILENO, "invalid link\n", 13);
    }
    else if (adj->mat[x][y] != 0)
    {
        write(STDOUT_FILENO, "link already exist\n", 19);
    }
    else
    {
        adj->mat[x][y] = cost;
        adj->mat[y][x] = cost;
    }
    return;
}

void del_link(s_adja *adj, int x, int y)
{
    if (x > adj->nb_node || y > adj->nb_node)
    {
        write(STDOUT_FILENO, "no node in graph\n", 17);
    }
    else if (adj->mat[x][y] == 0)
    {
        write(STDOUT_FILENO, "non existant link\n", 18);
    }
    else
    {
        adj->mat[x][y] = 0;
    }
    return;
}
void print_node(s_adja *adj)
{
    int i = 0;
    int j = 0;
    int cpt = 0;
    char writ[1];
    while (i < adj->nb_node)
    {
        writ[0] = i + 48;
        write(STDOUT_FILENO, "Node n° ", 10);
        write(STDOUT_FILENO, writ, 1);
        write(STDOUT_FILENO, " is link to\n", 12);
        while (j < adj->nb_node)
        {
            if (adj->mat[i][j] != 0)
            {
                writ[0] = j + 48;
                write(STDOUT_FILENO, "Node n° ", 10);
                write(STDOUT_FILENO, writ, 1);
                write(STDOUT_FILENO, " cost is ", 9);
                writ[0] = adj->mat[i][j] + 48;
                write(STDOUT_FILENO, writ, 1);
                write(STDOUT_FILENO, "\n", 1);
                cpt++;
            }
            j++;
        }
        if (cpt == 0)
        {
            write(STDOUT_FILENO, "Nothing\n", 9);
        }
        i++;
        j = 0;
        cpt = 0;
    }
    return;
}

void print_adja(s_adja *adj)
{
    if (adj->nb_node == 0)
    {
        write(STDOUT_FILENO, "No node in this graph", 21);
    }
    else if (adj == NULL)
    {
        write(STDOUT_FILENO, "Invalid_graph", 13);
    }
    else
    {
        char writ[1];
        writ[0] = adj->nb_node + 48;
        write(STDOUT_FILENO, "This graph has ", 15);
        write(STDOUT_FILENO, writ, 1);
        write(STDOUT_FILENO, " node\n", 6);
        print_node(adj);
    }
    return;
}