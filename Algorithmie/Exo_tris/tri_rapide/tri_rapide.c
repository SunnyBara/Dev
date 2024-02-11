#include "stdio.h"

void print_tab(int *tab, int size);

int tri(int *tab, int pivotpos, int size)
{
    int i = 0;
    int trie = 1;
    int save;
    while (trie)
    {
        if (tab[pivotpos] > tab[i] && i > pivotpos)
        {
            save = tab[i];
            tab[i] = tab[pivotpos];
            tab[pivotpos] = save;
            pivotpos = i;
            i = 0;
        }
        else if (tab[pivotpos] < tab[i] && i < pivotpos)
        {
            save = tab[i];
            tab[i] = tab[pivotpos];
            tab[pivotpos] = save;
            pivotpos = i;
            i = 0;
        }
        if (i >= size)
        {
            trie = 0;
        }
        i += 1;
    }
    return pivotpos;
}

void recurtrie(int *tab, int start, int end)
{
    if (start > end)
    {
        return;
    }
    int pivotpos = tri(tab, (start + end) / 2, end);
    recurtrie(tab, (pivotpos / 2) - 1, pivotpos - 1);
    recurtrie(tab, pivotpos + 1, end);
    return;
}

void tri_rapide(int *tab, int size)
{
    recurtrie(tab, 0, size);
    return;
}