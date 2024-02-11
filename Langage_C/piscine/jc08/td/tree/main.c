#include "tree.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  s_btree *tree = b_node_create(7);
  tree = b_node_add(tree, 3);
  tree = b_node_add(tree, 10);
  tree = b_node_add(tree, 1);
  tree = b_node_add(tree, 6);
  tree = b_node_add(tree, 4);
  tree = b_node_add(tree, 7);
  tree = b_node_add(tree, 14);
  tree = b_node_add(tree, 13);
  b_prefixe(tree);
  printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 3));
  printf("nouvelle root %d\n", tree->elt);
  return (0);
}