#include "geo.h"

int geo_triangle_is_right(s_triangle t)
{
    s_line l1 = geo_point_to_line(t.p1,t.p2);
    s_line l2 = geo_point_to_line(t.p2,t.p3);
    s_line l3 = geo_point_to_line(t.p1,t.p3);
    if (geo_line_is_ortho(l1,l2)
     || geo_line_is_ortho(l2,l3)
     || geo_line_is_ortho(l1,l3))
    {
        return(0);
    }
    return(1);

}

int geo_triangle_is_equi(s_triangle t)
{
    double d1 = geo_point_distance(t.p2,t.p3);
    if (geo_point_distance(t.p1,t.p2) ==  d1 && geo_point_distance(t.p1,t.p3) == d1)
     {
        return(0);
     }     
    return(1);
}

int geo_triangle_is_iso(s_triangle t)
{
    double d1 = geo_point_distance(t.p1, t.p2);
    double d2 = geo_point_distance(t.p1, t.p3);
    double d3 = geo_point_distance(t.p2, t.p3);
    if ( d1 ==  d2 || d1 == d3 || d2 == d3)
     {
        return(0);
     }     
    return(1);
}

s_line geo_triangle_median(s_triangle t)
{
    return(geo_point_to_line(t.p1,geo_point_middle(t.p2, t.p3)));
}
