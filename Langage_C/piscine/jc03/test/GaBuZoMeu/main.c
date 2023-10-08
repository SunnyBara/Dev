#include "GaBuZoMeu.h"
#include "my_atoi.h"
#include "stdio.h"
int main(int argc,char **argv)
{
    char *test;
    int n = my_atoi(argv[1]);
    return(ga_bu_zo_meu(n));   
}
