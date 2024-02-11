#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 1;
    int arg1 = 0;
    int arg2 = 1;
    while (arg1 < arg2)
    {
        x += 1;
        arg1 = x * x * 8;
        arg2 = 64 * x * log2(x);
        printf("passage x %d\narg1 %d && arg2 %d\n", x, arg1, arg2);
    }
    return 0;
}