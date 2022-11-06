#include "complexe.h"

struct s_complex neg_complexe(struct s_complex a)
{
    struct s_complex z;
    z.img  = -1*a.img;
    z.real = -1*a.real;
    return(z);
}
