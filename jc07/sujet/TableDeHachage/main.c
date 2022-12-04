#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char **argv)
{
    s_hash *l;
    f_hash funch;
    f_display display;
    f_cmp cmp;
    cmp = &my_cmp;
    char *data = "toto";
    char *data1 = "ata";
    char *data2 = "to";
    char *data3 = "ata";
    const void *constdata = data;
    const void *constdata1 = data1;
    const void *constdata2 = data2;
    const void *constdata3 = data3;
    funch = &my_hashfunc;
    display = &my_display;
    l = hash_new(3, funch);
    hash_print_key(l, constdata);
    hash_insert(l, data);
    hash_insert(l, data1);
    hash_insert(l, data2);
    hash_insert(l, data3);
    hash_dump(l, display);
    printf("occurence %i\n", hash_count(l,"to",cmp));
    return (0);
}