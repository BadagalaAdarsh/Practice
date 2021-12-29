for((i = 1; i <= 1000; i++)); 
do  
    echo $i
    python testcase.py > input
    ./one < input > out1
    ./two < input >out2
    diff -w out1 out2 || break

done