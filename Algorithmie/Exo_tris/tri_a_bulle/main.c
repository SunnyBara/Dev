

void tri_a_bulle(int *tab, int size);
void print_tab(int *tab, int size);

int main(void)
{
    int tab[12] = {2, 5, 9, 3, 43, 2, 53, 86, 12, 92, 1, 283};
    int tab2[4] = {1, 4, 5, 12};
    print_tab(tab, 12);
    tri_a_bulle(tab, 12);
    print_tab(tab, 12);
    print_tab(tab2, 12);
    tri_a_bulle(tab2, 4);
    print_tab(tab2, 12);
    return 0;
}