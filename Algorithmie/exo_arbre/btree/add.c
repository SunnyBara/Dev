#include "./../btree.h"
#include "stdlib.h"
#include <stdio.h>

s_btree *b_node_add(s_btree *tree, int elt)
{
    s_btree *newnode = b_node_create(elt);
    s_btree *tmp = tree;
    s_btree *save;
    while (tmp != NULL)
    {
        save = tmp;
        if (tmp->elt < elt)
        {
            tmp = tmp->Filsdroite;
        }
        else
        {
            tmp = tmp->Filsgauche;
        }
    }
    if (save->elt < elt)
    {
        save->Filsdroite = newnode;
    }
    else
    {
        save->Filsgauche = newnode;
    }
    return (tree);
}