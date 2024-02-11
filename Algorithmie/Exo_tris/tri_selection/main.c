

void tri_selection(int *tab, int size);
void print_tab(int *tab, int size);

int main(void)
{
    int tab[12] = {2, 5, 9, 3, 43, 2, 53, 86, 12, 92, 1, 283};
    print_tab(tab, 12);
    tri_selection(tab, 12);
    print_tab(tab, 12);
    return 0;
}