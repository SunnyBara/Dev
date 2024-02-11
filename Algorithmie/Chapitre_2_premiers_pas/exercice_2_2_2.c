// pas de code;

// A <a1...an>  on cherche i tel que  tel que A[i] = min[A];
// save = A[1]
// A[1] = A[i]
// A[i] = save
// on cherche le second element le plus petit tel que pour i  A[i] >= min[A] et i != 1;
// puis
//
// save = A[2]
// A[2] = A[i]
// A[i] = save
#include <stdio.h>
#include <stdlib.h>

void triepartselection(int *tab, int size)
{
    int i = 0;       // c1 1
    int min;         // c2 1
    int j;           // c3 1
    int save;        // c4 1
    while (i < size) // c5  n
    {
        min = i;         // c6 n-1
        j = i + 1;       // c7 n-1
        while (j < size) // c8 *(sum des i de  1 à n-1 des (n-i); ~somme des i de 1 à n-1 ; => n(n-1)/2
        {
            if (tab[j] < tab[min]) // c9 *(sum des i de  1 à n-1 des (n-1 - i); ~somme des i de 1 à n-2 => (n-2)(n-1)/2
            {
                min = j; // c10 *(sum des i de  1 à n-1 des (n-1 - i); ~somme des i de 1 à n-2  => (n-1)(n-2)/2;
            }
            j += 1; // c11 *(sum des i de  1 à n-1 des (n-1 - i); ~somme des i de 0 à n-2 ;
        }
        save = tab[i];     // c12 n-1
        tab[i] = tab[min]; // c13 n-1
        tab[min] = save;   // c14 n-1
        i += 1;            // c15 n-1
    }
}
// complexité O(n^2) dans tous les cas;

int main()
{
    int tab[5] = {6, 13, 2, 9, 4};
    triepartselection(tab, 5);
    int i = 0;
    printf("[");
    while (i < 4)
    {
        printf("%d, ", tab[i]);
        i += 1;
    }
    printf("%d]\n", tab[i]);
    return 0;
}
