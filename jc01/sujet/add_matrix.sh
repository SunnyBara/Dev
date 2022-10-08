#! /bin/bash
L1a=$(head --line=1 $1)
L2b=$(head --line=1 $2)
taillea=${#L1a}
b=$((taillea -1))
tailleb=${#l2b}
matA=$(cat $1)
matB=$(cat $2)
lengthA=${#matA}
lengthB=${#matB}
i=0
j=0
varA=${matA:i:1}
varB=${matB:i:1}
if (("$lengthA" != "$lengthB"));
then
    exit 1
fi
while (($i < $lengthA));
do
    if [ "$j" == "$taillea" ];
    then
        total="$total\n"
	j=0
	i=$((i+1))
	varA=${matA:i:1}
        varB=${matB:i:1}
	continue
    fi    
    if [ "$varA" = " " ] && [ "$varB" = " " ];
    then
	total="$total "
    else
        Add=$((varA+varB))
        total="$total$Add"
    fi
    i=$((i+1))
    j=$((j+1))
    varA=${matA:i:1}
    varB=${matB:i:1}
done
echo -e "$total"
