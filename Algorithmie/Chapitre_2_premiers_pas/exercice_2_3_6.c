#include <stdio.h>

void showtab(int *tab, int j)
{
    int i = 0;
    printf("[");
    while (i < j - 1)
    {
        printf("%d, ", tab[i]);
        i += 1;
    }
    printf("%d]\n", tab[i]);
}

void tripartinsertion(int *tab, int size)
{
    int j = 1;
    int key;
    while (j < size)
    {
        int min = 0;
        int max = j - 1;
        int moy = 1;
        key = tab[j];
        while (min <= max)
        {
            moy = (min + max) / 2;
            if (tab[moy] <= key)
            {
                min = moy + 1;
            }
            else
            {
                max = moy - 1;
            }
        }
        if (tab[moy] < key)
        {
            moy += 1;
        }
        while (moy <= j)
        {
            tab[j] = tab[moy];
            tab[moy] = key;
            key = tab[j];
            moy += 1;
        }
        j += 1;
    }
    return;
}

int main()
{
    int A[15] = {10, 11, 12, 59, 63, 67, 72, 75, 89, 3, 81, 84, 7, 8, 9};
    tripartinsertion(A, 15);
    int i = 0;
    printf("[");
    while (i < 14)
    {
        printf("%d, ", A[i]);
        i += 1;
    }
    printf("%d]\n", A[i]);
    return 0;
}