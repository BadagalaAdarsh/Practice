'''An integer is said to be k-reachable from another integer if the latter can be converted to the former by replacing atmost k digits. Note that, leading 0's are not considered the part of the number and hence are not allowed to replaced with non-zero integers.

For example,

1123 is 15-reachable from 2223 but not 1-reachable.

6 is 2-reachable from 10, but 10 is not 2-reachable from 6

Mancunian has been given the following problem. He is provided the initial integer N and the value of k. Now he has to answer Q queries. Each query is represented by a pair (L, R). The answer for a query is the number of integers in the range L to R (inclusive) which are k-reachable from N.

Input:
The first line contains three integers N, k and Q.
Each of the next Q lines is of the form L R denoting a specific query.

Output:
For each query, output the answer to the given query in a new line.

Constraints:
1 <= N < 107
1 <= k <= 5
1 <= Q <= 105
1 <= L <= R < 107
SAMPLE INPUT

6 2 1
8 12

SAMPLE OUTPUT

2

Explanation

8 and 9 are 2-reachable from 6 whereas 10, 11 and 12 are not reachable at all.
Time Limit: 1.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic

'''

#I was Unable to solve this question

#This python solution was partially accepted as per the hackerearth 

    from math import log, ceil
     
    MAX = 10 ** 7 + 10
    arr = [0] * MAX
     
    n, k, t = map(int, input().strip().split())
    c = ceil(log(n, 10))
    c = 10 ** c
    # print(c)
     
    for i in range(1, min(MAX, c)):
        a, b = n, i
        cnt = 0
        while a and b:
            if a % 10 != b % 10:
                cnt += 1
            a //= 10
            b //= 10
        
        arr[i] = arr[i-1]
        if cnt <= k:
            arr[i] += 1
            
    for i in range(c, MAX):
        arr[i] = arr[i-1]
        
    for _ in range(t):
        l, r = map(int, input().strip().split())
        res = arr[r] - arr[l-1]
        print(res)

#Other solution in python which too got partially accepted due to time limit exceeding


import sys
def diff(a,b):
    ans=0
    while(True):
        if(a%10 != b%10):
            ans+=1
        a//=10
        b//=10
        if(b==0):
            break
    return ans
    
al = sys.stdin.readlines()
a = list(map(int, al[0].split()))
n, k, q = a[0], a[1], a[2]
pre=[0]*10000005
st=1
en=10**(len(str(n)))
for m in range(st,en):
    if diff(m,n)<=k:
        pre[m]=1
    pre[m]+=pre[m-1]
for m in range(en,10000001):
    pre[m]+=pre[m-1]
for i in range(q):
    Q=list(map(int, al[i+1].split()))
    print(pre[Q[1]]-pre[Q[0]-1])

#Below code is in C lang which got completely accepted
    #include <stdio.h>
    #include<stdbool.h>
    #include<stdlib.h>
    #define MAX 10000007
    int a[MAX] ,p[MAX] ,m[10] ,t[10];
    int max(int a,int b){   return (a > b ? a : b); }
    void printArr() {
        int i;
        for(i = 1 ; i < 100 ; i++)  printf("%d " ,p[i]);
        printf("\n");
    }
    int main() {
       int n ,i ,k ,Q ,r = 0 ,num ,j ,l;
        scanf("%d %d %d" ,&n ,&k ,&Q);
        num = n ,r = 0;
        while(num){
            m[r++] = num % 10;
            num /= 10;
        }
        for(i = 1 ; i < MAX ; i++) {
            j = i ,l = 0;
            while(j){
                t[l++] = j % 10;
                j /= 10;
            }
            if(r >= l){
                int sum = 0;
                for(j = 0 ; j < r ; j++)     if(m[j] != t[j])    sum++;
                if(sum <= k)    a[i] = 1;
            }
            p[i] = p[i - 1] + a[i];
        }
        //printArr();
        while(Q--) {
            int l ,r;
            scanf("%d %d" ,&l ,&r);
            printf("%d\n" ,p[r] - p[l - 1]);
        }
        return 0;
    }

