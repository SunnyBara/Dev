typedef enum   types 
{
    E_int = 0,
    E_float,
    E_double
}e_types;

typedef union  value
{
    int     I;
    double  D;
    float   F;
}u_value;

typedef struct  super_type
{
    u_value val;
    e_types type;
}s_super_type;


s_super_type init_int(int val);
s_super_type init_float(float val);
s_super_type init_double(double val);

int    get_int(s_super_type val);
float  get_float(s_super_type val);
double get_double(s_super_type val);
void   print_super(s_super_type super);
