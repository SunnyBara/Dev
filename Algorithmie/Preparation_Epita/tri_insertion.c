#include <stdio.h>

int *tri_insertion(int *tab, int size)
{
    int i = 0;
    int j = 0;
    int save = 0;
    while (i < size)
    {
        j = i;
        while (j > 0)
        {
            if (tab[j] < tab[j - 1])
            {
                save = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = save;
            }
            j--;
        }
        i += 1;
    }
    return (tab);
}

int main(void)
{
    int tab[8] = {3, 4, 1, 24, 9, 4, 1, 45};
    tri_insertion(tab, 8);
    int i = 0;
    while (i < 8)
    {
        printf("%d,", tab[i]);
        i += 1;
    }
    printf("\n");
}