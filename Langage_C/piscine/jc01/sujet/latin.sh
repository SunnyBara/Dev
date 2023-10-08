#! /bin/bash 
i=0
j=0
n=0
if (( $# == 0 ));
then
    exit 1
fi
tab=$(cat $1 | tr  --squeeze-repeats ' ' | tr -d '\t' | tr -d '\n')
length=${#tab}
test=${tab:0:1}
while  (($i < $length ));
do
    i=$((i+1))
    n=$((n+1))
    test=${tab:i:1}
    if [ "$test" = " " ];
    then
	var1="ae"
	var2="${tab:j:n}"
	var3="$var3$var2$var1"
	j=$i
	n=0
    fi
done    
echo $var3 | tr -d '.' | tr -d ' ' | tr [a-z] [A-Z]

