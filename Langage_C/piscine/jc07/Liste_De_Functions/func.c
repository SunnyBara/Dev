#include "func.h"
#include "stdio.h"
#include "stdlib.h"

s_listf *listf_add(s_listf *l,funcP e)
{
    s_listf *tmp;
    tmp = malloc(sizeof(s_listf));
    tmp->func = e;
    tmp->next = l;
    return(tmp);
}

void listf_print(s_listf *l)
{
    s_listf *tmp;
    tmp = l;
    while( tmp != NULL && tmp->next != NULL)
    {
        printf("%p", tmp->func);
        tmp =  tmp->next;
        printf(" ");
    }
    if (tmp  != NULL)
    {
        printf("%p", tmp->func);
        printf("\n");
    }
    return;
}

s_listf *listf_find(s_listf *l, funcP e)
{
    s_listf *tmp;
    tmp = l;
    while (tmp != NULL && tmp->func != e)
    {
        tmp = tmp->next;
    }
    return(tmp);
}

s_listf* listf_remove(s_listf *l, funcP e)
{
    s_listf *tmp;
    s_listf *save;
    tmp = l;
    if (tmp->func == e)
    {
        save = tmp;
        tmp = tmp->next;
        free(save);
        return(tmp);
    }
    while (tmp != NULL &&  tmp->next != NULL && tmp->next->func != e)
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

s_listf *listf_sorted_add(s_listf *l, funcP e)
{
    s_listf *tmp;
    s_listf *save;
    if (l == NULL)
    {
        return(listf_add(l, e));
    }
    tmp  = l;
    while (tmp != NULL && tmp->func < e)
    {
        save = tmp;
        tmp = tmp->next;
    }
    save->next = listf_add(tmp,e);
    return(l);
}

void apply(s_list *l, s_listf *lf)
{
    s_list *tmp;
    s_listf *tmpf;
    tmp = l;
    while (tmp != NULL)
    {
        tmpf = lf;
        while (tmpf != NULL)
        {
            tmp->data = tmpf->func(tmp->data);
            tmpf = tmpf->next;
        }
        tmp = tmp->next;
    }
    return;
}