#!/bin/bash
echo " enter 1 for compilation"
echo " enter 2 for compile and run"
echo " enter 3 for print the content"
read n
touch $2
cp $1 $2
	if [ $n -eq 1 ]
	then
		gcc $2 -o m -lpthread
	else if [ $n -eq 2 ]
	then
		gcc $2 -o m -lpthread
		./m
	else if [ $n -eq 3 ]
	then
		
		cat < $2 
	else
		echo "above"
fi
fi
fi





