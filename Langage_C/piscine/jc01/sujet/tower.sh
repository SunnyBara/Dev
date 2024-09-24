#!/bin/sh

etage=$1
j=0

echo   " _______________________ "


if [ "$2" = "square" ];
then
    while (($j < $etage )) ;
    do
	  echo "|                       |"
	  echo "|   __ __        __ __  |"
	  echo "|  |__|__|      |__|__| |"
	  echo "|  |__|__|      |__|__| |"
	  echo "|                       |"
	  echo "|                       |"
	  j=$((j+1))
	   
    done
elif [ "$2" = "triangle" ];
then
    while (($j < $etage));
    do
	echo "|                       |"
        echo "|                       |"
        echo "|    /\          /\     |"
        echo "|   /__\        /__\    |"
        echo "|                       |"
	echo "|                       |"
	j=$((j+1))

    done

else
    exit 1
fi
echo "|                       |"
echo "|           __          |"
echo "|          |  |         |"
echo "|          |  |         |"
echo "|          |  |         |"
echo "|__________|  |_________|"

