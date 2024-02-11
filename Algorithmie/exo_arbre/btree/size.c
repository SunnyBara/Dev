#include "./../btree.h"
#include <stdlib.h>
#include <stdio.h>

int recursize(s_btree *tree, int size)
{
    printf("segfault\n");
    if (tree)
    {
        size += 1;
        size = recursize(tree->Filsgauche, size);
        size = recursize(tree->Filsdroite, size);
    }
    return size;
}

unsigned int b_size(s_btree *tree)
{
    return (recursize(tree, 0));
}