#! /bin/bash
liste=$(ls $1)
for current in $liste
do
    j=0
    length2=${#2}
    k=$length2
    rechercheb=${2:k:1}
    length=${#current}
    i=$length
    recherche=${current:i:1}
    transfert=""
    while (($i > 0)) && [ "$recherche" != "." ];
    do
        i=$((i-1))
        recherche=${current:i:1}
    done
    while (($i > $j));
    do
	ajout=${current:j:1}
	transfert="$transfert$ajout"
	j=$((j+1))
    done
    while (( $k > 0 )) && [ "$rechercheb" != "." ];
    do
	k=$((k-1))
	rechercheb=${2:k:1}
    done
    while (( $k < $length2 ));
    do
	ajoutb=${2:k:1}
	transfert="$transfert$ajoutb"
	k=$((k+1))
    done
    echo 'mv'  "$current" dans "$transfert"
    
done
