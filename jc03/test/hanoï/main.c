#include "hanoï.h"
#include "my_atoi.h"
int main(int argc, char **argv)
{
    int n = my_atoi(argv[1]);
    if (n < 1)
    {
	return(1);
    }
    hanoi(n);
    return(0);
}
