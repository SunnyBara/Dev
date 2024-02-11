#include "stdio.h"

void print_tab(int *tab, int size)
{
    int i = 1;
    printf("[%d, ", tab[0]);
    while (i < size - 1)
    {
        printf("%d, ", tab[i]);
        i += 1;
    }
    printf("%d]\n", tab[i]);
}