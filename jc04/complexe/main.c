#include "print_complexe.h"
#include "complexe.h"
#include "stdio.h"
#include "my_atof.h"
int main(int argc, char **argv)
{
    
    struct s_complex z;
    z.img = my_atof(argv[2]);
    z.real = my_atof(argv[1]);
    print_complexe(z);
    return 0;
}
