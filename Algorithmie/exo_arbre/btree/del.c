#include "./../btree.h"
#include <stdlib.h>

int b_node_delete(s_btree *tree, int elt)
{
    int cr = 0;
    s_btree *root = tree;
    tree = b_node_find(tree, elt);
    if (tree != NULL)
    {
        s_btree *save = tree;
        if (tree->Filsgauche != NULL)
        {
            s_btree *tmp = tree->Filsgauche;
            save = tree->Filsgauche;
            while (tmp->Filsdroite != NULL)
            {
                tmp = tmp->Filsdroite;
            }
            tmp->Filsdroite = tree->Filsdroite;
        }
        else if (tree->Filsdroite != NULL)
        {
            save = tree->Filsdroite;
        }
        else
        {
            if (root->elt != elt)
            {
                while ((root->Filsdroite->elt != elt || root->Filsdroite == NULL) && (root->Filsgauche == NULL || root->Filsgauche->elt != elt))
                {
                    if (root->elt < elt)
                    {
                        root = root->Filsdroite;
                    }
                    else
                    {
                        root = root->Filsgauche;
                    }
                }
                if (root->Filsdroite != NULL && root->Filsdroite->elt == elt)
                {
                    root->Filsdroite = NULL;
                }
                else if (root->Filsgauche != NULL && root->Filsgauche->elt == elt)
                {
                    root->Filsgauche = NULL;
                }
                tree = NULL;
            }
            else
            {
                tree = NULL;
                free(root);
            }
        }
        if (tree != NULL)
        {
            tree->Filsdroite = save->Filsdroite;
            tree->Filsgauche = save->Filsgauche;
            tree->elt = save->elt;
        }

        cr = 1;
    }
    return (cr);
}