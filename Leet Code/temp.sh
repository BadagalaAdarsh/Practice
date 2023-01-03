for j in *.cpp;do
file=$j
#echo $file
i=1
sub='long'
while read line;do
#echo
if [[ $line == *"$sub"* ]];then
	echo $j
fi 
done < $file
done
