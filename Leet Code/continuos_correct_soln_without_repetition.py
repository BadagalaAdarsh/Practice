'''  Roy is working on HackerEarth Profile. Right now he is working on User Statistics.
One of the statistics data (Code Streak) is as follows:

Given the User Activity Data, find the maximum number of continuous correct solutions submitted by any user.
Seems easy eh? Here's the catch! In order to maximize this number a user could have submitted a correct answer to the same problem which he has already solved. Now such cases cannot be tolerated. (See test case for clarification).
Also in all the continuous correct submissions multiple correct submissions to same problem should be counted only once.

User Activity Data will be as follows:
Total number of submissions by the user - N
For each submission its Submission ID - S and Result - R (Solved or Unsolved) will be given.
Solved is represented by integer 1 and Unsolved by 0.

Input:
First line contains integer T - number of test cases. T test cases follow. First line of each test case will contain N. Next N lines each will contain two space separated integers S and R.

Ouput:
For each test case output in a single line the required answer.

Constraints:
1 <= T <= 1000
1 <= N <= 1000000 (106)
1 <= S <= 1000000 (106)
0 <= R <= 1

Note: Sum of N over all the test cases in each file does not exceed 1000000 (106)
SAMPLE INPUT

3
6
1 0
2 1
3 1
4 1
5 1
6 0
5
1 1
2 0
3 1
1 1
2 1
4
1 1
2 1
2 1
3 1

SAMPLE OUTPUT

4
2
3

Explanation

In first test case, submissions from second to fifth are all correct and all are unique. None of the questions were solved before. So answer is 4.

In second tests case, longest range of correct submission is third to fifth i.e answer should be 3. But fourth submission should not counted since it has already been solved once. Hence the answer is 2.

Third test case is quite obvious now.
Time Limit: 2.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
 '''

test=int(input())

for _ in range (test):
    
    N = int(input())
    check = set()
    ans=0
    arr=[]
    sol=0
    
    for i in range (N):
        
        s,r = [int(a) for a in input().split()]
        arr.append([s,r])
        
    for i in arr:
        
        if i[0] not in check and i[1] == 1:
            ans+=1
            check.add(i[0])
            
            if ans>sol:
                sol=ans
            
        elif i[0] in check and i[1] == 1:
            continue
        
        if i[1]==0:
            ans=0
            
    print(sol)
        
'''============above is my code it took 17.5 seconds for overall completion================='''

for _ in range(int(input())):
    n=int(input())
    d=set()
    m=0
    c=0
    for i in range(n):
        a,b=map(int,input().split())
        if b==1 and a not in d:
            c+=1
            d.add(a)
        elif b==0:
            m=max(c,m)
            c=0
    if c>m:
        m=c
    print(m)

'''=================== above code took 13 seconds =============================='''

t=int(input())
for i in  range(t):
    n=int(input())
    d={};p=0;m=[]
    for j in range(n):
        s,r=list(map(int,input().split()))
        if r==1:
          if s not in d:    
            d[s]=1
            p+=1
        else:
            m.append(p)
            p=0
    m.append(p)        
    print(max(m))

'''=========================above code took 16 seconds ==================================='''

    for _ in range(int(input())):
        n = int(input())
        result = []
        dic = {}
        prev = set()
        counter = 0
        maximum = 0
        for i in range(n):
            s,r = map(int,input().split())
            if s not in prev and r==1:
                counter+=1
                prev.add(s)
            if r==0:
                maximum = max(maximum,counter)
                counter = 0
        maximum = max(maximum,counter)
        print(maximum)

'''=======================above code took 13.9 seconds ================================'''

        
        
    

