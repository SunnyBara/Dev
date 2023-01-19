#include "tree.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  s_btree *abr;
  s_btree *adr;
  abr = b_node_create(5);
  b_node_add(abr, 4);
  b_node_add(abr, 3);
  adr = b_node_find(abr, 3);
  printf("prev %i : %i\n", adr->elt, adr->prev->elt);
  b_prefixe(abr);
  b_node_delete(abr,5);
  b_prefixe(abr);
  return (0);
}