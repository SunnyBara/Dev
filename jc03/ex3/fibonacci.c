int fibonacci(int n)
{
  if (n == 0)
    {
    return(0);
    }
  else if (n == 1)
    {
      return(1);
    }
  else
    {
      return(fibonacci(n-2)+fibonacci(n-1));
    }
}
int main(int argc, int **argv)
{
 char n=10;
  return(fibonacci(n));
}
