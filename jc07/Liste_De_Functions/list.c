#include <stdio.h>
#include <stdlib.h>
#include "list.h"

s_list *list_add(s_list *l,int e)
{
    s_list *tmp;
    tmp = malloc(sizeof(s_list));
    tmp->data = e;
    tmp->next = l;
    return(tmp);
}

void list_print(s_list *l)
{
    s_list *tmp;
    tmp = l;
    while( tmp != NULL && tmp->next != NULL)
    {
        printf("%i", tmp->data);
        tmp =  tmp->next;
        printf(" ");
    }
    if (tmp  != NULL)
    {
        printf("%i", tmp->data);
        printf("\n");
    }
    return;
}

s_list *list_find(s_list *l, int e)
{
    s_list *tmp;
    tmp = l;
    while (tmp != NULL && tmp->data != e)
    {
        tmp = tmp->next;
    }
    return(tmp);
}

s_list* list_remove(s_list *l, int e)
{
    s_list *tmp;
    s_list *save;
    tmp = l;
    if (tmp->data == e)
    {
        save = tmp;
        tmp = tmp->next;
        free(save);
        return(tmp);
    }
    while (tmp != NULL &&  tmp->next != NULL && tmp->next->data != e)
    {
        tmp = tmp->next;
    }
    if  (!(tmp == NULL || tmp->next == NULL))
    {
        save = tmp->next;
        tmp->next = tmp->next->next;
        free(save);
    }
    return(l);
}

s_list *list_sorted_add(s_list *l, int e)
{
    s_list *tmp;
    s_list *save;
    if (l == NULL)
    {
        return(list_add(l, e));
    }
    tmp  = l;
    while (tmp != NULL && tmp->data < e)
    {
        save = tmp;
        tmp = tmp->next;
    }
    save->next = list_add(tmp,e);
    return(l);
}