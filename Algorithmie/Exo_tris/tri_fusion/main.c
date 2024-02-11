#include <stdlib.h>

void tri_fusion(int *A, int start, int end);
void print_tab(int *tab, int size);

int main(void)
{
    int tab[12];
    tab[0] = 2;
    tab[1] = 5;
    tab[2] = 9;
    tab[3] = 3;
    tab[4] = 43;
    tab[5] = 2;
    tab[6] = 53;
    tab[7] = 86;
    tab[8] = 12;
    tab[9] = 92;
    tab[10] = 1;
    tab[11] = 283;
    print_tab(tab, 12);
    tri_fusion(tab, 0, 11); // index start + index end pas size idiot
    print_tab(tab, 12);
    return 0;
}