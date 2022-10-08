#include "my_strlen.h"

int my_strlen(const char str[])
{
    int i = 0;
    while ( str[i] != '\0')
    {
	i ++;
    }
    return(i);
}    
