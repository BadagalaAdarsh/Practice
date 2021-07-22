for file in  *.mp4
do
if [[ $file = V* ]]
then
        num=${file:3:14}
	year=${num:0:4}
	mon=${num:4:2}
	day=${num:6:2}
	hour=${num:8:2}
	min=${num:10:2}
	sec=${num:12:2}
	#echo "date is $year $mon $day, time is $hour $min $sec"
	touch -a -m -t $year$mon$day$hour$min.$sec $file
	echo "$file is modified"
fi
done
