#include <stdlib.h>
#include "./../btree.h"

s_btree *b_node_create(int elt)
{
    s_btree *newnode;
    newnode = malloc(sizeof(s_btree));
    newnode->elt = elt;
    newnode->Filsgauche = NULL;
    newnode->Filsdroite = NULL;
    return (newnode);
}
