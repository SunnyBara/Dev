#include "fifo.h"
#include <stdlib.h>
#include <stdio.h>

int  main(int argc, char **argv)
{
    s_fifo *l;
    l = init_fifo();
    printf("is empty = %i\n", is_empty(l));
    printf("size = %i\n", size(l));
    push(l,5);
    print(l);
    push(l,7);
    print(l);
    push(l,22);
    print(l);
    pop(l);
    print(l);
    push(l,45);
    print(l);
    printf( "head = %i\n", head(l));
    destroy(l);
    print(l);
    return(0);
}