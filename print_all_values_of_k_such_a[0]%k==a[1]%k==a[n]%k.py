''' Oz has a list arr[] of M integers. He has to find all integers K such that :

1) K > 1
2) arr[1]%K = arr[2]%K = arr[3]%K = ... = arr[M]%K where '%' is a modulus operator

Help Oz to find all such K's.

Input :
First line of input contains an integer M. Then M lines follow each containing one integer of the list. Input data is such that at least one integer K will always exist.

Output :
Output all possible integers K separated by space in increasing order.

Constraints :
- 2<= M <=100
- 1< value of each integer <109
- All integers will be distinct
SAMPLE INPUT

3
38
6
34

SAMPLE OUTPUT

2 4 

Time Limit: 3.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic

'''

def gcd(a, b):
    if(a == 0):
        return b
    return gcd(b % a, a)
    
def reduce(list):
    v=list[0]
    for i in range(1,len(list)):
        v=gcd(v,list[i])
    return v
m = int(input())
arr = []
for i in range(m):
    arr.append(int(input()))
arr.sort()
g=[]
for i in range(m-1):
    g.append(arr[i+1]-arr[i])
    
tmp=reduce(g)
tmp1=set({tmp})
for i in range(2,int(tmp**0.5)+1):
    if(tmp%i)==0:
        tmp1.add(i)
        tmp1.add(tmp//i)
print(*sorted(tmp1))
