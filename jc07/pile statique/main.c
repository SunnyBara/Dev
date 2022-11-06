#include "pile.h"
#include <stdio.h>

void stack_pushtest(s_stack *st)
{
    int i = 0;
    printf("empilement\n");
    while (i < 5)
    {
        stack_push(st,i);
        i++;
    }
    stack_print(st);
}

void stack_poptest(s_stack *st)
{
    printf("premiere suppression:  element  %i\n", stack_pop(st));
    printf("seconde suppression:  element  %i\n", stack_pop(st));
    stack_print(st);
}
void stack_toptest(s_stack *st)
{
    printf("top de la pile %i\n", stack_top(st));
    return;
}

int main(int argc, char **argv)
{
   /* s_stack *st;
    st = stack_init();
    printf(" CR empty %i\n", stack_is_empty(st));
    stack_print(st);
    stack_pushtest(st);
    stack_poptest(st);
    stack_toptest(st);
    stack_destroy(st);
    stack_print(st);
   */
   return(0);

}