int mean(const int tab[], int  size)
{
  char i = 0;
  int  m = 0;
  while (i<size)
  {
      m = m + tab[i];
      i++;
  }
  return(m = m / size);
}
