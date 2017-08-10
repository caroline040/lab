#!/bin/bash

files=`ls`

i=0
for n in $files 
do
	i=$(($i + 1))
done

echo "$i"
