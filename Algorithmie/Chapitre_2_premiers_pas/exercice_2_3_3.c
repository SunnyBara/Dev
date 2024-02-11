// nocode

// montrons part récurrence T(n) = { 2 si n = 2  et 2T(n/2) + n si n = 2^k avec k >1 } = n*log2(n);
// Initialisation
// Hypothèse de récurrence (H0) => T(2) = 2 = 2*log2(2) = 2 * ln(2)/ln(2) = 2 * 1 = 2;
// l'Initialisation est vraie
// Supposons que L'hypothèse (H): T(n) = 2T(n/2) + n = n*log2(n) est vraie;
//
// Passage au successeur
//
// soit n+1 avec n =  2^k;
// T(n+1) = 2T(n+1/2) + n+1 = 2T(2^(k+1)/2) + 2^(k+1) = 2T(2^k) + 2^(k+1) => part l'hypothèse de récurrence
// on remplace T(2^k) part (2^k)*log2(2^k);
// 2T(2^k) + 2^(k+1) = 2*(2^k*log2(2^k) + 2^k+1 = 2^(k+1)*log2(2^k) + 2^(k+1)
// = 2^(k+1)(log2(2^k) + 1) =  2^(k+1)(log2(2^k) + ln(2)/ln(2)) = 2^(k+1)(log2(2^k) + log2(2))
// = 2^(k+1)(log2(2^k*2)) = 2^(k+1)(log2(2^(k+1)) = 2T(2^(k+1)/2) + 2^(k+1)
// donc T(n+1) =  2T(n+1/2) + n+1 =  (n+1)log2(n+1);
// On a montré part recurrence que l'hypothèse est Vraie