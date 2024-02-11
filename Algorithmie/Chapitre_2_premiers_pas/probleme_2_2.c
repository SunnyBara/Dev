// pour i = 1 à A.longueur -1                   //c1 n
//   pour j = A.longueur decr jusqu"a i +1;     //c2  somme de 1 à n de i
//       Si A[j] < A[j-1]                       //c3  somme de 1 à n de i-1
//           permuter A[j] <-> A[j-1]           //c3  somme de 1 à n de i-1

// a) pour prouver que le tri bulle tri réellement on peut analyser l'invariant de boucle
//
// b) Initialisation : Pour N0 le seule élément présent est déjà trié.
// Conservation : Pour N si les N-1 élément sont triées et qu'on prend l'élement de A[A.longueur] en le comparant jusqu'a A[n]
// alors les N éléments seront triées. Donc l'invariant [1 à N-1] est vrai avant chaque nouvelle itérations et chaque fin de boucle assure
// le trie des éléments de [1 à N]
// Terminaison: Arrivé à j = i+1 et sachant que l'invariant de boucle est vraie.
// On a comparé l'élement initialement en A[A.longueur] avec tous les éléments jusqu'a A[i+1];
// permettant d'assurer que l'élément en A[i+1] est l'élément le plus petit se trouvant dans la partie [i+1 à A.longueur]
// on sort de la boucle donc on obtient un tableau A' trié de [1 à i+1].
//
// c) En partant de la terminaison de la question b) qui assure que chaque sorti de la seconde boucle pour amène l'élement le plus
// faible de la partie [i+1 à A.longueur] en position i+1; et sachant l'invariant de boucle assurant le trie de [1 à i] à l'entrée
// on conclu qu'a chaque nouvelle itération de la première boucle pour on a pour i un tableau de type
// A' avec a'1<= a'2 ...<= a'i-1  + a'i ... a'n non triée.
// Sachant que l'algorithme avance jusqu'a i = A.longueur la dernière itération assure que
// A' contient a'1 <= a'2...<= a'n + {} on obtient donc le tableau A triée.

// d) complexité => n(n+1)/2 => O(n^2) => équivalente au tri part insertion