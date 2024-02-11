

void tri_cocktail(int *tab, int size);
void print_tab(int *tab, int size);

int main(void)
{
    int arr[] = {5, 4, 3, 2, 1}; // Reverse order
    int size = sizeof(arr) / sizeof(arr[0]);
    int tab[12] = {2, 5, 9, 3, 43, 2, 53, 86, 12, 92, 1, 283};
    int tab2[4] = {1, 4, 5, 12};
    print_tab(tab, 12);
    tri_cocktail(tab, 12);
    print_tab(tab, 12);
    print_tab(arr, size);
    tri_cocktail(arr, size);
    print_tab(arr, size);
    return 0;
}