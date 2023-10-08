int factoriel(int n)
{
  if (n==1)
    {
      return(1);
    }
  else
    {
      return(factoriel(n-1)*n);
    }
}
int main(int argc, char **argv)
{
 char n=5;
 return(factoriel(n));
}

 
