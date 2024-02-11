#include <stdio.h>
int *fusion(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i = 0;
    int j = 0;
    int L[n1];
    int R[n2];
    while (i < n1)
    {
        L[i] = A[i];
        i += 1;
    }

    while (j < n2)
    {
        R[j] = A[n1 + j];
        j += 1;
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (R[j] < L[i])
        {
            A[i + j] = R[j];
            j += 1;
        }
        else
        {
            A[i + j] = L[i];
            i += 1;
        }
    }
    if (i == n1)
    {
        printf("dumpn2\n");
        while (j < n2)
        {
            A[i + j] = R[j];
            j += 1;
        }
    }
    else if (j == n2)
    {
        printf("dumpn1\n");
        while (i < n1)
        {
            A[i + j] = L[i];
            i += 1;
        }
    }
    return A;
}

int main()
{
    int A[7] = {56, 21, 34, 2, 54, 4, 9};
    fusion(A, 0, 3, 6);
    int i = 0;
    printf("[");
    while (i < 6)
    {
        printf("%d, ", A[i]);
        i += 1;
    }
    printf("%d]\n", A[i]);
    return 0;
}