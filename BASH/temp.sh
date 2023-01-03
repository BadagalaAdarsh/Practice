for file in *.jpg
do
	for file2 in /home/adarsh/Pictures/DCIM/Camera_jul_18_2021/*.jpg
	do
		if [[ $file2 = /home/adarsh/Pictures/DCIM/Camera_jul_18_2021/IMG2* ]];
		then
			one=${file:4:6}
			two=${file2:57:6}
			if [[ $one = $two ]]
			then
				mv $file  ${file2:46:50}
			fi
			#echo $file2
			#echo $two
		fi
	done
	
done
