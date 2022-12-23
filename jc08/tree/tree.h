typedef struct btree{
    int elt;
    struct btree *right;
    struct btree *left;
    struct btree *prev;
}s_btree;
s_btree *b_node_create(int elt);
s_btree *b_node_add(s_btree *tree, int elt);
s_btree *b_node_find(s_btree *tree, int elt);
int b_node_delete(s_btree *tree, int elt);
void b_prefixe(s_btree *tree);