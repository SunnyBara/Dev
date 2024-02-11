#include <stdio.h>
void tripartinsertion(int *tab, int size)
{
    int j = 1;
    int key;
    while (j < size)
    {
        int i = j - 1;
        key = tab[j];
        while (i >= 0 && tab[i] < key)
        {
            tab[i + 1] = tab[i];
            i -= 1;
        }
        tab[i + 1] = key;
        j += 1;
    }
    return;
}

int main()
{
    int tab[6] = {31, 41, 59, 26, 41, 58};
    tripartinsertion(tab, 6);
    int i = 0;
    printf("[");
    while (i < 5)
    {
        printf("%d, ", tab[i]);
        i += 1;
    }
    printf("%d]\n", tab[i]);
    return 0;
}