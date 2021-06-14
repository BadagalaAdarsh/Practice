'''  HackerMan has brought a new drawing book for his child, which consists only of geometric shapes. Its consists of lessons where the child has to make drawings using the geometric shapes. The first lesson is based on how to use squares to build different objects.

You are task is to help HackerMan in teaching one part of this lesson. You have to help him in determining, given S number of squares, how many distinct rectangles you can build out of that.

Two rectangles are considered different if none of them can be rotated and moved to obtain the second one. During rectangle construction, the child can neither deform the squares nor put any squares upon any other ones.

Note: All the squares are of the same configuration.

Constraints

Each file will not contain T test cases where

Input

There will be one line of input that will contain an integer N (

) which represents the number of test cases, each subsequent line contains an integer S that represents the number of squares available.

Output

Each line should contain a single integer equal to the number of different rectangles that the child can form using the corresponding number of squares in that line of input.

Explanation of sample below

There are a total of 3 test cases.

Only 1 rectangle can be made using 1 square, and its the square itself.

2 rectangles can be made using 2 square, one is the square itself and the other is formed by joining the 2 squares.

A total of 5 rectangles can be made using 4 squares. 4 rectangles will be only 1 square wide and 1 rectangle will be 2 squares wide.
SAMPLE INPUT

3
1
2
4

SAMPLE OUTPUT

1
2
5

Time Limit: 2.0 sec(s) for all input files combined.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
 '''


import math

test = int(input())

for _ in range (test):
    
    squares = int(input())
    ans=0
    
    for length in range (1,int(math.sqrt(squares))+1):
        height = length
        while height * length <= squares:
            ans+=1
            height+=1
            
    print(ans)


'''================above is my code === even it got accepts == in web site it shows partially solved============'''

T = int(input())
for i in range(T):
    S = int(input())
    numberOfWays = 0
    for j in range(1, int(S ** 0.5) + 1):
        numberOfWays += int(S / j) - (j - 1)
    print(numberOfWays)

''' ===============this is one of best solutin in hackerearth website================='''

    import math
    for _ in range(int(input())):
        N = int(input())
        count = 0
        for i in range(1,math.floor(math.sqrt(N))+1):
            count+=int(N/i)-i+1
        print(count)

'''=================this too is one of best solution in hackerearth in website ================'''
import math
 
N = int(input())
for _ in range(N):
    square = int(input())
    count = 0
    for each in range(1, int(math.sqrt(square))+1):
        count += (square // each) - (each-1)
    print(count)
'''==================these all are better than my solution and the one given in geeks for geeks website==============='''

def test():
    n = int(input())
    res = 0
    i = 1
    while(n/i >= i):
        res += n//i - (i-1)
        i+=1
    print(res)
 
t = int(input())
while(t):
    t-=1
    test()

'''========================================================================'''


            
