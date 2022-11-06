#include "my_str.h"
#include <stdlib.h>

char *my_strupcase(char *str)
{
    int  i  = 0;
    while (str[i] != '\0')
    {
        if (str[i] > 96 && str[i] < 123)
        {
            str[i] = str[i]-32;
        }
        i++;
    }
    return(str);
}

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return(i);
}

char *my_str(char *str)
{
    int  size = my_strlen(str);
    char *myStr;
    myStr = malloc(size*sizeof(char));
    int i = 0;
    while (i < size)
    {
        myStr[i] = str[i];
        i++;
    }
    return(myStr);
}

char *my_strlowcase(char *str)
{
    int  i  = 0;
    while (str[i] != '\0')
    {
        if (str[i] > 64 && str[i] < 91)
        {
            str[i] = str[i]+32;
        }
        i++;
    }
    return(str);
}

int my_strcmp(const char *s1, const char *s2)
{
    int size1 = my_strlen(s1);
    int size2 = my_strlen(s2);
    return(size1-size2); 
}