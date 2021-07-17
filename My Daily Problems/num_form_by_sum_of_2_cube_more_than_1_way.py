'''  Little Syed loves brute force. He thinks that brute force can be the solution to any problem in the world. You give him any question, and he'll have a brute force answer ready for you, almost all the time. His good friend Little Jhool (Like, always!) decides to teach him a lesson, by giving him problems which cannot be solved by brute force, because he wants Syed to learn algorithms.

    Given a number, n, Syed needs to find the number closest to n, though less than n which satisfies Jhool's swinging theorem.

Jhool's swinging Theorem: A number n, such that it can be expressed as a sum of two positive algebraic cubes; AND, if that number can be expressed in such a manner in more than one way - it satisfies the theorem.

Now, everyone here on HackerEarth knows how much we hate Little Jhool (No, not really!) - so we want you to help Syed in figuring out Jhool's queries - once and for all!

Input Format:
The first line contains an integer, t - denoting the number of test cases.

The next t lines will contain, an integer - n - denoting the number which Jhool gives.

Output Format:
You have to print the previous number satisfying the given constraints. If no such previous number exists, print -1.

Constraints:
1 <= t <= 100
1 <= n <= 704977
SAMPLE INPUT

2
100
4150

SAMPLE OUTPUT

-1
4104

Explanation

In the first case, since no such number below 100 exists, the result is -1. In the second case, 4104 is the answer because: (4096 + 8 = 4104) or (161616 + 222) and (3375 + 729 = 4104) or (151515 + 999) - that is, there is more than one way in which 4104 can be expressed, satisfying the theorem.
Time Limit: 2.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
 '''

for _ in range (int(input())):
    
    num = int(input())
    
#Check is the list of numbers which can be formed by some of two cubes in more than one way
#as it was not is sorted order for the purpose of problem I have sorted it and reversed the order of numbers
#c++ program to get this sequence is below this program 
    check=[1729,4104,39312,40033,13832,32832,20683,195841,216027,171288,64232,46683,110808,149389,314496,65728,320264,110656,262656,134379,165464,443889,216125,513000,439101,327763,513856,373464,515375,402597,558441,525824,593047,684019]
    
    check.sort()
    
    check=check[::-1]
    
    if num < 1729:
        print(-1)
        
    else:
        for i in check:
            
            if num > i:
                print(i)
                break

#################################################################################################

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

void findAllNumbers( long long int N)
{
	// find cube root of N
	long long int cb = pow(N, 1.0 / 3);

	// create an empty set
	set<int> s;

	for (int i = 1; i < cb - 1; i++) 
	{
		for (int j = i + 1; j < cb; j++) 
		{
			// (i, j) forms a pair
			int sum = (i * i * i) + (j * j * j);

			// sum is seen before
			if (s.find(sum) != s.end())
				cout << sum << endl;

			else
				// sum is not seen before
				s.insert(sum);
		}
	}
}

int main()
{
	long long int N = 704977; # This was the limit given in the constraints that's why I have given it

	findAllNumbers(N);
	
	return 0;
}


################################################################3
''' c++ program for this question from the submissions of HackerEarth'''

    #include <iostream>
    #include <cmath>
    using namespace std;
     
    int main()
    {
        long long int arr[704969*2]={};
        
        for(int i=1;i<=89;i++)
        {
            for(int j=i;j<=89;j++)
            {
                //if(i==j) continue;
                int k=pow(i,3)+pow(j,3);
                arr[k]++;
            }
        }
        
        int t;
        cin>>t;
        while(t--)
        {
            int n,i;
            cin>>n;
            for(i=n;i>1;i--) { if(arr[i]>1) { cout<<i<<endl; break; } }
            if(i==1) cout<<"-1\n";
        }
        return 0;
    }


# Solution in C Language

    #include<stdio.h>
    #include<stdlib.h>
     
    int main() {
        int testcases, num, *result, ans;
        int cube[90];
        for(int i = 1; i <= 90; i++)
            cube[i-1] = i*i*i;
            
        scanf("%d", &testcases);
        while(testcases--) {
            scanf("%d", &num);
            result = (int *) calloc(num, sizeof(int));
            
            for(int i = 0; cube[i] < num; i++) {
                for(int j = i + 1; cube[i] + cube[j] < num; j++) {
                    result[cube[i]+cube[j]]++;
                }
            }
            
            ans = -1;
            for(int i = num - 1; i >= 0; i--) {
                if(result[i] >= 2) {
                    ans = i;
                    break;
                }
            }
            printf("%d\n", ans);
        }
        return 0;
    }

#Solution in Python language from the submissions of Hacker Earth

cu=[i**3 for i in range(1,100)]
cnt=dict([(i,0) for i in range(1,(100**3)+1)])
for i in range(99):
    for j in range(i,99):
        c=cu[i]+cu[j]
        if c>100**3:
            break
        cnt[c]+=1
cnt=[k for k,i in cnt.items() if i>1]
t=int(input().strip())
for _ in range(t):
    n=int(input().strip())
    arr=[i for i in cnt if i<n]
    if len(arr)==0:
        print(-1)
    else:
        print(arr[-1])

###############################################################################3

def cube_root(x):
    if 0<=x: return x**(1./3.)
    return -(-x)**(1./3.)
    
N = int(input())
for _ in range(N):
    val = int(input())
    new_val = int(cube_root(val))
    count = 0
    li = []
    for i in range(new_val, 1, -1):
        for j in range(1, i):
            if (i**3 + j**3) < val:
                li.append(str((i**3 + j**3)))
    set_li = list(set(li))
    main_li = []
    set_li.sort(reverse=True)
    ll = []
    for i in set_li:
        if li.count(i) > 1:
            ll.append(int(i))
    ll.sort()
 
    print(max(ll) if ll else "-1")

#############################################################################################

    lim = 704977
    def sol(n,cubesS,cubesL):
        for i in range(n,-1,-1):
            count = 0
            for j in cubesL:
                if j > i:
                    break
                a = i
                b = i-j
                #print(i,j,a,b)
     
                if b in cubesS: # and a in cubesS:
                    if count > 1:
                        return i
                    else:
                        count += 1
        return -1
        
    t = int(input())
    nums = [False]*lim
    for i in range(90):
        nums[i**3] = True
    cubesL = [i for i in range(lim) if nums[i]]
    cubesS = set(cubesL)
    for _ in range(t):
        n = int(input())
        print(sol(n,cubesS,cubesL))

######################################################################################

    import bisect
    import math
    def find_lt(a, x):
        'Find rightmost value less than x'
        i = bisect.bisect_left(a, x)
        if i:
            return a[i-1]
        return -1
     
    def genList():
        list = []
        for i in range(1,90):
            for k in range(i,90):
                list.append(i**3+k**3)
        list.sort()
        last = list[0]
        answer = []
        add = False
        for i in range(1,len(list)):
            if list[i] == last:
                add = True
            else:
                if add:
                    answer.append(last)
                add = False
                last = list[i]
        return answer
     
    tests = int(input())
    check = genList()
    for k in range(0,tests):
        N = int(input())
        print(find_lt(check,N))