#Another Solution in C Lang

    #include <stdio.h>
    int po[10];
    int dig(int n)
    {
        int co = 0;
        while(1)
        {
            co+=1;
            n/=10;
            if(n==0)break;
        }
        return co;
    }
    int pre[10000005];
    int dif(int a, int b)
    {
        int ans = 0;
        while(1)
        {
            if(a%10 != b%10)ans++;
            a/=10;
            b/=10;
            if(b==0)break;
        }
        return ans;
    }
    int main()
    {
        int n,k,q;
        po[0] = 1;
        for(n=1;n<=9;n++)po[n] = 10*po[n-1];
        scanf("%d%d%d",&n,&k,&q);
        int di = dig(n);
        int st = po[di-1];
        int en = po[di];
        int m;
       // printf("%d %d\n",st,en);
       st = 1;
        for(m=st;m<en;m++)
        {
            if(dif(m,n)<=k)
            pre[m] = 1;
            pre[m]+= pre[m-1];
        }
        for(;m<=10000000;m++)
        pre[m]+= pre[m-1];
        int l,r;
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",pre[r]-pre[l-1]);
        }
        return 0;
    }

#Another solution in C

    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
     
    int max_reach(int n){
        int digits = floor(log(n)/log(10))+1;
        switch(digits){
            case 1: return 9;
            case 2: return 99;
            case 3: return 999;
            case 4: return 9999;
            case 5: return 99999;
            case 6: return 999999;
            case 7: return 9999999;
        }
    }
     
    int is_reachable(int i,int n,int k){
        int ctr = 0;
        while(n!=0){
            int rem_n=n%10;
            int rem_i=i%10;
            if(rem_n!=rem_i) ctr++;
            n=n/10;
            i=i/10;
        }
        return ctr<=k;
    }
     
    int main()
    {
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        int max = max_reach(n);
        //printf("%d\n",max);
        int * ctr = malloc((max+1)*sizeof(int));
        ctr[0] = is_reachable(0,n,k);
        for(int i=1;i<=max;i++){
            if(is_reachable(i,n,k)) ctr[i] = ctr[i-1]+1;
            else ctr[i] = ctr[i-1];
            //printf("%d ",ctr[i]);
        }
       // printf("\n");
        int a,b;
        for(int i=0;i<q;i++){
            scanf("%d%d",&a,&b);
            if(a>max) {
                printf("0\n");
                continue;
            }
            if(a<=max && b>max) b=max;
            printf("%d\n",is_reachable(a,n,k)+ctr[b]-ctr[a]);
        }
        return 0;
    }

#Almost all the accepted solutions are in C++ language I don't know why
#Below is the code in C++
# Try to understand the logic of solutions of both the languages

#Solution in C++
    #include<iostream>
    #include<algorithm>
    #include<memory.h>
    #include<math.h>
    #include<stdio.h>
    #include<string>
    #include<vector>
    #include<bitset>
    #include<climits>
    #include<list>
    #include<set>
    #include<fstream>
     
    #define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
    #define rrep(i, a, b) for (int i = (a), i##_end_ = (b); i >= i##_end_; --i)
    #define vi vector<int>
    #define pii pair<int,int>
    #define pis pair<int,string>
    #define pss pair<string,string>
    #define pb push_back
    #define mp make_pair
     
    using namespace std;
     
    typedef long long int lli;
    typedef unsigned long long int ulli;
    typedef long double ld;
     
    lli t,n,k,q,l,r;
     
    lli a[10000005]={0};
     
    void precompute(){
     
        int totaldigi=0;
        lli temp=n;
        int digits[10];
        rep(i,0,10)
        digits[i]=-1;
     
        while(temp!=0)
        {
            digits[totaldigi]=(temp%10);
            totaldigi++;
            temp/=10;
        }
        lli cnt,posi,flag,total;
        rep(i,1,10000005)
        {
            temp=i;
            cnt=0;
            posi=0;
            flag=0;
            total = 0;
            
            while(temp!=0)
            {
               total++;
               temp/=10;
            }
            
            if(total<totaldigi)
              total = totaldigi;
              
            temp=i;  
            
            while(total!=0)
            {
                if(digits[posi]==-1)
                {
                     flag=1;
                     break;
                }
                if((temp%10)==digits[posi])
                    cnt++;
                temp/=10;
                posi++;
                total--;
                
            }
     
     
            if((totaldigi-cnt)<=k && flag!=1 )
                a[i]=1;
     
             a[i]+=a[i-1];
        }
       // rep(i,0,16)
        //  cout << ans[i] <>;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
     
       
            cin >> n >> k >> q;
     
            precompute();
     
            while(q--)
            {
                cin >> l >> r;
     
               // rep(i,l,r+1)
     
                cout << a[r]-a[l-1] << "\n";
            }
     
        
     
     
        return 0;
    }


