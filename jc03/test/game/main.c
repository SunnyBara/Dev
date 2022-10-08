#include "game.h"
#include "data.h"
#include "load.h"
#include <unistd.h>
#include "print.h"
#include <stdlib.h>
int main(int argc, char **argv)
{
    t_cell map[SIZE_X][SIZE_Y];
    load(map);
    system("clear");
    print(map);
    sleep(3);	  
    while (1)
    {
	system("clear");
	game(map);
	print(map);
	sleep(1);	
    }
    return(0);
}
