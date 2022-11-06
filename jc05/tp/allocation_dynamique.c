#include "stdio.h"
#include "jc05.h"
#include "stdlib.h"
int **matalloc(unsigned int n, int v)
{
    int **mat;
    int i=0;
    mat = malloc(n*sizeof(int*));
    while (i < n)
    {
        mat[i] = malloc(n*sizeof(int));
        i++;
    }
    initmatc(mat,n,v);
    printmat(mat,n,n);
    return(mat);
}

void matfree(int **m, int n)
{
    int i=0;
    int j=0;
    while (i < n)
    {
        while(j<n)
        {
            free(m[i][j]);
            j++;
        }
        i++;
        j=0;
    }
}