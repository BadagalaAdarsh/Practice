'''  
PandeyG, a brilliant tennis player, decided to start a tournament in his colony. Now, since PandeyG is overly optimistic and ambitious - he tries to lure in as many people as he can from his colony for them to participate in his very own knockout type tennis tournament. What he fails to realize that, to have a knockout tournament, you need to have number of players, in the form of 2^a, where a is any number - what it simply means is that, if there are only 7 people to take part in the tournament, a knockout version cannot be held.

Because: 1 vs. 2 | 3 vs. 4 | 5 vs. 6 | 7 vs. ? |

enter image description here

So, he comes with a brilliant algorithm of adding ghost opponent, to make his tournament more popular. So, for every player who is short of an opponent, he will face a ghost - matches between the ghosts, and matches between ghosts and players are not counted, of course. So, basically, the player who gets the ghost opponent gets a free bye to the next round, i.e., he qualifies for the next round, without even facing an opponent. If there are no players, there will obviously be no matches.

So, given the number of players willing to take part, can you help PandeyG figure out the number of matches he will have to make arrangements for?

Input Format: On the first line, the number of test cases are given, then following every line, the number of players who want to participate n is given.

Output Format: For every n, output the number of matches which will be played for the tournament to be held, by our PandeyG.

Constraints:

    t <=10

    0<=n<=10^9

SAMPLE INPUT

2
7
3

SAMPLE OUTPUT

6
2

Explanation

For n = 7, 1 v 2 - 1 3 v 4 - 2 5 v 6 - 3 7 v ? - 1 v 3 - 4 5 v 7 - 5 - 1 v 7 - 6

So, 6 matches will need to be played!
Time Limit: 2.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic


 '''



test=int(input())
for _ in range (test):
    player=int(input())
    
    if player==0:
        print(0)
        
    else:
        print(player-1)


"""or"""

test=int(input())

for _ in range (test):
    
    players=int(input())
    
    ans = 0
    
    while players>1:
        while players%2==0:
            players/=2
            ans+=players
            
        if players>1:
            players-=1
            ans+=1
            
    print(int(ans))
