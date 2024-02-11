

void tri_selection(int *tab, int size)
{
    int i = 0;
    int j = 0;
    int min = 0;
    int save = 0;
    while (i < size - 1)
    {
        j = i + 1;
        min = i;
        while (j < size)
        {
            if (tab[j] < tab[min])
            {
                min = j;
            }
            j += 1;
        }
        if (min != i)
        {
            save = tab[i];
            tab[i] = tab[min];
            tab[min] = save;
        }
        i += 1;
    }
    return;
}