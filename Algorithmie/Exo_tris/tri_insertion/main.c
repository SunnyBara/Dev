

void tri_insertion(int *tab, int size);
void print_tab(int *tab, int size);

int main(void)
{
    int tab[13] = {2, 5, 9, 3, 43, 2, 53, 86, 12, 92, 1, 283, 23};
    print_tab(tab, 13);
    tri_insertion(tab, 13);
    print_tab(tab, 13);
    return 0;
}