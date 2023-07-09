#include <stdio.h>
#include <stdlib.h>

int itemain(int argc, char **argv)
{
    int n = 14;
    int i = 1;
    int a = 0;
    int b = 1;
    int c;
    while (i < n)
    {
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    printf("f(%i) = %d\n", n, c);
    return (0);
}

int fiborecur(int n)
{
    if(n==0)
    {
        return(0);
    }
    else if( n==1)
    {
        return(1);
    }
    else
    {
        return(fiborecur(n-2) + fiborecur(n-1));
    }

}

int main(int argc, char **argv)
{
    char id;
    id = '1';
    printf("id %c\n",id);
    printf("id + 1 %c\n",id+1);
    return(0);
}