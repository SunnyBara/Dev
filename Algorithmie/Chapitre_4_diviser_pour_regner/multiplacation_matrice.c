#include <stdio.h>

int Size_X = 2;
int Size_Y = 3;

void multi_mat(int A[Size_X][Size_Y], int B[Size_Y][Size_X])
{
    int C[Size_X][Size_X];
    int eleme;
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < Size_X)
    {
        k = 0;
        eleme = 0;
        while (k < Size_Y)
        {
            printf("multiplication de Aik = %d Bkj = %d add to eleme %d\n", A[i][k], B[k][j], eleme);
            eleme += A[i][k] * B[k][j];
            k += 1;
        }
        C[i][j] = eleme;
        j += 1;
        if (j == Size_Y)
        {
            i += 1;
            j = 0;
        }
    }
    i = 0;
    j = 0;
    while (i < Size_X)
    {
        j = 0;
        printf("|");
        while (j < Size_X - 1)
        {
            printf("%d ,", C[i][j]);
            j += 1;
        }
        printf("%d|\n", C[i][j]);
        i += 1;
    }
    return;
}

int main(void)
{
    int A[Size_X][Size_Y];
    int B[Size_Y][Size_X];
    A[0][0] = 3;
    A[0][1] = 2;
    A[0][2] = 5;
    A[1][0] = 7;
    A[1][1] = 10;
    A[1][2] = 7;
    B[0][0] = 1;
    B[0][1] = 3;
    B[1][0] = 5;
    B[1][1] = 9;
    B[2][0] = 4;
    B[2][1] = 12;
    multi_mat(A, B);
    return 0;
}