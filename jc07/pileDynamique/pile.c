#include "pile.h"
#include <stdlib.h>
#include <stdio.h>
s_stack *stack_first(s_stack *st)
{
    s_stack *tmp;
    tmp = st;
    while (tmp->next !=  NULL)
    {
        tmp = tmp->next;
    }
    return(tmp);
}

s_stack *stack_init(int elt)
{
    s_stack *c;
    c = (malloc(1*sizeof(s_stack)));
    c->elt = elt;
    return(c);
}

int stack_is_empty(s_stack  *st)
{
    if (st == NULL)
    {
        return(0);
    }
    return(1);
}

int stack_size(s_stack *st)
{
    int i = 0;
    s_stack *tmp = st;
    while (tmp->next !=  NULL)
    {
        tmp = tmp->next;
        i++;
    }
    return(i);
}

void  recurseprint(s_stack *tmp)
{
    if (tmp == NULL)
    {
        return;
    }
    recurseprint(tmp->next);
    printf("elements = %i\n", tmp->elt);
  
    return;
}

void stack_print(s_stack *st)

{
    s_stack *tmp = st;
    recurseprint(tmp);
    return;  
}

s_stack *stack_push(s_stack *st, int elt)
{
    s_stack *tmp;
    tmp = st;
    while (tmp->next !=  NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = stack_init(elt);
    return(tmp->next);
}

s_stack *stack_pop(s_stack *st)
{   
    s_stack *tmp;
    s_stack *save;
    tmp = st;
    while (tmp->next->next !=  NULL)
    {
        tmp = tmp->next;
    }
    save = tmp->next;
    tmp->next = NULL;
    return(save);
}

int stack_top(s_stack *st)
{
    s_stack *tmp;
    tmp = st;
    while (tmp->next !=  NULL)
    {
        tmp = tmp->next;
    }
    return(tmp->elt);
}

void recursedestroy(s_stack *st)
{
    if (st ==  NULL)
    {
        return;
    }
    recursedestroy(st->next);
    free(st);
    return;
}
void stack_destroy(s_stack *st)
{
    recursedestroy(st);
    return;
}