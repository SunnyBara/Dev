#include <stdio.h>

void Fusion(int *A, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int L[n1];
    int R[n2];
    int i = 0;
    int j = 0;
    int k = start;
    while (j < n1)
    {
        L[j] = A[start + j];
        j += 1;
    }
    while (i < n2)
    {
        R[i] = A[mid + 1 + i];
        i += 1;
    }
    i = 0;
    j = 0;
    while (i < n2 && j < n1)
    {
        if (L[j] > R[i])
        {
            A[k] = R[i];
            i += 1;
        }
        else
        {
            A[k] = L[j];
            j += 1;
        }
        k += 1;
    }
    while (i < n2)
    {
        A[k] = R[i];
        i += 1;
        k += 1;
    }
    while (j < n1)
    {
        A[k] = L[j];
        j += 1;
        k += 1;
    }
    return;
}

void tri_fusion(int *A, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        tri_fusion(A, start, mid);
        tri_fusion(A, mid + 1, end);
        Fusion(A, start, mid, end);
    }
    return;
}