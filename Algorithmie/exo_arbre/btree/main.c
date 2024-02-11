#include <stdio.h>
#include "./../btree.h"
#include "unistd.h"

int main(void)
{
    s_btree *tree = b_node_create(7);
    printf("%d height \n", b_height(tree));
    tree = b_node_add(tree, 2);
    tree = b_node_add(tree, 10);
    tree = b_node_add(tree, 11);
    tree = b_node_add(tree, 1);
    tree = b_node_add(tree, 6);
    tree = b_node_add(tree, 4);
    tree = b_node_add(tree, 7);
    tree = b_node_add(tree, 14);
    tree = b_node_add(tree, 13);
    tree = b_node_add(tree, 5);
    printf("%d height \n", b_height(tree));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node pas dans l'abre %d\n", b_node_delete(tree, 2));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 7));
    // printf("nouvelle root %d\n", tree->elt);
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 7));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 1));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 6));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 14));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 13));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 4));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 3));
    // b_prefix(tree);
    // printf("%d size \n", b_size(tree));
    // printf("suppression d'une node dans l'abre %d\n", b_node_delete(tree, 10));
    // b_prefix(tree);
    // tree = NULL;
    // printf("%d size \n", b_size(tree));
    return 0;
}