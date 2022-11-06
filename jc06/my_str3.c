#include "my_str.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long int my_strtoul(const char *nptr, const char **endptr, int base)
{
    int i = 0;
    int inte = 0;
    int signe = 1;
    if (nptr[i] == '-')
    {
        signe = -1;
        i++;
    }
    while (nptr[i] > 47 && nptr[i] < 58)
    {
        inte = inte * base + (nptr[i] - 48);
        i++;
    }
    *endptr = nptr + i;
    return (inte * signe);
}

void remplissage(char *c, char *string, int fill, int i)
{
    int remp =0;
    while (fill < (i))
    {
        c[remp] = string[fill];
        fill++;
        remp++;
    }
    return;
}

char **my_strarray(char *string, char *delimiter)
{
    char **c;
    int i = 0;
    int size = my_strlen(delimiter);
    int sizeofstring = my_strlen(string);
    int j = 0;
    int k = 0;
    int l = 0;
    int fill = 0;
    c = malloc(((sizeofstring) * sizeof(char *)));
    while (string[i] != '\0')
    {
        if (string[i] == delimiter[0])
        {
            j = 0;
            l = i;
            while (delimiter[j] != '\0')
            {
                if (string[i] != delimiter[j])
                {
                    break;
                }
                j++;
                i++;
            }
            c[k] = malloc((l-fill)*sizeof(char));
            remplissage(c[k],string,fill,l);
            fill = i;
            k++;
        }
        i++;
    }
    c[k] = malloc((i-fill)*sizeof(char));
    remplissage(c[k],string,fill,i);
    return (c);
}

const  char *my_strstr(const char *big, const  char *little)
{
    int i =0;
    int j =0;
    while (big[i] != '\0')
    {
        if (big[i] == little[0])
        {
            j = 0;
            while (little[j] != '\0')
            {
                if (big[i] != little[j])
                {
                    break;
                }
                j++;
                i++;
            }
            if (little[j] == '\0')
            {
                 return(big +i-j); 
            }
        }
        i++;
    }
    char *c ="pas d'occurence";
    return(c);
}

char *my_strcat(char *s, const char *append)
{
    int sizesrc = my_strlen(append);
    int sizedest = my_strlen(s);
    s=realloc(s,sizesrc+sizedest);
    int i = 0;
    while (i < sizesrc)
    {
        s[i+sizedest]=append[i];
        i++;
    }
    return(s);
}