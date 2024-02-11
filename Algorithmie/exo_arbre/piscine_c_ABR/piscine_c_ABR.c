#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *str)
{
    char size = 1;
    int p = 1;
    while (str[size] != '\0')
    {
        size += 1;
        p *= 10;
    }
    int i = 0;
    int n = 0;
    while (i < size)
    {
        n += (str[i] - '0') * p;
        i += 1;
        p /= 10;
    }
    return (n);
}

int isabr(char *abr)
{
    char i = 0;
    char j = 0;
    char *str;
    char save;
    char cpt = 1;
    char k = 0;
    while (abr[i] != '\0')
    {
        if (abr[i] == ' ')
        {
            cpt += 1;
        }
        i += 1;
    }
    printf("size = %d\n", cpt);
    int *treeint = malloc(cpt * sizeof(int));
    i = 0;
    while (abr[i] != '\0')
    {
        save = i;
        j = 0;
        while (abr[i] != ' ' && i != -1)
        {
            if (abr[i] != 'x' || abr[i] <= '0' && abr[i] >= '9' || abr[i] != '\0')
            {
                i = -2;
            }
            i += 1;
        }
        if (i == -1)
        {
            printf("2\n");
            return 2;
        }
        else if (abr[save] == 'x')
        {
            treeint[k] = -1;
            k += 1;
        }
        else
        {
            str = malloc((i - save + 1) * sizeof(char));
            while (save < i)
            {
                str[j] = abr[save];
                j += 1;
                save += 1;
            }
            str[j] = '\0';
            int n = my_atoi(str);
            treeint[k] = n;
            k += 1;
        }
        i += 1;
    }
    return (0);
}

int main(void)
{
    char *str = "14 34 2 x x x ";
    isabr(str);
}