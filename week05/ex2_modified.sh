#create the file for sequential numbers                                                   
if test ! -f seq_nums
then
    echo 0 > seq_nums
fi

for i in `seq 1 $1`;
do
	#lock to not allow others
	if ln seq_nums seq_nums.lock
		then

	
		#reads and increases the last number
		LASTNUMBER=`tail -1 seq_nums`
		LASTNUMBER=$((LASTNUMBER+1))

		echo $LASTNUMBER >> seq_nums

		#Unlock
		rm seq_nums.lock
	fi
done