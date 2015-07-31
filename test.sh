#!/bin/bash

echo "Running encoder tests:"
array=(  0 -8192 8191 2048 -4096 6111 340 -2628 -255 7550 )
for i in "${array[@]}"
do
	echo ***Running Encoder Test for value $i***
	./bit14encoder $i
	echo -----------------------------------------
done


echo "Running decoder tests"
array=( 4000 0000 7f7f 5000 0a05 5500 0A0A 0029 3F0F 4400 5E7F )
for i in "${array[@]}"
do
	echo ***Running Decoder Test for value $i***
        ./bit14decoder $i
        echo ------------------------------------------

done



