#include "complexe.h"
#include "my_atof.h"
#include "print_complexe.h"
#include "div_complex.h"

int main(int argc, char **argv)
{
    struct s_complex a;
    struct s_complex b;
    a.img = my_atof(argv[2]);
    a.real = my_atof(argv[1]);
    b.real = my_atof(argv[3]);
    b.img = my_atof(argv[4]);
    print_complexe(div_complex(a,b));
    return(0);
}
    
