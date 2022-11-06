#include <stdio.h>
#include <stdlib.h>
#include "list.h"

s_list *list_addtest(s_list *l)
{
    s_list *tmp;
    int i = 0;
    tmp = l;
    while (i < 5)
    {   
        tmp=list_add(tmp, 5-i);
        i++;
    }
    list_print(tmp);
    return(tmp);
}

int  main(int argc, char **argv)
{
    s_list *l;
    l = list_addtest(l);
    printf(" l.data =%i\n", list_find(l,2)->data);
    l = list_remove(l,2);
    list_print(l);
    l = list_sorted_add(l,6);
    list_print(l);
    return(0);
}