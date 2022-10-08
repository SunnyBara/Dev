#! /bin/bash

while read line
do
    length=${#line}
    i=0
    lettre=0
    message=''
    underscore="_"
    
    while (( $i < $length ));
    do
        lettre=${line:$i:1}
	
	if [ "${line:$i:1}" = "|" ];then
           message="$message$underscore"
        else
	   message="$message$lettre"    
	fi
        i=$((i+1))   
    done
    echo "$underscore$message$underscore"
done 
