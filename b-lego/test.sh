#!/bin/bash

g++ std.cpp -o std.out

i=1
n=10

:> std.txt
while [ $i -le $n ]; do
	start_time=$(date +%s%N)
	./std.out < $i.in > $i.out
	end_time=$(date +%s%N)
	printf "$i : $((($end_time - $start_time) / 1000000))ms\n"
	cat $i.out >> std.txt
	i=$(($i + 1))
done
