#include "jc05.h"
int raiseit(char *s)
{
    int maj = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] > 96  && s[i] <  123)
        {
            s[i] = s[i] - 32;
        }
        else if (s[i] > 64  && s[i] < 91)
        {
            maj++;
        }
        i++;
    }
    return(maj);
}
