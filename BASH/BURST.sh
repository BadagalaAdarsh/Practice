for file in  *.jpg
do
if [[ $file = 00100sPORTRAIT_00100_BURST* ]]
then
	#echo $file
	year=${file:26:4}
	mon=${file:30:2}
	day=${file:32:2}
	#echo $year $mon $day
	hour=${file:34:2}
	min=${file:36:2}
	sec=${file:38:2}
	
	#if [[ $hour = W* ]]
	#then	
		#echo $hour
		#continue
	#fi
	#echo $file
	#hour=${num:8:2}
	#min=${num:10:2}
	#sec=${num:12:2}

	#echo "date is $year $mon $day, time is $hour $min $sec"
	touch -a -m -t $year$mon$day$hour$min.$sec $file
	echo "$file is modified"
fi
done
