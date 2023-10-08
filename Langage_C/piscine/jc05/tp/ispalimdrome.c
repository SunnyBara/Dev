#include "jc05.h"
int ispalimdrome(const char *s)
{
    int i;
    int j = 0;
    i = mystrlen(s)-1;
    while (i > j)
    {
        if (s[i] != s[j])
        {
            return(-1);
        }
        i--;
        j++;
    }
    return(0);
}