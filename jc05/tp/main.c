#include <stdio.h>
#include <stdlib.h>
#include "jc05.h"

void reversetest()
{    
    char *r;
    r = malloc(8*sizeof(char));
   r[0] = 'r';
   r[1] = 'e';
   r[2] = 'v';
   r[3] = 'e';
   r[4] = 'r';
   r[5] = 's';
   r[6] = 'e';
   r[7] = '\0';
    printf("Reverse\n");
    r = reverse(r);
    printf("expected r = esrever\n");
    printf("Result r = %s\n", r);
    return;
}

void swaptest()
{
    int *a;
    int *b;
    a = malloc(1*sizeof(int));
    b = malloc(1*sizeof(int));
    a[0] = 5;
    b[0] = 17;
    swap(a,b);
    printf("Swap\n");
    printf("expected a = 17, b = 5\n");
    printf("Result a = %i, b = %i\n", a[0], b[0]);

}

void palimdrometest()
{
    const char *s;
    int a;
    s = "kayak";
    printf("Palimdrome\n");
    printf("expected s = 0\n");
    a = ispalimdrome(s);
    printf("Result s = %i\n", a);    
}

void mystrlentest()
{
    const char *s = "test de mystrlen";
    int a;
    a = mystrlen(s);
    printf("Mystrlen\n");
    printf("expected s = 16\n");
    printf("Result s = %i\n", a);   
}

void raiseittest()
{
    printf("Raiseit\n");
    printf("expected maj = 3\n");
    char *r;
    int compteur;
    r[0] = 'r';
    r[1] = 'E';
    r[2] = 'v';
    r[3] = 'E';
    r[4] = 'r';
    r[5] = 's';
    r[6] = 'E';
    r[7] = '\0';
    compteur = raiseit(r);
    printf("Result maj = %i\n", compteur);   
    printf("R = %s\n", r);   
    return;
}

void memswaptest()
{
    printf("Memswap\n");
    char *a = "je suis a";
    char *b = "je suis b";
    memswap(a,b);
    printf("expected a = je suis b, b = je suis a\n");
    printf("Result a = %s,  b = %s\n", a, b);   
    return;
}
void printmat(int **r, int lin, int col)
{
    int i = 0;
    int j = 0;
    while (i < lin)
    {
        while(j<col)
        {
            printf("%i ",r[i][j]);
            j++;
        }
        i++;
        printf("\n");
        j=0;
    }
    return;
}
void initmatc(int **r, int n, int v)
{
    int i = 0;
    int j = 0;
    while (i < n)
    {
        while(j<n)
        {
            r[i][j]= v;
            j++;
        }
        i++;
        j=0;
    }
    return;
}

void mattest()
{
    int **a;
    int **b;
    int **r;
    int i =0;
    int j = 0;
    int col = 2;
    int lin = 2;
    a = malloc(2*sizeof(int*));
    b = malloc(2*sizeof(int*));
    r = malloc(2*sizeof(int*));
    while (i < lin)
    {
        a[i] = malloc(2*sizeof(int));
        b[i] = malloc(2*sizeof(int));
        r[i] = malloc(2*sizeof(int));
        i++;
    }
    i = 0;
    while (i < lin)
    {
        while (j < col)
        {
            a[i][j]= i+j;
            b[i][j]= a[i][j]+j;
            j++;
        }
        i++;
        j=0;  
    }
    printf("Matadd\n");
    matadd(a,b,r);
    printmat(r,lin,col);
    printf("Matsub\n");
    matsub(a,b,r);
    printmat(r,lin,col);
    printf("Matmul\n");
    matmul(a,b,r);
    printmat(r,lin,col);
    printf("Matscalmul\n");
    matscalmul(a,5,r);
    printmat(r,lin,col);

return;
}
void matalloctest()
{
    matfree(matalloc(4,3),4);
}
int main(int  argc, char **argv)
{
    swaptest();
    mystrlentest();
    palimdrometest();
    reversetest();
    raiseittest();
    memswaptest();
    mattest();
    matalloctest();
    return(0);
}