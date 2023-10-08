#include  "complexe.h"
struct  s_complex mul_complex(struct s_complex a, struct s_complex b)
{
    struct s_complex mul;
    mul.img  = (a.real  *  b.img + a.img * b.real);
    mul.real = (a.real *  b.real) - (a.img  *  b.img) ;
    return(mul);
}
