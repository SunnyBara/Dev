#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    s_adja *adja;
    adja = create_adja(6);
    adja->mat[5][5] = 3;
    add_link(adja, 2, 7, 6);
    add_link(adja, 2, 5, 4);
    add_link(adja, 2, 5, 6);
    printf("cost 2 - 5 = %i\n", adja->mat[2][5]);
    del_link(adja, 2, 7);
    del_link(adja, 2, 4);
    printf("cost 2 - 5 = %i\n", adja->mat[2][5]);
    print_adja(adja);
    return (0);
}