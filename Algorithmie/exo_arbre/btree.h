#ifndef Btree_h
#define Btree_h
typedef struct btree
{
    int elt;
    struct btree *Filsgauche;
    struct btree *Filsdroite;
} s_btree;
s_btree *b_node_create(int elt);
s_btree *b_node_add(s_btree *tree, int elt);
void b_prefix(s_btree *tree);
s_btree *b_node_find(s_btree *tree, int elt);
int b_node_delete(s_btree *tree, int elt);
unsigned int b_size(s_btree *tree);
int b_height(s_btree *tree);
#endif