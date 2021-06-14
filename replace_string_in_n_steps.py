'''Mack gives Daisy two strings S1 and S2-consisting only of characters- 'M' and 'D' , and asks her to convert S1 to S2 in exactly N moves.

In a single move, Daisy has two choices:

    Exchange any one 'M' with a 'D', or
    Exchange any one 'D' with a 'M'.

You need to help Daisy if it's possible to transform S1 to S2 in exactly N moves. Output "Yes" if possible, else "No".


Input Format:
First line contains T, the number of test cases. T lines follow.
Each line consists of 2 space separated strings S1 and S2, and and the value N.


Output Format:
For each test case, print the answer, either "Yes" or "No"-(Without the quotes).


Constraints:
1 ≤ T ≤ 250
1 ≤ |S1|=|S2| ≤ 50
1 ≤ N ≤ 100
SAMPLE INPUT

3
MMDMDDM DDDDDDD 2
MMDD MMDD 1
MMMMMDMM DDDDDMDD 8

SAMPLE OUTPUT

No
No
Yes

Time Limit: 1.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded when all the testcases pass.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
  '''

    t=int(input())
    for i in range(t):
        s1,s2,n=input().split()
        n=int(n)
        m=0
        for j in range(len(s1)):
            if s1[j]!=s2[j]:
                m+=1
        if n>=m and (n-m)%2==0:
            print("Yes")
        else:
            print("No")
