#include "stdio.h"
void tri_cocktail(int *tab, int size)
{
    int i = 0;
    int j = 0;
    int save = 0;
    char permuted = 1;
    while (permuted)
    {
        permuted = 0;
        j = i;
        while (j < size - 1 - i)
        {
            if (tab[j] > tab[j + 1])
            {
                save = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = save;
                permuted = 1;
            }
            j += 1;
        }
        while (j > i)
        {
            if (tab[j] < tab[j - 1])
            {
                save = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = save;
                permuted = 1;
            }
            j -= 1;
        }
        i += 1;
    }

    return;
}