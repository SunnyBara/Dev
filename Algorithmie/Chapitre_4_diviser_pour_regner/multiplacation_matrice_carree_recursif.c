#include <stdlib.h>
#include <stdio.h>

int **Addmatrice(int **A, int **B, int size)
{
    int i = 0;
    int **C;
    C = malloc(size * sizeof(int *));

    while (i < size)
    {
        C[i] = malloc(size * sizeof(int));
        i += 1;
    }
    i = 0;
    int j = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            C[i][j] = A[i][j] + B[i][j];
            j += 1;
        }
        i += 1;
    }
    return C;
}

int **remplirC(int **C, int **C11, int **C12, int **C21, int **C22, int n)
{
    int i = 0;
    int j = 0;
    while (i < n / 2)
    {
        j = 0;
        while (j < n / 2)
        {
            C[i][j] = C11[i][j];
            C[i][j + n / 2] = C12[i][j];
            C[i + n / 2][j] = C21[i][j];
            C[i + n / 2][j + n / 2] = C22[i][j];
            j += 1;
        }
        i += 1;
    }
    return C;
}

int **decomposeMatrice(int **A, int starti, int startj, int endi, int endj)
{
    int n = endi - starti;
    int **B;
    B = malloc(n * sizeof(int *));
    int i = 0;
    while (i < n)
    {
        B[i] = malloc(n * sizeof(int));
        i += 1;
    }
    int j = startj;
    i = starti;
    int l = 0;
    int k = 0;
    while (i < endi)
    {
        k = 0;
        j = startj;
        while (j < endj)
        {
            B[l][k] = A[i][j];
            k += 1;
            j += 1;
        }
        i += 1;
        l += 1;
    }
    return (B);
}

void printmat(int **C, int size)
{
    int i = 0;
    int j = 0;
    while (i < size)
    {
        j = 0;
        printf("|");
        while (j < size - 1)
        {
            printf("%d ,", C[i][j]);
            j += 1;
        }
        printf("%d|\n", C[i][j]);
        i += 1;
    }
    return;
}

int **Multiplication_matrice_carree_recursif(int **A, int **B, int size)
{
    printf("size %d\n", size);
    printf("je rentre avec la matrice A\n");
    printmat(A, size);
    printf("et la  matrices B\n");
    printmat(B, size);
    printf("===========\n");
    int n = size;
    int **C;
    C = malloc((n) * sizeof(int *));
    int i = 0;
    int j = 0;
    while (i < n)
    {
        C[i] = malloc(n * sizeof(int));
        i += 1;
    }
    if (n == 1)
    {
        printf("A[0][0] %d B[0][0] %d \n", A[0][0], B[0][0]);
        C[0][0] = A[0][0] * B[0][0];
        printf("je ressord\n");
    }
    else
    {

        printf("la?\n");
        int **C11 = Addmatrice(Multiplication_matrice_carree_recursif(decomposeMatrice(A, 0, 0, n / 2, n / 2), decomposeMatrice(B, 0, 0, n / 2, n / 2), n / 2), Multiplication_matrice_carree_recursif(decomposeMatrice(A, 0, n / 2, n / 2, n), decomposeMatrice(B, n / 2, 0, n, n / 2), n / 2), n / 2);
        int **C12 = Addmatrice(Multiplication_matrice_carree_recursif(decomposeMatrice(A, 0, 0, n / 2, n / 2), decomposeMatrice(B, 0, n / 2, n / 2, n), n / 2), Multiplication_matrice_carree_recursif(decomposeMatrice(A, 0, n / 2, n / 2, n), decomposeMatrice(B, n / 2, n / 2, n, n), n / 2), n / 2);
        int **C21 = Addmatrice(Multiplication_matrice_carree_recursif(decomposeMatrice(A, n / 2, 0, n, n / 2), decomposeMatrice(B, 0, 0, n / 2, n / 2), n / 2), Multiplication_matrice_carree_recursif(decomposeMatrice(A, n / 2, n / 2, n, n), decomposeMatrice(B, n / 2, 0, n, n / 2), n / 2), n / 2);
        int **C22 = Addmatrice(Multiplication_matrice_carree_recursif(decomposeMatrice(A, n / 2, 0, n, n / 2), decomposeMatrice(B, 0, n / 2, n / 2, n), n / 2), Multiplication_matrice_carree_recursif(decomposeMatrice(A, n / 2, n / 2, n, n), decomposeMatrice(B, n / 2, n / 2, n, n), n / 2), n / 2);
        printf("ou plus profond encore ? \n");
        remplirC(C, C11, C12, C21, C22, n);
    }
    return (C);
}

int main(void)
{
    int **A;
    int **B;
    int n = 2;
    A = malloc(n * sizeof(int *));
    B = malloc(n * sizeof(int *));
    int i = 0;
    while (i < n)
    {
        A[i] = malloc(n * sizeof(int));
        B[i] = malloc(n * sizeof(int));
        i += 1;
    }
    A[0][0] = 1;
    A[0][1] = 3;
    A[1][0] = 7;
    A[1][1] = 5;
    B[0][0] = 6;
    B[0][1] = 8;
    // B[0][2] = 5;
    // B[0][3] = 9;
    B[1][0] = 4;
    B[1][1] = 2;
    // B[1][2] = 5;
    // B[1][3] = 9;
    // B[2][0] = 1;
    // B[2][1] = 3;
    // B[2][2] = 5;
    // B[2][3] = 92;
    // B[3][0] = 1;
    // B[3][1] = 3;
    //   B[3][2] = 5;
    //  B[3][3] = 903;
    // int **Sousmat = decomposeMatrice(B, 2, 2, 4, 4);
    // remplirC(A, decomposeMatrice(B, 0, 0, 2, 2), decomposeMatrice(B, 0, 2, 2, 4), decomposeMatrice(B, 2, 0, 4, 2), decomposeMatrice(B, 2, 2, 4, 4), 4);
    // printmat(B, 4);
    // printf("============================\n");
    // printmat(A, 4);
    int **C = Multiplication_matrice_carree_recursif(A, B, 2);
    printf("============================\n");
    printmat(C, 2);
    //  int **C = Multiplication_matrice_carree_recursif(A, B, 2);
    // printmat(C, n);
}
