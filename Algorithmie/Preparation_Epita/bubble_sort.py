
def my_bubble_sort(tab):
    i = 0
    j = 0
    size =  len(tab)
    while i<size:
        j = 0
        permutation = 0
        while j < size - i-1:
            if tab[j] >= tab[j+1]:
                permutation += 1
                save = tab[j]
                tab[j] = tab[j + 1]
                tab[j + 1] = save
            j += 1
        if permutation == 0:
            i = size
        i +=1
    return tab

tab = [3, 4, 1, 24, 9, 4, 1, 45]
my_bubble_sort(tab)
print(tab)
