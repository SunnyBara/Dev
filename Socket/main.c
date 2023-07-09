#include "stdio.h"
#include <stdlib.h>
#include <string.h>
typedef struct test
{
    char *a;
    char *b;
    char *c;
    int x;
} s_test;

char *mystrtok(char *stringtocut, char *breakpoint)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char confirm = 'N';
    while (stringtocut[j] != '\0')
    {

        if (stringtocut[j] == breakpoint[0])
        {
            i = j;
            k = 0;
            while (stringtocut[j] != '\0' && breakpoint[k] != '\0' && stringtocut[j] == breakpoint[k])
            {
                j++;
                k++;
            }
            if (breakpoint[k] == '\0' && stringtocut[j] == '\0')
            {
                confirm = 'Y';
                break;
            }
        }
        j++;
    }
    if (confirm == 'Y')
    {
        char *stringcut;
        k = 0;
        while (k < i)
        {
            stringcut[k] = stringtocut[k];
            k++;
        }
        stringcut[i] = '\0';
        printf("stringcut = '%s'\n ", stringcut);
        return (stringcut);
    }
    return (stringtocut);
}

/*int fill(char *stringtofill, int size, char *filler, int starter)
{
    int i = 0;
    while (i < size)
    {
        stringtofill[i] = filler[starter + i];
        i++;
    }
    return (starter + i);
}*/
int fillint(char *strtofill, int inttosend, int starter)
{
    int i = 1;
    int puissance = 1;
    if (inttosend < 0)
    {
        inttosend = inttosend * -1;
        strtofill[starter] = '-';
    }
    else
    {
        strtofill[starter] = '+';
    }

    int save = inttosend;

    if (inttosend < 10)
    {
        strtofill[starter + i] = '0';
        i++;
    }
    else
    {
        while (inttosend > 10)
        {
            inttosend = inttosend / 10;
            puissance = puissance * 10;
        }
        printf("puissance = %d \n", puissance);
        inttosend = save;
    }
    while (puissance >= 1)
    {
        save = inttosend;
        inttosend = inttosend / puissance;
        printf("inttosend dans strtofill %d\n", inttosend);
        strtofill[starter + i] = inttosend + 48;
        inttosend = save - inttosend * puissance;
        puissance = puissance / 10;
        i++;
    }
    printf("strtofill %s\n", strtofill);
    return (starter + i);
}

int main(int argc, char **argv)
{
    /*s_test *strin;
    strin = malloc(sizeof(s_test));
    strin->a = malloc(sizeof(char));
    strin->b = malloc(sizeof(char));
    strin->c = malloc(sizeof(char));
    int sizea = 2;
    int sizeb = 2;
    int sizec = 1;

    char *text = "abbcd345";

    int i = 0;
    i = fill(strin->a, sizea, text, i);
    i = fill(strin->b, sizeb, text, i);
    i = fill(strin->c, sizec, text, i);
    printf("strin->a = %s\n", strin->a);
    printf("strin->b = %s\n", strin->b);
    printf("strin->c = %s\n", strin->c);
    char *stoi;
    stoi = malloc(sizeof(char));
    i = fill(stoi, 4, text, i);
    strin->x = atoi(stoi);
    printf("stoi %d\n",  strin->x );*/
    int b;
    int a;
    b = rand() % 10 ;
    a = rand() % 10 - 455;
    printf("a = %d , b = %d\n", a, b);
    char *strtofill;
    int starter = 0;
    strtofill = malloc(sizeof(char));
    starter = fillint(strtofill, a, starter);
    starter = fillint(strtofill, b, starter);

    printf("%s\n", strtofill);
    return (0);
}