#Solution in C++14

    /*
    * C++11 code template for contests.
    * @author: Andrei Kalendarov
    * @e-mail: andreykalendarov@gmail.com
    */
     
    //#define ANDREIKKAA_ALLOCATOR
    const int _ML = 228;
    #pragma GCC optimize("O3,no-stack-protector")
    #include <bits/stdc++.h>
    #define endl '\n'
    #define x first
    #define y second
    using namespace std;
    #define rand abcdefghijklmnopqrstuvwxyz
    #define random_shuffle abcdefghijklmnopqrstuvwxyz
    #define all(x) (x).begin(), (x).end()
    #define sz(x) (int)(x).size()
    using ll = int64_t;
    using ull = uint64_t;
    using ld = double;
    const ld PI = 3.14159265358979323846;
    mt19937 rd(228);
    #if defined(ANDREIKKAA_ALLOCATOR)
    char _mem[_ML * 1024 * 1024];
    size_t _ptr = 0;
    inline void* operator new (size_t _x) { _ptr += _x; assert(_ptr < _ML * 1024 * 1024); return _mem + _ptr - _x; }
    inline void operator delete (void*) { }
    #endif
    template<class T, class U> inline ostream &operator<< (ostream &, const pair<T, U> &);
    template<class T, class U> inline istream &operator>> (istream &, pair<T, U> &);
    template<class T> inline ostream &operator<< (ostream &, const vector<T> &);
    template<class T> inline istream &operator>> (istream &, vector<T> &);
    template<class T> inline ostream &operator<< (ostream &, const set<T> &);
    template<class T> inline ostream &operator<< (ostream &, const multiset<T> &);
    template<class T> inline ostream &operator<< (ostream &, const unordered_set<T> &);
    template<class T> inline ostream &operator<< (ostream &, const unordered_multiset<T> &);
    template<class T, class U> inline ostream &operator<< (ostream &, const map<T, U> &);
    template<class T, class U> inline ostream &operator<< (ostream &, const unordered_map<T, U> &);
     
    /* ________ CODE ________ */
     
    int TO;
    int K;
    string s;
     
    vector<int> vals;
     
    void gen(int p, int cc) {
        //cout << p << " " << cc << " " << lst << endl;
        if(cc <= K) {
            vals.push_back(stoi(s));
        }
        if(cc == K) {
            return;
        }
        
        if(p == TO) {
            return;
        }
        
        gen(p + 1, cc);
        for(char i = '0'; i < '9' + 1; ++i) {
            if(s[p] == i) {
                continue;
            }
            char c = s[p];
            s[p] = i;
            gen(p + 1, cc + 1);
            s[p] = c;
        }
    }
     
    void solve(int hui) {
        int k, q;
        cin >> s >> k >> q;
        k = min(k, sz(s));
        K = k;
        TO = sz(s);
        gen(0, 0);
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        
        //cout << vals << endl;
        
        for(int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            
            int pr = upper_bound(all(vals), r) - vals.begin();
            int pl = lower_bound(all(vals), l) - vals.begin();
            cout << pr - pl << endl;
        }
    }
     
    inline void _main_function() {
        
        
        int t = 1;
        //cin >> t;
        for(int i = 1; i <= t; ++i) {
            solve(i);
        }
    }
     
    /* ________ CODE ________ */
     
    int main() {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        cout << setprecision(20);
        //cout << fixed;
     
        _main_function();
    }
     
    template<class T, class U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) {
        _out << _p.x << ' ' << _p.y;
        return _out;
    }
    template<class T, class U> inline istream &operator>> (istream &_in, pair<T, U> &_p) {
        _in >> _p.x >> _p.y;
        return _in;
    }
    template<class T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) {
        if (_v.empty()) { return _out; }
        _out << *_v.begin();
        for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
        return _out;
    }
    template<class T> inline istream &operator>> (istream &_in, vector<T> &_v) {
        for (auto &_i : _v) { _in >> _i; }
        return _in;
    }
    template<class T> inline ostream &operator<< (ostream &_out, const set<T> &_s) {
        if (_s.empty()) { return _out; }
        _out << *_s.begin();
        for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
        return _out;
    }
    template<class T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) {
        if (_s.empty()) { return _out; }
        _out << *_s.begin();
        for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
        return _out;
    }
    template<class T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) {
        if (_s.empty()) { return _out; }
        _out << *_s.begin();
        for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
        return _out;
    }
    template<class T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) {
        if (_s.empty()) { return _out; }
        _out << *_s.begin();
        for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
        return _out;
    }
    template<class T, class U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) {
        if (_m.empty()) { return _out; }
        _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
        for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
        return _out;
    }
    template<class T, class U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) {
        if (_m.empty()) { return _out; }
        _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
        for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
        return _out;
    }


