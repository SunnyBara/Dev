#include "complexe.h"
#include "stdio.h"

void print_complexe(struct s_complex z)
{
    double l = z.real; 
    double b = z.img;
    printf("z = ");
    if (l > 0)
    {
	printf("%g",l);
    }
    else  if ( l < 0)
    {
	printf("%g",l);
    }
    if (b < 0)
    {
	printf( " %gi",b);
    }
    else if (b > 0)
    {
	printf( " +%gi",b);
    }
    if  (l == b && l == 0)
    {
	printf("0");
    }
    printf("\n");
    return;
}
