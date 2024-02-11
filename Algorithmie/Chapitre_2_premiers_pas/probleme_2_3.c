// règle de Horner
// y = 0
// pour i = n decr jusqu'à 0
//      y = ai + x*y;

// a) le programme part de n jusqu'a 0 sans aucune possibilité de sortir rapidement.
// on a donc un parcourt linéaire de complexité O(n);
//
// b)
// soit A <a0,a1....,an>
// pour i = n et i > 0;
//  y = y + A[i]*x^i;
// renvoyer y;
// l'algorithme est de complexité O(n);
// c)
//
//
