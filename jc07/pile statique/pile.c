#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

s_stack *stack_init()
{
    s_stack *c;
    c = (malloc(1*sizeof(s_stack)));
    c->size = 0;
    return(c);
}

int stack_is_empty(s_stack  *st)
{
    if (st->size == 0)
    {
        return(0);
    }
    return(1);
}

int stack_size(s_stack *st)
{
    return(st->size);
}

void stack_print(s_stack *st)
{
    int i = 1;
    while (i <= st->size)
    {
        printf("elements = %i\n", st->elt[st->size - i]);
        i++;
    }
    return;  
}

int stack_push(s_stack *st, int e)
{
    st->elt[st->size] =  e;
    st->size = st->size + 1;
    return(1);
}

int stack_pop(s_stack *st)
{
    st->size = st->size - 1;
    return(st->elt[st->size]);
}

int stack_top(s_stack *st)
{
    return(st->elt[st->size-1]);
}

void stack_destroy(s_stack *st)
{
    free(st);
    return;
}