#! /bin/bash
i=0
j=0
mix1=$(cat $1 | tr -d [:space:])
mix2=$(cat $2 | tr -d [:space:])
length=${#mix1}
length2=${#mix2}
test=${mix1:0:1}
test2=${mix2:0:1}
while (($i < $length ))  && (($j < $length2));
do
      echo "$test"
      echo "$test2"
      i=$((i+1))
      j=$((j+1))
      test=${mix1:i:1}
      test2=${mix2:j:1}
done
if (($i < $length ));
then
    while (($i < $length ));
    do
	echo "$test"
	i=$((i+1))
	test=${mix1:i:1}
    done
fi

if (($j < $length2 ));
then
    while (($j < $length2));
    do
	echo "$test2"
	j=$((j+1))
	test2=${mix2:j:1}
    done
fi    
