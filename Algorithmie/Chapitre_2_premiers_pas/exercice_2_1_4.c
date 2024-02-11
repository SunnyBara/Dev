// formellement:
//  soit A et B deux nombres en base 2 de taille n ;
//  on veut creer C tel que C = A + B et C est de taille N+1;
//  Ex n = 1;
//  A = 1 B= 1 soit 1+1 en base 2 = 10 donc C = A + B = 1 + 1 = 10 size C = Size(A ou B) + 1 = 2;
// Pour n  si A = 1.....0 et B = 1....0 alors C  = A + B = 10.....0 donc sizeC = sizeA + 1 ;
//  on garde en tête que size A = size B = n sachant que size A = n implique que A= 1....X; avec n-2 caractères entre 1 et X.
//  il en va de même  pour B

// Vesrion algorithmique;
#include <stdio.h>
#include <stdlib.h>

char *additionBinaire(char *A, char *B, int n)
{
    char *C = malloc((n + 1) * sizeof(char));
    int i = 0;
    C[0] = '1';
    while (i < n - 1)
    {
        if (A[i] == B[i])
        {
            C[i + 1] = '0';
        }
        else
        {
            C[i + 1] = '1';
        }
        i += 1;
    }
    C[i + 1] = '\0';
    return C;
}

int main()
{
    char A[6] = "10011";
    char B[6] = "11101";
    char *C = additionBinaire(A, B, 6);
    printf("%s\n", C);
}
