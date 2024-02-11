// A<2,3,8,6,1>  B<0,1,2,3,4>

// a) inversion => i < j && A[i] > A[j]
// 1) 0 < 4 && 2 > 1;
// 2) 1 < 4 && 3 > 1;
// 3) 2 < 3 && 8 > 6;
// 4) 2 < 4 && 8 > 1;
// 5) 3 < 4 && 6 > 1;
//
// b) le tableau contenant le plus d'inversion  pour un ensemble de nombre {1,2,...,n}
// est un tableau trié dans l'ordre décroissant soit A'<n,n-1,...,1>;
// il contient n(n-1)/2 inversion ( somme de 1 à n-1 des i);
// c) le tri part insertion à dans son cas le plus défavorable une complexité qui est proche du nombre d'inversion
// du tableau précédent. Cela s'explique car le tri part insertion parcours le tableau et effectue des inversions successives.
// donc si on voulait passer du tableau A' à un tableau A<1,...,n> il faudrait executer O(n^2) opérations soit O(n^2) iversions
// d) a l'image du probleme 2.1 on effectue un mixte entre le tri fusion et le tri par insertion.
//
//
//
//
//
//
