#include <stdio.h>

int *my_bubble_sort(int *tab, int size)
{
    int i = 0;
    int j = 0;
    int save;
    int permutation = 0;
    while (i < size)
    {
        permutation = 0;
        j = 0;
        while (j < size - i - 1)
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
    }
    return tab;
}

int main(void)
{
    int tab[8] = {3, 4, 1, 24, 9, 4, 1, 45};
    my_bubble_sort(tab, 8);
    int i = 0;
    while (i < 8)
    {
        printf("%d,", tab[i]);
        i += 1;
    }
    printf("\n");
}