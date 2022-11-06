#include  "complexe.h"
struct s_complex sub_complex( struct s_complex a, struct s_complex b)
{
    struct s_complex sous;
    sous.img  = a.img  - b.img;
    sous.real = a.real - b.real;
    return(sous);
}
