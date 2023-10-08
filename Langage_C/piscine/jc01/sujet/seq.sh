#! /bin/bash
echo "$1" , "$2" , "$3"
if (("$1" > "$3")) && (("$2" < 0)) ;
then
	l=$1
	while (("$l" > "$3"));
	do
	l=$((l-$2))
	echo "$l"
	done
	
	

elif (("$1" < "$3")) && (("$2" > 0)) ;
then
	l=$1
	while (("$l" < "$3"));
	do
	l=$((l+$2))
	echo "$l"
	done
	
elif (($1 == $3));
then
    echo "$1"
	exit 0

else
    echo 'je passe dans else'
	exit 1
fi
echo 'jsuis pas dans la boucle lol'
