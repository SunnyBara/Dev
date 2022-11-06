#include "enum.h"
#include "stdio.h"

s_super_type init_int(int val)
{
    s_super_type a;
    a.val.I  = val;
    a.type = E_int;
    return(a);
}

s_super_type init_float(float val)
{
    s_super_type a;
    a.val.F = val;
    a.type = E_float;
    return(a);
}

s_super_type init_double(double val)
{
    s_super_type a;
    a.val.D  = val;
    a.type = E_double;
    return(a);
}

int get_int(s_super_type val)
{
    if (val.type == E_int)
    {
        return(val.val.I);
    }
    return(1);
}

float get_float(s_super_type val)
{
    if (val.type == E_float)
    {
        return(val.val.F);
    }
    return(1);
}

double get_double(s_super_type val)
{
    if (val.type == E_double)
    {
        return(val.val.D);
    }
    return(1);
}

void print_super(s_super_type super)
{
    if (super.type == E_int)
    {
        printf("Int , %i\n", super.val.I);
    }
    else if (super.type == E_float)
    {
        printf("float , %f\n", super.val.F);
    }
    else if (super.type == E_double)
    {
        printf("double, %f\n", super.val.D);
    }
    return;
}

int main(int argc, char **argv)
{
    print_super(init_int(5));
    print_super(init_double(8.54));
    print_super(init_float(5.4f));
    return(0);
}