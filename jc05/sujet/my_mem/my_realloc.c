#include "my_mems.h"
#include "stdio.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include  <unistd.h>
/*
void *my_realloc(void *ptr, size_t new_size, size_t old_size)
{
    int taille;
    int i = 0;
    char *s = (char*)ptr;
    char *tab;
    tab = malloc(new_size*sizeof(char));
    if (old_size > new_size)
    {
        taille = new_size;
    }
    else
    {
        taille = old_size;
    }
    while (i < taille)
    {
        tab[i] = s[i];
        i++;
    }
    free(ptr);
    return(tab);
}

char *my_memset(char *s, int c, size_t n)
{
    int i = 0;
        while  (i < n)
        {
            s[i] = c;
            i++;
        }
    return(s);
}

void *my_memcpy(void *dest, const void *src, size_t n)
{   
    printf("my_memcpy\n");
    int i = 0;
    char *s = (char*)dest;
    const char *mysrc =(const char*)src;
    while (i<n)
    {
        s[i] = mysrc[i];
        printf("mysrc[i]%i\n", mysrc[i]);
        i++;
    }
    dest = (void*)s;
   return(dest); 
}

void *my_memov(void *dest, const void *src, size_t n)
{
    printf("my_memov\n");
    int i = 0;
    char *s = (char*)dest;
    char *tab;
    tab = malloc(n*sizeof(char));
    const char *mysrc =(const char*)src;
    while (i < n)
    {
        tab[i] = mysrc[i];
        printf("mysrc[i]%i\n", mysrc[i]);
        printf("tab[i]%i\n", tab[i]);
        i++;
    }
    i =0;
    while (i<n)
    {
        s[i] = tab[i];
        i++;
    }
    free(tab);
    dest = (void*)s;
    return(dest);
}*/
void memdump(const void  *addr, size_t len)
{
    int cpt = 0;
    int i = 0;
    int j = 0;
    int k =0;
    int top;
    unsigned char *tab;
    unsigned char writ[1];
    tab = (unsigned char*) addr; 
    while (j < len/16)
    {

        i = k;
        top = k + 16;
          while (i < top)
        {     
          write(STDOUT_FILENO,hexa(tab[i]),2);
          write(STDOUT_FILENO," ",1);
          i++;
        }
        write(STDOUT_FILENO," ",1);
        i = k;
        while (i<top)
        {
            if (cpt == 0)
            {
                write(STDOUT_FILENO,"|",1);
            }        
            if  (!isprint(tab[i]))
            {
                write(STDOUT_FILENO,".",1);
            }
            else 
            {
                writ[0] = tab[i];
                write(STDOUT_FILENO,writ,1);
            }
            i++;
            cpt++;
            k++;
            if (cpt == 16)
            {
                write(STDOUT_FILENO,"|\n",2);
                cpt = 0;
            }
        }
        j++;
    }
    return;
}
