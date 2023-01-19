#include "isABR.h"
#include <stdlib.h>
#include <stdio.h>
s_nombres *initialisation(s_nombres *list)
{
    list = malloc(sizeof(s_nombres));
    list->next = NULL;
    list->puissances = malloc(sizeof(s_puissance));
    list->puissances->puissance = 0;
    list->value = 0;
    return (list);
}
s_nombres *conv(char *tab)
{
    int i = 0;
    s_nombres *node;
    s_nombres *tmp;
    s_nombres *new;
    node = initialisation(node);
    tmp = node;
    if (tab[0] == 'x' && tab[1] == '\0')
    {
        node->value = 'x';
        return (node);
    }
    while (tab[i] != '\0')
    {
        tmp->value = tab[i] - 48;
        tmp->puissances->puissance = tmp->puissances->puissance + 1;
        new = malloc(sizeof(s_nombres));
        tmp->next = new;
        tmp->next->puissances = tmp->puissances;
        tmp = tmp->next;
        i++;
    }
    return (node);
}

char *valid(char *arg)
{
    int i = 0;
    while (arg[i] != '\0')
    {
        printf("arg[i] = %c\n", arg[i]);
        if (arg[0] == 'x' && arg[1] == '\0')
        {
            break;
        }
        else if (arg[i] < 48 || arg[i] > 57)
        {
            return ("invalid");
        }
        i++;
    }
    return ("conv");
}
void puissance(s_nombres *node)
{
    s_nombres *tmp;
    tmp = node;
    while (tmp->value == 0)
    {
        node->puissances->puissance = node->puissances->puissance - 1;
        tmp = tmp->next;
    }
    return;
}
int comparevalue(s_nombres *elt, s_nombres *L)
{
    if (elt->value == 'x' || L->value == 'x')
    {
        return (1);
    }
    puissance(elt);
    puissance(L);
    if (elt->puissances->puissance < L->puissances->puissance)
    {
        return (1);
    }
    else if (elt->puissances->puissance > L->puissances->puissance)
    {
        return (0);
    }
    else
    {
        while (elt->value == L->value)
        {

            elt = elt->next;
            L = L->next;
        }
        if (elt->value <= L->value)
        {
            return (1);
        }
        else if (elt->value > L->value)
        {
            return (0);
        }
    }
}
int compare(s_nombres *elt, int argc, s_nombres **L1, s_nombres **L2)
{
    int i = 0;
    int check = 1;
    while (i < argc && check == 1)
    {
        check = comparevalue(elt, L1[i]);
        i++;
    }
    i = 0;
    while (i < argc && check == 1)
    {
        check = comparevalue(L2[i], elt);
        i++;
    }
    if (check != 1)
    {
        return (0);
    }
    else
    {
        return (1);
    }
}
s_puissance *recurabr(s_nombres **chaîne, int i, int argc, s_nombres **L1, s_nombres **L2, s_puissance *test)
{
    if (i > argc)
    {
        return (test);
    }
    else if (chaîne[i - 1]->value == 'x')
    {
        test->puissance ++;
        return(test);
    }
    test->puissance = test->puissance + compare(chaîne[i - 1], argc, L1, L2);
    L1[i - 1] = chaîne[i - 1];
    recurabr(chaîne, 2 * i, argc, L1, L2, test);
    L1[i - 1]->value = 'x';
    L1[i - 1]->next = NULL;
    L1[i - 1]->puissances->puissance = 0;
    L2[i - 1] = chaîne[i - 1];
    recurabr(chaîne, 2 * i + 1, argc, L1, L2, test);
    return(test);
}

void remplissage(s_nombres **L, int argc)
{
    int i = 0;
    while (i < argc)
    {
        L[i]->value = 'x';
        i++;
    }
    return;
}

int is_abr(char **argv, int argc)
{
    int i = 0;
    char *test;
    s_nombres **L1;
    s_nombres **L2;
    s_nombres **chaîne;
    chaîne = malloc((argc - 1) * sizeof(s_nombres *));
    L1 = malloc((argc - 1) * sizeof(s_nombres *));
    L2 = malloc((argc - 1) * sizeof(s_nombres *));
    while (i < argc - 1)
    {
        L1[i] = initialisation(L1[i]);
        L2[i] = initialisation(L2[i]);
        chaîne[i] = initialisation(chaîne[i]);
        i++;
    }
    i = 1;
    remplissage(L1, argc - 1);
    remplissage(L2, argc - 1);
    while (i < argc)
    {
        test = valid(argv[i]);
        if (test == "invalid")
        {
            return (2);
        }
        else
        {
            chaîne[i - 1] = conv(argv[i]);
        }
        i++;
    }
    s_puissance *abrrrr;
    abrrrr = malloc(sizeof(s_puissance));
    abrrrr->puissance = 0;
    abrrrr = (recurabr(chaîne, 1, argc - 1, L1, L2, abrrrr));
    if (abrrrr->puissance < argc - 1)
    {
        return(0);
    }
    return (1);
}