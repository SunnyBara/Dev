#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    s_dlist *list;
    s_dlist *list2;
    list2 = malloc(sizeof(s_dlist));
    list = malloc(sizeof(s_dlist));
    f_free ffree;
    f_cmp fcmp;
    f_copy fcopy;
    ffree = &myf_free;
    fcopy = &my_fcopychar;
    fcmp = &my_cmpchar;
    dlist_init(list, ffree, fcopy, fcmp);
    dlist_add_head(list, "0");
    dlist_add_queue(list, "5");
    dlist_add(list, "1");
    dlist_add(list, "2");
    dlist_add(list, "4");
    dlist_add(list, "3");
    printf("NoSHIFT\n");
    dlist_show_string(list);
    dlist_shift(list, 3);
    printf("SHIFT +3\n");
    dlist_show_string(list);
    dlist_shift(list, -3);
    printf("SHIFT -3\n");
    dlist_show_string(list);
    dlist_shift(list, -1);
    printf("SHIFT -1\n");
    dlist_show_string(list);
    return (0);
}