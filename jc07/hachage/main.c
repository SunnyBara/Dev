#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char **argv)
{
    int i = 0;
    int cpt = 0 ;
    s_hash *f;
    char *str;
    f = hash_new(5);
    while (i < 7 )
    {
        str = malloc(sizeof(char));
        f = hash_insert(f,my_itoa(i, str, 10));
        i++;
    }
    hash_dump(f);
    return(0);
}