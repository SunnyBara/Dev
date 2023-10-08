#include "fifo.h"
#include <stdlib.h>
#include <stdio.h>

s_fifo *init_fifo(void)
{
    s_fifo *l;
    l = malloc(sizeof(s_fifo));
    return(l);
}

int is_empty(s_fifo *fifo)
{
 return(!(fifo->head == NULL && fifo->tail == NULL));
}

int size(s_fifo *fifo)
{
    return(fifo->size);
}

void push(s_fifo *fifo, int element)
{
    s_list *s;
    s = malloc(sizeof(s_list));
    s->elt = element;
    if (fifo->head == NULL && fifo->tail == NULL)
    {
        fifo->head = s;
    }
    else 
    {
        fifo->tail->next = s;
    }
    fifo->tail = s;
    return;
}

void pop(s_fifo *fifo)
{
    if (fifo->head == NULL  && fifo->tail == NULL)
    {
        return;
    }
    fifo->head = fifo->head->next;
    return;
}

void  print(s_fifo *fifo)
{
    if (fifo->head == NULL && fifo->tail == NULL)
    {
        printf("pile vide");
    }
    s_list *tmp;
    tmp = fifo->head;
    while (tmp != NULL )
    {
        printf("%i", tmp->elt);
        tmp = tmp->next;
        if (tmp != NULL)
        {
            printf("<->");
        }
    }
    printf("\n");
    return;
}

int head(s_fifo *fifo)
{
    if (fifo->head == NULL && fifo->tail == NULL)
    {
        printf("pas de tete");
        return(1);
    }   
    return(fifo->head->elt);
}

void recurseclear(s_list *tmp)
{
    if (tmp == NULL)
    {
        return;
    }
    recurseclear(tmp->next);
    free(tmp);
    return;
}
void  clear(s_fifo *fifo)
{
    recurseclear(fifo->head);
    return;
}

void destroy(s_fifo *fifo)
{
    clear(fifo);
    free(fifo);
    return;
}

