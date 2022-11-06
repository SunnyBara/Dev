typedef struct s_point 
{
  double x;
  double y;
} s_point;

typedef struct s_line
{
  double a;
  double b;
} s_line ;

typedef struct s_triangle
{
  s_point p1;
  s_point p2;
  s_point p3;
} s_triangle;

void  print_line(s_line l);
void print_triangle(s_triangle t);
void print_point(s_point p);
double my_sqrt(double x);
double geo_point_distance(s_point p1, s_point p2);
double geo_point_origin(s_point p1);
int geo_point_on_line(s_point p, s_line l);
s_point geo_point_middle(s_point p1, s_point p2);
s_line geo_point_to_line(s_point p1, s_point p2);
int geo_line_parallel(s_line l1, s_line l2);
int geo_line_is_triangle(s_line l1, s_line l2, s_line l3);
s_point geo_line_inter(s_line l1, s_line l2);
int geo_line_is_ortho(s_line l1, s_line l2);
s_triangle geo_line_to_triangle(s_line l1, s_line l2, s_line l3);
int geo_triangle_is_right(s_triangle t);
int geo_triangle_is_equi(s_triangle t);
int geo_triangle_is_iso(s_triangle t);
s_line geo_triangle_median(s_triangle t);
s_line geo_triangle_altitude(s_triangle t);
