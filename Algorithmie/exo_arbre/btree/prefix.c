#include "./../btree.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct printlist
{
    int elt;
    struct printlist *next;
} s_printlist;

void printnode(int node)
{
    int n = node;
    int i = 0;
    int pow = 1;
    while (n != 0)
    {
        n = n / 10;
        i += 1;
        pow *= 10;
    }
    pow /= 10;
    char elt[i];
    int j = 0;
    n = node;
    while (j < i)
    {
        elt[j] = n / pow + '0';
        n = (n - n / pow * pow);
        pow = pow / 10;
        j += 1;
    }
    write(STDOUT_FILENO, elt, i);
    return;
}

void printlist(s_printlist *list)
{
    s_printlist *save;
    while (list != NULL)
    {
        printnode(list->elt);
        save = list;
        if (list->next != NULL)
        {
            write(STDOUT_FILENO, "-", 1);
        }
        else
        {
            write(STDOUT_FILENO, "\n", 1);
        }
        list = list->next;
        free(save);
    }
}

s_printlist *addprintlist(int elt, s_printlist *list)
{
    if (list == NULL)
    {
        s_printlist *newlist = malloc(sizeof(s_printlist));
        newlist->elt = elt;
        newlist->next = 0;
        list = newlist;
    }
    else
    {
        s_printlist *tmp = list;
        s_printlist *newitem = malloc(sizeof(s_printlist));
        newitem->elt = elt;
        newitem->next = NULL;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newitem;
    }
    return (list);
}

s_printlist *recurabr(s_btree *tree, s_printlist *list)
{
    if (tree == NULL)
    {
        return list;
    }
    list = addprintlist(tree->elt, list);
    list = recurabr(tree->Filsgauche, list);
    list = recurabr(tree->Filsdroite, list);
    return list;
}

void b_prefix(s_btree *tree)
{
    s_printlist *list = NULL;
    list = recurabr(tree, list);
    printlist(list);
}