#include "stdio.h"
#include "jc05.h"
void memswap(void *a, void *b)
{
    void **c;
    void *abis;
    abis = a;
    c = &a;
    *c = b;
    c = &b;
    *c = abis;
    return;
}

int **matadd( int **a,  int **b, int **r)
{
    int i = 0;
    int lin = 1;
    int j = 0;
    int col = 1;
    while (i < 2)
    {
        while (j < 2)
        {   
            r[i][j]=a[i][j]+b[i][j];
            j++;
        }
        j=0;
        i++;
    }
    return(r);
}

int **matsub(int **a, int **b, int **r)
{
    int i = 0;
    int j = 0;
    while (i < 2)
    {
        while (j < 2)
        {   
            r[i][j]=a[i][j]- b[i][j];
            j++;
        }
        j=0;
        i++;
    }
    return(r);
}
int **matmul(int **a, int **b, int **r)
{
    int i = 0;
    int k = 0;
    int caze = 0;
    int j = 0;
    while (i < 2)
    {
	while (k < 2)
	{      
	    while (j < 2)
	    {
		caze = a[i][j] * b[j][k] + caze; 
		j++;
	    }
	    r[i][k] = caze;
	    j=0;
	    k++;
	    caze = 0;
	}
	i ++;
	k = 0;
    }
}
int **matscalmul(int **a, int b, int **r)
{
    int i = 0;
    int j = 0;
    while (i < 2)
    {
        while (j < 2)
        {   
            r[i][j]= a[i][j] * b;
            j++;
        }
        j=0;
        i++;
    }
    return(r);
}
