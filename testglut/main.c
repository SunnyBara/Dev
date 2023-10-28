#include "data.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct charlist
{
    char **list;
    struct charlist *next;
} s_charlist;

char *movetab(char *tab)
{
    tab[0] = 'b';
    char *tabtest;
    tabtest = malloc(sizeof(char));
    tabtest[0] = tab[0];
    tab[0] = 'a';
    return (tabtest);
}

int main(int argc, char **argv)
{
    return (0);
}