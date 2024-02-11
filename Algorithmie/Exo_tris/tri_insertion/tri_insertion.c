

void tri_insertion(int *tab, int size)
{
    int i = 1;
    int j = 0;
    int save = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (tab[j] < tab[j - 1] && j > 0)
        {
            save = tab[j - 1];
            tab[j - 1] = tab[j];
            tab[j] = save;
            j -= 1;
        }
        i += 1;
    }
    return;
}