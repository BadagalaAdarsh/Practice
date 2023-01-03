'''  Marut loves good strings. According to him, good strings are those which contain either all alphabets of uppercase or lowercase. While he is preparing for his exams, he finds many bad strings in his book and wants to convert them to good strings. But he wants to do this in minimum number of operations.
In one operation, he can pick only one character of any case and convert it to any other case.

As his exams are going on, he wants your help.

Input:
The first line contains an integer T, denoting the number of test cases.
Each test case consists of only one line with a string S which contains uppercase and lowercase alphabets..

Output:
Print the minimum number of operations, in which Marut can obtain a good string.
Print the answer for each test case in new line.

Constraints:
1 ≤ T ≤ 10
If T is not in this range, print "Invalid Test" (without the quotes)
1 ≤ Length of S ≤ 100
S can contain numbers, special characters but no spaces.
If the length of string is not in the above range or it does not contain any alphabets, print "Invalid Input" (without the quotes)

For Example, if the input is:
0
TestString

Print "Invalid Test" (without the quotes)
SAMPLE INPUT

3
abcEfg
!@6#2
123A

SAMPLE OUTPUT

1
Invalid Input
0

Time Limit: 1.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
  '''

'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''



#Today I came to know that it is necessary to check even the test cases which I have learnt in this problem
# Because of not checking test cases I was unable to solve 4 test cases
# It is always suggested to check the constraints of test cases and check whether the given test case in number or string

# Write your code here

test = input()

if (test.isdigit()):
    
    test = int(test)
    
    if test >=1 and test<=10:

        for _ in range (test):
            
            string = input()
            
            upper=lower=0
            valid = invalid = 0
            
            for i in string:
                
                #comparing with ascii values of lower case letters
                if (i>='a' and i<='z'):
                    lower+=1
                
                #comparing with ascii values of upper case letters
                if(i>='A' and i<='Z'):
                    upper+=1
                    
            
            if (lower==0 and upper ==0) or len(string) > 100:
                print("Invalid Input")
                
            elif lower==0 or upper == 0:
                print(0)
                
            else:
                print(min(lower,upper))
    else:
        print("Invalid Test")

else:
    print("Invalid Test")
    
