#include "stdio.h"
void tri_a_bulle(int *tab, int size)
{
    int i = 0;
    int j = 0;
    int save = 0;
    int permutation = 0;
    int passage = 0;
    while (i < size)
    {
        j = 0;
        permutation = 0;
        while (j < size - 1 - i)
        {
            if (tab[j] > tab[j + 1])
            {
                permutation += 1;
                save = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = save;
            }
            j += 1;
        }
        if (permutation == 0)
        {
            i = size;
        }
        i += 1;
        passage += 1;
    }
    printf("l'algo a fait %d tours de boucles\n", passage);
    return;
}