#include "tree.h"
#include <unistd.h>
#include <stdlib.h>
s_btree *b_node_create(int elt)
{
    s_btree *node;
    node = malloc(sizeof(s_btree));
    node->right = NULL;
    node->left = NULL;
    node->elt = elt;
    node->prev = NULL;
    return (node);
}

s_btree *recuradd(s_btree *tree, s_btree *address, s_btree *save)
{
    if (tree == NULL)
    {
        address->prev = save;
        return (address);
    }
    save = tree;
    if (tree != NULL)
    {
        if (tree->elt < address->elt)
        {
            tree->right = recuradd(tree->right, address, save);
        }
        else
        {
            tree->left = recuradd(tree->left, address, save);
        }
    }
    return (tree);
}

s_btree *b_node_add(s_btree *tree, int elt)
{
    s_btree *address;
    s_btree *save;
    address = b_node_create(elt);
    return (recuradd(tree, address, save));
}
void printnode(int elt)
{
    int i = elt;
    int j = 1;
    int puissance = 1;
    char writ[1];
    while (i > 9)
    {
        i = i / 10;
        puissance = puissance * 10;
        j++;
    }
    i = elt;
    while (j > 0)
    {
        i = i / puissance;
        writ[0] = (char)i + 48;
        write(STDOUT_FILENO, writ, 1);
        i = elt - i * puissance;
        puissance = puissance / 10;
        j--;
    }
    write(STDOUT_FILENO, "-", 1);
    return;
}
void recurprefix(s_btree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printnode(tree->elt);
        recurprefix(tree->left);
        recurprefix(tree->right);
    }
    return;
}
void b_prefixe(s_btree *tree)
{
    recurprefix(tree);
    write(STDOUT_FILENO, "\n", 1);
    return;
}

s_btree *recurfind(s_btree *tree, s_btree *address, int elt)
{
    if (tree == NULL)
    {
        return (NULL);
    }
    else if (tree->elt == elt)
    {
        return (tree);
    }
    else if (tree->elt > elt)
    {
        address = recurfind(tree->left, address, elt);
    }
    else if (tree->elt < elt)
    {
        address = recurfind(tree->right, address, elt);
    }
    return (address);
}
s_btree *b_node_find(s_btree *tree, int elt)
{
    s_btree *address;
    return (recurfind(tree, address, elt));
}
s_btree *deletedroit(s_btree *addresse)
{
    s_btree *erase;
    erase = addresse->left;
    if (addresse->left == NULL && addresse->right == NULL && addresse->prev != NULL)
    {
        addresse->prev->right = NULL;
    }
    else if (addresse->left == NULL && addresse->prev != NULL)
    {
        addresse->right->prev = addresse->prev;
        if (addresse->right->elt >= addresse->prev->elt)
        {
            addresse->prev->right = addresse->right;
        }
        else if (addresse->right->elt < addresse->prev->elt)
        {
            addresse->prev->left = addresse->right;
        }
    }
    else if (addresse->right == NULL && addresse->prev != NULL)
    {
        addresse->left->prev = addresse->prev;
        if (addresse->left->elt >= addresse->prev->elt)
        {
            addresse->prev->right = addresse->left;
        }
        else if (addresse->left->elt < addresse->prev->elt)
        {
            addresse->prev->left = addresse->left;
        }
    }
    else if ((addresse->left != NULL && addresse->right != NULL) || (addresse->prev == NULL))
    {
        while (erase->right != NULL)
        {
            erase = erase->right;
        }
        erase->right = addresse->right;
        if (addresse->right != NULL)
        {
            addresse->right->prev = erase;
        }
        if (addresse->left != NULL)
        {
            addresse->left->prev = NULL;
        }
        if (addresse->prev == NULL)
        {
            addresse = addresse->left;
        }
    }
    return(addresse);
}
int b_node_delete(s_btree *tree, int elt)
{
    s_btree *addresse;
    addresse = recurfind(tree, addresse, elt);
    tree = deletedroit(addresse);
    return (0);
}