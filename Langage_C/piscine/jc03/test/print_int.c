#include <unistd.h>
#include <stdio.h>
void traitement(int n)
{
    int j = 0;
    int i = 0;
    int k;
    int puissance = 1;
    int element = 0;
    i = n;
    while (i > 9)
    {
        i = i / 10;
        j++;
        puissance = puissance * 10;
    }
    j++;
    char m[j];
    k = j;
    while (j > 0)
    {
        element = n / puissance;
        m[k - j] = element + 48;
        n = n - (element * puissance);
        puissance = puissance / 10;
        j--;
    }
    write(STDOUT_FILENO, m, 3);
    write(STDOUT_FILENO, "\n", 1);
    return;
}
void print_int(int n)
{
    if (n < 0)
    {
        n = n * -1;
        write(STDOUT_FILENO, "-", 1);
    }
    traitement(n);
    return;
}
