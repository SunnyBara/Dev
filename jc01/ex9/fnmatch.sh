#! /bin/bash
test=0
ct[k]=${#1}
cpt=0
l=0
i=0
j=0
k=0
m=0
length=${#1}
length2=${#2}
while (( $j < $length2 && $i < $length ));
do 
    lettre=${1:$i:1}
    arg1=${2:$j:1}
    if [ "$lettre" = "?" ];
    then
        i=$((i+1))
	j=$((j+1))
	continue
    elif [ "$lettre" = "*" ];
    then
	while (( $i < $length )) && [ "$lettre" = "*" ];
	do
	    i=$((i+1))
	    lettre=${1:$i:1}	   
	done	
	if [ "$lettre" = "$arg1" ];
	then
	    continue
	elif (( $i == $length ));
	then
	    j=$length2
	    break
	elif [ "$lettre" = "?" ];
	then
	     i=$((i+1))
	     j=$((j+1))
	     continue
	else    
	    while (($j < $length2 )) && [ "$lettre" != "$arg1" ];
	    do
		j=$((j+1))
		arg1=${2:$j:1}
	    done
	fi
    elif [ "$lettre" = "[" ];
	 i=$((i+1))
	 lettre=${1:$i:1}
	 while [ "$lettre" != "]" ];
	 do
	     $
    else
	test=1
	break
	    
    fi
         j=$((j+1))  
         i=$((i+1))
done 
    if (($test==0 && $i == $length && $j == $length2 ));
    then
	echo $2
    else
	echo 'invalide'
    fi
