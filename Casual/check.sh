for((i = 1; ; i++)); do
    echo $i
    ./generator $i > input # to store the random inputs in the input file
    ./efficient_solution < input > output1 # pass the input to efficient one and store output
    ./brute_force < input > output2 # pass the same output to brute force and check output
    diff -w output1 output2 || break # diff is the bash function to check two files
                                     # -w is used to ignore white spaces or say new lines

    # can write the above diff line as below to
    # diff -w <(./efficient_solution < input) <(./brute_force < input) || break
done

#run the file using bash check.sh in the terminal
# we have used infinite loop so that we can check upto which i out program is working good