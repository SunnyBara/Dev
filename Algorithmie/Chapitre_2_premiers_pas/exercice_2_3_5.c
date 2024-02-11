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
        return -1; // c5 1
    }
    else
    {
        return i; // c6 1
    }
}

// complexité O(n) dans le cas défavorable
// en moyenne on test n/2 => complexité O(n)

// Debut exo 2_3_5
//
#include <stdio.h>

int dicho(int *A, int v, int sizeA)
{
    int min = 0;                                 // c1 1
    int max = sizeA;                             // c2 1
    while (v != A[(max + min) / 2] && min < max) // c3
    {
        printf("min %d  max %d\n", min, max);
        if (v > A[(max + min) / 2])
        {
            min = ((max + min) / 2) + 1;
        }
        else if (v < A[(max + min) / 2])
        {
            max = ((max + min) / 2) - 1;
        }
    }
    if (v == A[(max + min) / 2])
    {
        return ((max + min) / 2);
    }
    return (-1);
}

int recurdicho(int *A, int min, int max, int v)
{
    int c;
    if (min > max)
    {
        return -1;
    }
    if (A[(min + max) / 2] == v)
    {
        return ((min + max) / 2);
    }
    else if ((A[(min + max) / 2] > v))
    {
        c = recurdicho(A, min, ((min + max) / 2) - 1, v);
    }
    else
    {
        c = recurdicho(A, ((min + max) / 2) + 1, max, v);
    }
    return c;
}

int main()
{
    int A[15] = {3, 7, 8, 9, 10, 11, 12, 59, 63, 67, 72, 75, 81, 84, 89};
    int i = recurdicho(A, 0, 15, 3);
    printf("%d\n", i);
    return 0;
}