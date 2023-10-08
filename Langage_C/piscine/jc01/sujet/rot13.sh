#! /bin/bash

i=0
j=0
test=$(cat $1)
tab='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
length=${#test}
tet=${test:i:1}
teta=${tab:j:1}
while (($i < $length));
do
    teta=${tab:j:1}   
    while  (($j < 53)) &&  [ "$tet" != "$teta" ];
    do
	j=$((j+1))
	teta=${tab:j:1}
    done
    if (($j < 14));
    then
        u=$((j+13))
        var=${tab:u:1}
    elif (($j > 13)) && (($j < 26));
    then
        u=$((j-13))
        var=${tab:u:1}
    elif (($j > 25)) && (($j < 40));
    then
        u=$((j+13))
        var=${tab:u:1}
    elif (($j > 39)) && (($j < 53));
    then
        u=$((j-13))
        var=${tab:u:1}	
    else
	var=${test:i:1}	
    fi
    text="$text$var"
    i=$((i+1))
    tet=${test:i:1}
    j=0
done
echo $text
