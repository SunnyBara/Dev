#! /bin/bash

i=0
while (( $i < $#));
do
    i=$((i+1))
    str=${@:i:1}    
    length=${#str}
    echo "$str" counts "$length" characters
done
