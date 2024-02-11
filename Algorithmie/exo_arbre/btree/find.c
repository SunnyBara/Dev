#include "./../btree.h"
#include <stdlib.h>

s_btree *b_node_find(s_btree *tree, int elt)
{
    while (tree != NULL && tree->elt != elt)
    {
        if (tree->elt < elt)
        {
            tree = tree->Filsdroite;
        }
        else
        {
            tree = tree->Filsgauche;
        }
    }
    return (tree);
}