#include <stdlib.h>
// entrée soit A = <a1,...,an> et v ;
// sortie entier i tel que A[i] = v || nil si v n'est pas dans A;

int exo(int *A, int v, int sizeA)
{
    int i = 0;                     // c1 1
    while (i < sizeA && A[i] != v) // c2 n si on trouve pas v ou i fois avec i tel que A[i] = v
    {
        i += 1; // c3 n-1 si on trouve pas v ou i fois avec i tel que A[i] = v
    }
    if (i == sizeA) // c4 1
    {
        return NULL; // c5 1
    }
    else
    {
        return i; // c6 1
    }
}

// complexité O(n) dans le cas défavorable
// en moyenne on test n/2 => complexité O(n)