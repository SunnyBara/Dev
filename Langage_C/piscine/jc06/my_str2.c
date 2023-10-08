#include "my_str.h"
#include <stdio.h>

int my_strncmp(const char *s1, const char *s2, unsigned int n)
{
    int i = 0;
    int compare;
    int size1 = my_strlen(s1);
    int size2 = my_strlen(s2);
    if (n > size1 || n > size2)
    {
        return (1);
    }
    while (i < n)
    {
        compare = compare + (s1[i] - s2[i]);
        i++;
    }
    return (compare);
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    int size = my_strlen(src);
    while (i < size)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

char *my_strncpy(char *dest, const char *src, unsigned int n)
{
    int i = 0;
    int size = my_strlen(src);
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

int my_atoi(const char *ptr)
{
    int i = 0;
    int signe = 1;
    int inte = 0;
    while (ptr[i] == ' ')
    {
        i++;
    }
    if (ptr[i] == '-')
    {
        signe = -1;
        i++;
    }
    while (ptr[i] != '\0')
    {
        if (ptr[i] < 48 || ptr[i] > 57)
        {
            return (0);
        }
        inte = inte * 10 + (ptr[i] - 48);
        i++;
    }
    return (inte * signe);
}

int my_atoi_base(const char *str, const char *base)
{
    int size = my_strlen(base);
    int i = 0;
    int j = 0;
    int inte = 0;
    int signe = 1;
    if (str[i] == '-')
    {
        signe = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        while (str[i] != base[j])
        {
            j++;
        }
        inte = inte*size + j;
        i ++;
        j = 0;
    }
    return(inte*signe);
}
