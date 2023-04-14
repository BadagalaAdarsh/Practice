
# traverse the file 1 line by line in bash

for line in $(cat file1.txt); do
# check if the line present in file2.txt if exist continue the loop else print the line
if grep -q "$line" file2.txt; then
continue
else
echo "$line"
fi
done