#Solution in Java 8 which got completely accepted by the HackerEarth
#Not to be afraid by seeing the code cause it is bit lengthy

        import java.io.IOException;
        import java.io.InputStream;
        import java.io.PrintWriter;
        import java.io.*;
        import java.util.*;
        import java.util.LinkedList;
        import java.math.*;
        import java.lang.*;
        import java.util.PriorityQueue;
        import static java.lang.Math.*;
        @SuppressWarnings("unchecked")
        public class Solution implements Runnable {
            static class InputReader {
                private InputStream stream;
                private byte[] buf = new byte[1024];
                private int curChar;
                private int numChars;
                private SpaceCharFilter filter;
                private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     
                public InputReader(InputStream stream) {
                    this.stream = stream;
                }
     
                public int read() {
                    if (numChars==-1)
                        throw new InputMismatchException();
     
                    if (curChar >= numChars) {
                        curChar = 0;
                        try {
                            numChars = stream.read(buf);
                        }
                        catch (IOException e) {
                            throw new InputMismatchException();
                        }
     
                        if(numChars <= 0)
                            return -1;
                    }
                    return buf[curChar++];
                }
     
                public String nextLine() {
                    String str = "";
                    try {
                        str = br.readLine();
                    }
                    catch (IOException e) {
                        e.printStackTrace();
                    }
                    return str;
                }
                public int nextInt() {
                    int c = read();
     
                    while(isSpaceChar(c))
                        c = read();
     
                    int sgn = 1;
     
                    if (c == '-') {
                        sgn = -1;
                        c = read();
                    }
     
                    int res = 0;
                    do {
                        if(c<'0'||c>'9')
                            throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = read();
                    }
                    while (!isSpaceChar(c));
     
                    return res * sgn;
                }
     
                public long nextLong() {
                    int c = read();
                    while (isSpaceChar(c))
                        c = read();
                    int sgn = 1;
                    if (c == '-') {
                        sgn = -1;
                        c = read();
                    }
                    long res = 0;
     
                    do {
                        if (c < '0' || c > '9')
                            throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = read();
                    }
                    while (!isSpaceChar(c));
                        return res * sgn;
                }
     
                public double nextDouble() {
                    int c = read();
                    while (isSpaceChar(c))
                        c = read();
                    int sgn = 1;
                    if (c == '-') {
                        sgn = -1;
                        c = read();
                    }
                    double res = 0;
                    while (!isSpaceChar(c) && c != '.') {
                        if (c == 'e' || c == 'E')
                            return res * Math.pow(10, nextInt());
                        if (c < '0' || c > '9')
                            throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = read();
                    }
                    if (c == '.') {
                        c = read();
                        double m = 1;
                        while (!isSpaceChar(c)) {
                            if (c == 'e' || c == 'E')
                                return res * Math.pow(10, nextInt());
                            if (c < '0' || c > '9')
                                throw new InputMismatchException();
                            m /= 10;
                            res += (c - '0') * m;
                            c = read();
                        }
                    }
                    return res * sgn;
                }
     
                public String readString() {
                    int c = read();
                    while (isSpaceChar(c))
                        c = read();
                    StringBuilder res = new StringBuilder();
                    do {
                        res.appendCodePoint(c);
                        c = read();
                    }
                    while (!isSpaceChar(c));
     
                    return res.toString();
                }
     
                public boolean isSpaceChar(int c) {
                    if (filter != null)
                        return filter.isSpaceChar(c);
                    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
                }
     
                public String next() {
                    return readString();
                }
     
                public interface SpaceCharFilter {
                    public boolean isSpaceChar(int ch);
                }
            }
            public static long min(long a,long b)
            {
                if(a>b)
                {
                    return b;
                }
                return a;
            }
            public static int min(int a,int b)
            {
                if(a>b)
                {
                    return b;
                }
                return a;
            }
            public static long max(long a,long b)
            {
                if(a>b)
                {
                    return a;
                }
                return b;
            }
            public static int max(int a,int b)
            {
                if(a>b)
                {
                    return a;
                }
                return b;
            }
            static class pair implements Comparable<pair>
            {
              int x;
              int y;
              pair(int x,int y)
              {
                this.x = x;
                this.y = y;
              }
              public int compareTo(pair b)
              {
                if(this.x>b.x)
                {
                  return 1;
                }
                else if(this.x<b.x)
                {
                  return -1;
                }
                else
                {
                  return this.y-b.y;
                }
              }
            }
            public static int gcd(int a,int b)
            {
                if(a==0)
                return b;
                if(b==0)
                return a;
                while((a%=b)!=0&&(b%=a)!=0);
                return a^b;
            }
            public static int mod(int a)
            {
              if(a>0)
                return a;
              return -a;
            }
            static int mod = (int)1e9+7;;
            public static long expo(long exp,long pow)
            {
              long ans = 1;
              while(pow!=0)
              {
                if((pow&1)==1)
                {
                  ans = ans*exp;
                }
                exp = exp*exp;
                pow = pow>>1;
              }
              return ans;
            }
            static int max = (int)1e9;
            public static long fact(int num)
            {
                if(num==0)
                {
                  return 1;
                }
                return (fact(num-1)*num)%mod;
            }
            static int[] sieve;
            public static ArrayList<Integer> sieve()
            {
              sieve = new int[51];
              ArrayList<Integer> list = new ArrayList<>();
              for(int i=1;i<=50;i++)
              {
                sieve[i] = i;
              }
              for(int i=2;i<=50;i++)
              {
                if(sieve[i]==i)
                {
                  for(int j=i*2;j<=50;j+=i)
                  {
                    if(sieve[j]==j)
                    {
                      sieve[j] = i;
                    }
                  }
                }
              }
              for(int i=2;i<=50;i++)
              {
                if(sieve[i]==i)
                {
                  list.add(i);
                }
              }
              return list;
            }
            public static int bsearch(long[] a,long val)
            {
              int l = 0;
              int r = a.length-1;
              while(l<r)
              {
                int mid = (l+r+1)>>1;
                if(a[mid]<=val)
                {
                  l = mid;
                }
                else
                {
                   r = mid-1;
                }
              }
              if(a[l]<=val)
              {
                return l+1;
              }
              return 0;
            }
            public static int check(int n,int c,int k)
            {
              int k1 = 0;
              while(c!=0&&n!=0){
                if(c%10!=n%10)
                {
                  k1++;
                }
                c/=10;
                n/=10;
              }
              while(n!=0)
              {
                if(n%10!=0)
                {
                  k1++;
                }
                n/=10;
              }
              if(c==0&&k1<=k)
              {
                return 1;
              }
              return 0;
            }
            public static void main(String args[]) throws Exception {
                new Thread(null, new Solution(),"Main",1<<26).start();
            }
            public void run() {
              InputReader sc  = new InputReader(System.in);
              PrintWriter out = new PrintWriter(System.out);
              int n = sc.nextInt();
              int k = sc.nextInt();
              int[] ans = new int[(int)1e7+1];
              for(int i=1;i<=(int)1e7;i++)
              {
                ans[i]+=check(n,i,k);
              }
              for(int i=1;i<=(int)1e7;i++)
              {
                ans[i]+=ans[i-1];
              }
              int t1 = sc.nextInt();
              while(t1-->0)
              {
                int l = sc.nextInt();
                int r = sc.nextInt();
                out.println(ans[r]-ans[l-1]);
              }
              out.close();
             }
        }



