#include "mean.h"
int main(int argc, char **argv)
{
  int tab[4];
  tab[0] = 256;
  tab[1] = 258;
  tab[2] = 257;
  tab[3] = 260;
  int size = 4;
  return(mean(tab,size));
}
