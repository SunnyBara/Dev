#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k = 0;
    int n = 10;
    int arg1 = 1;
    int arg2 = 0;
    int x = 5 * log2(5);
    int y = 5 * log2(5 / 1);
    int z = 5 * 4 + 5 * log2(5 / 4);
    // while (arg1 - arg2 > 0)
    // {
    //     k += 1;
    //     arg1 = n * log2(n);
    //     arg2 = n * k + n * log2(n / k);
    //     printf("passage x %d\narg1 %d && arg2 %d\n", x, arg1, arg2);
    // }
    printf("x %d y %d z %d\n", x, y, z);
    return 0;
}