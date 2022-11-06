#include "geo.h"

int geo_line_parallel(s_line l1, s_line l2)
{
    if (l1.a*l1.a == l2.a*l2.a)
    {
        return(0);
    }
    return(1);
}

int geo_line_is_triangle(s_line l1, s_line l2, s_line l3)
{
    return(!(geo_line_parallel(l1,l2) && geo_line_parallel(l2,l3) && geo_line_parallel(l3,l1)));
    
}

s_point geo_line_inter(s_line l1, s_line l2)
{
    s_point inter;
    inter.x = (l1.b-l2.b)/(l1.a-l2.a);
    inter.y = l1.a*inter.x + l1.b;    
    return(inter);
}

int geo_line_is_ortho(s_line l1,  s_line l2)
{
    if (l1.a*l2.a + l1.b*l2.b == 0)
    {
        return(0);
    }
    return(1);
}

s_triangle geo_line_to_triangle(s_line l1, s_line l2, s_line l3)
{
    s_triangle triangle;
    triangle.p1 = geo_line_inter(l1,l2);
    triangle.p2 = geo_line_inter(l2,l3);
    triangle.p3 = geo_line_inter(l1,l3);
    return(triangle);
}
