#include "sapin.h"
#include "my_atoi.h"
int main(int argc, char **argv)
{
    int n=my_atoi(argv[1]);
    return(sapin(n));
}
