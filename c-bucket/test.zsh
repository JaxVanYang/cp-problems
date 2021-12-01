g++ std.cc -o std.out

i=1
n=10

while [ $i -le $n ]; do
	start_time=$(date +%s%N)
	./std.out < $i.in > $i.out
	end_time=$(date +%s%N)
	printf "$i : $((($end_time - $start_time) / 1000000))ms\n"
	i=$(($i + 1))
done
