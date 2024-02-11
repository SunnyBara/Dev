#include "./../btree.h"
#include <stdlib.h>
#include <stdio.h>

int recurheight(s_btree *tree, int heightmax, int height)
{
    if (height > heightmax)
    {
        heightmax = height;
    }
    if (tree != NULL)
    {
        heightmax = recurheight(tree->Filsgauche, heightmax, height + 1);
        heightmax = recurheight(tree->Filsdroite, heightmax, height + 1);
    }

    return (heightmax);
}

int b_height(s_btree *tree)
{
    return (recurheight(tree, -1, -1));
}