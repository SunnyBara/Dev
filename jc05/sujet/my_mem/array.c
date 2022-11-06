#include "my_mems.h"
#include "stdio.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include  <unistd.h>

int *array_init(size_t size)
{
    printf("init\n");
    int *c;
    if (size < 1)
        {
            return(NULL);
        }
    c = malloc(size*sizeof(int));
    return(c);
}

void array_release(int *array)
{
    printf("release\n");
    if (array != NULL)
    {
     free(array);
    }
    return;
}

void array_print(int *array,  size_t size)
{
    printf("print\n");
    int i =0;
    while  (i < size)
    {
        print_int(array[i]);
        i++;
    }
    return;
}

void array_sort(int *array, size_t size)
{
    printf("sort\n");
    if (array == NULL)
    {
        return;
    }
    int i = 1;
    int j;
    int save = 0;
 
    while (i <size)
    {
         j = i;
        while ( j > 0 && array[j] < array[j-1])
        {
            save = array[j];
            array[j] = array[j-1];
            array[j-1] = save;
            j--;
        }
        i++;
    }  
    array_print(array,10);
    return;
}
int fibo(int n)
{
    if (n == 0)
    {
        return(0);
    }
    else if (n == 1)
    {
        return(1);
    }
    return(fibo(n-1)+fibo(n-2));
}
void array_fibo(int *array, size_t size, size_t n)
{
    int i = 0;
    if  (array == NULL)
    {
        return;
    }
    while (i < size)
    {
        array[i]  = fibo(n);
        i++;
        n++;
    }  
    array_print(array,10);
    return;
}   