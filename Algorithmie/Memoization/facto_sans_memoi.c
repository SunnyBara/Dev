#include <stdio.h>
#include <stdlib.h>

int factoriel(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (factoriel(n - 1) * n);
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    while (i < 500000)
    {
        factoriel(5000);
        i++;
    }
    return 0;
}