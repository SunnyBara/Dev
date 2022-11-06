#include "print_complexe.h"
#include "complexe.h"
#include "stdio.h"
#include "my_atof.h"
#include "add_complex.h"
int main(int argc, char **argv)
{
    
    struct s_complex z;
    z.img = my_atof(argv[2]);
    z.real = my_atof(argv[1]);
    struct s_complex b;
    b.img = my_atof(argv[4]);
    b.real = my_atof(argv[3]);
    print_complexe(add_complex(z,b));
    return 0;
}
