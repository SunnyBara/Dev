#include "geo.h"

double geo_point_distance (s_point p1, s_point p2)
{
    double d;
    d = my_sqrt((p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.x)*(p2.x - p1.x));
    return(d);
}

double geo_point_origin (s_point p1)
{
    double d;
    d = my_sqrt((p1.y)*(p1.y) + (p1.x)*(p1.x));
    return(d);
}

int geo_point_on_line (s_point p, s_line l)
{
    if (p.y == l.a*p.x + l.b)
    {
        return(0);
    }
    return(1);
}

s_point geo_point_middle (s_point p1, s_point p2)
{
    s_point d;
    d.x = (p2.x + p1.x)/2;
    d.y = (p2.y + p1.y)/2;
    return(d);
}

s_line geo_point_to_line(s_point p1, s_point p2)
{
    s_line d;
    d.a = (p2.y-p1.y)/(p2.x - p1.x);
    d.b = (p2.y - d.a*p2.x);
    return(d);
}