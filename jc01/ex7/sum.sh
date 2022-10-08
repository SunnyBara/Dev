#! /bin/bash

i=$#
j=0
somme=0
var1="+"
var2=""
var3="$var2"
test="$1"
if (( $i > 0 )); then
   for element in $@;
   do
       somme=$((somme + element))
       if (( $j >= 1 )); then  
          test="$test $var1 $element"      
       fi
       j=$((j+1)) 
   done
   echo "$test = $somme"
else
    echo "0 = 0"
fi
