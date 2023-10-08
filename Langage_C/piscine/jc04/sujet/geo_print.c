#include "geo.h"
#include "stdio.h"

void print_point(s_point p)
{
    printf("A = %f, B = %f\n",p.x,p.y);
    return;
}

void  print_line(s_line l)
{
   printf("Direction = %f, Ordonnée = %f\n",l.a,l.b);
    return;
}

void print_triangle(s_triangle t)
{
   printf(" Point 1: A = %f, B = %f\n",t.p1.x,t.p1.y);
   printf(" Point 2: A = %f, B = %f\n",t.p2.x,t.p2.y);
   printf(" Point 3: A = %f, B = %f\n",t.p3.x,t.p3.y);
    return;
}