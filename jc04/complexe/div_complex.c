#include  "complexe.h"
struct  s_complex div_complex(struct s_complex a, struct s_complex b)
{
    struct s_complex div;
    div.real  = ((a.real  * b.real)+ (a.img* b.img)) /(b.real*b.real + b.img *b.img);
    div.img = -(a.real *  b.img) + (a.img  *  b.real);
    return(div);
}
