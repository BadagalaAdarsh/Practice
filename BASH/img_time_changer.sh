for file in  *.jpg
do
if [[ $file = IMG* ]]
then
	year=${file:4:4}
	mon=${file:8:2}
	day=${file:10:2}
	echo $year $mon $day
	hour=${file:13:2}
	min=${file:15:2}
	sec=${file:17:2}
	
	if [[ $hour = W* ]]
	then	
		#echo $hour
		continue
	fi
	#echo $file
	#hour=${num:8:2}
	#min=${num:10:2}
	#sec=${num:12:2}
	#echo "date is $year $mon $day, time is $hour $min $sec"
	touch -a -m -t $year$mon$day$hour$min.$sec $file
	echo "$file is modified"
fi
done
