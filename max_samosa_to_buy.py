''' Shiro is an avid lover of Samosas. He went down to the Samosa street to have some. But he only has K units of money with him. There are N shops on the street and unfortunately, all of them have only one samosa remaining. You are also given an array A[ ] , where Ai is the cost of a samosa on the i'th shop.
Find the maximum samosas that Shiro can eat.

Input:
First line contains two space-separated integers N and K.
Second line contains N space separated integers, the cost of a samosa on the shops.

Output:
Print the answer.

Constraints:
1 ≤ N ≤ 103
0 ≤ K ≤ 103
0 ≤ Ai ≤ 100
SAMPLE INPUT

4 10
5 4 2 4

SAMPLE OUTPUT

3

Explanation

Shiro can eat from the 2nd,3rd and 4th Shop.
Time Limit: 2.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic.  '''

n,s=[int(b) for b in input().split()]

shop=[int(a) for a in input().split()]

p=sorted(shop)

count=0

for price in p:
	if s>=price:
		s=s-price
		count+=1
	else:
		break
print(count)
