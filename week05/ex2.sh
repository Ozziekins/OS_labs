if test ! -f seq_nums
then
    #creates the file for sequential numbers                                                   
    echo 0 > seq_nums
fi

for i in `seq 1 $1`
do
	# reads and increases the last number
	LASTNUMBER=`tail -1 seq_nums`
	LASTNUMBER=$((LASTNUMBER+1))

	echo $LASTNUMBER >> seq_nums
done