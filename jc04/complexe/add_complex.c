#include  "complexe.h"
struct  s_complex add_complex(struct s_complex a, struct s_complex b)
{
    struct s_complex somme;
    somme.img  = a.img  + b.img;
    somme.real = a.real + b.real;
    return(somme);
}
