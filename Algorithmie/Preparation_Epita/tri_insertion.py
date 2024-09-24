def my_insert_sort(tab):
    i = 1
    size = len(tab)
    while i < size:
        j = i
        while j > 0 and tab[j] < tab[j - 1]:
            save = tab[j]
            tab[j] = tab[j-1]
            tab[j-1] = save
            j -=1
        i += 1

tab = [3, 4, 1, 2,1,24, 9, 4, 4,1, 45]
my_insert_sort(tab)
print(tab)
