#include "geo.h"
#include "stdio.h"
int main(int argc, char **argv)
{
    s_point a;
    s_point b;
    a.x = 4;
    a.y = 2;
    b.x = 5;
    b.y = 1;
    printf("distance A-B\n");
    printf("D= %f\n", geo_point_distance(a,b));
    printf("distance A-O\n");
    printf("D= %f\n", geo_point_origin(a));
    printf("conversion en droite\n");
    print_line(geo_point_to_line(a,b));
    printf("point on line ");
    printf("Valeur  = %d", geo_point_on_line(a, geo_point_to_line(a,b)));
return(1);
}