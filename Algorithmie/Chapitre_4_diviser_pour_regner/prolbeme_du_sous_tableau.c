
#include <stdio.h>
#include <stdlib.h>

int *Trouver_sous_tableau_milieu(int *A, int bas, int mil, int haut)
{
    int somme_gauche = 0;
    int somme = 0;
    int i = mil;
    int max_gauche = mil;
    while (i >= bas)
    {
        somme = somme + A[i];
        if (somme > somme_gauche)
        {
            somme_gauche = somme;
            max_gauche = i;
        }
        i -= 1;
    }

    int somme_droite = 0;
    somme = 0;
    i = mil + 1;
    int max_droite = mil + 1;
    while (i <= haut)
    {
        somme = somme + A[i];
        if (somme > somme_droite)
        {
            somme_droite = somme;
            max_droite = i;
        }
        i += 1;
    }

    int *respons = malloc(3 * sizeof(int));
    respons[0] = max_gauche;
    respons[1] = max_droite;
    respons[2] = somme_gauche + somme_droite;
    return respons;
}

int *Trouver_soustableau_maximum(int *A, int bas, int haut)
{
    int mil;
    int *respons = malloc(3 * sizeof(int));
    if (haut == bas)
    {
        respons[0] = bas;
        respons[1] = haut;
        respons[2] = A[bas];
        return respons;
    }
    else
    {
        mil = (bas + haut) / 2;
        int *soustabmaxgauche = Trouver_soustableau_maximum(A, bas, mil);
        int *soustabmaxdroite = Trouver_soustableau_maximum(A, mil + 1, haut);
        int *soustabmilieu = Trouver_sous_tableau_milieu(A, bas, mil, haut);
        if (soustabmaxgauche[2] >= soustabmaxdroite[2] && soustabmaxgauche[2] >= soustabmilieu[2])
        {
            respons[0] = soustabmaxgauche[0];
            respons[1] = soustabmaxgauche[1];
            respons[2] = soustabmaxgauche[2];
        }
        else if (soustabmaxdroite[2] >= soustabmaxgauche[2] && soustabmaxdroite[2] >= soustabmilieu[2])
        {
            respons[0] = soustabmaxdroite[0];
            respons[1] = soustabmaxdroite[1];
            respons[2] = soustabmaxdroite[2];
        }
        else
        {
            respons[0] = soustabmilieu[0];
            respons[1] = soustabmilieu[1];
            respons[2] = soustabmilieu[2];
        }
        return respons;
    }
}

int main(void)
{
    int A[4] = {-10, -15, -2, -25};
    int *respond = Trouver_soustableau_maximum(A, 0, 3);
    printf("i = %d j = %d sums = %d\n", respond[0], respond[1], respond[2]);

    // Don't forget to free the allocated memory
    free(respond);

    return 0;
}
// int *soustabmax(int *tab, int size)
// {
//     int i = 0;
//     int j = 0;
//     int k = 0;

//     int sum;
//     int ir;
//     int jr;
//     int summax = -10000000;
//     while (i < size)
//     {
//         j = i;
//         k = i;
//         while (k < size)
//         {
//             sum = 0;
//             j = i;
//             while (j <= k)
//             {
//                 sum += tab[j];
//                 j += 1;
//             }
//             if (sum > summax)
//             {
//                 summax = sum;
//                 ir = i;
//                 jr = j - 1;
//             }
//             k += 1;
//         }
//         i += 1;
//     }
//     int *respons = malloc(3 * sizeof(int));
//     respons[0] = ir;
//     respons[1] = jr;
//     respons[2] = summax;
//     return (respons);
// }

// int main(void)
// {
//     int *respons = malloc(3 * sizeof(int));
//     int tab[9] = {56, -54, 19, 13, -10, 15, -19, -20, 20};
//     respons = soustabmax(tab, 9);
//     printf("ir = %d jr = %d sommemax = %d\n", respons[0], respons[1], respons[2]);
//     return 0;
// }