#include<bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

/*
I would like to explain what I did to solve this briefly. Firstly notice that any four consecutive natural numbers can be split into two sets with equal sums Example: If my starting number is say x, and I consider 4 consecutive numbers then sum(x, x + 3) = sum(x + 1, x +2).

So if n is divisible by 4 you can group them using the above approach by considering the remainders.

Suppose n when divided by 4 leaves remainder 3. 
Even then we should be able to divide into two sets since three numbers (x + 1, x + 2, x + 3) 
such that x is divisible by 4 contain two additional odd numbers (x + 1, x + 3) 
(x is even since it is divisible by 4). Another point to notice is that 1+2 = 3 is the only triplet 
(x, x+1, x+2) such that two elements add up to third. So start with sets A = {1, 2} B = {3}. 
Since n % 4 = 3, count of remaining numbers is divisible by 4. So now apply the first property 
that given 4 numbers x, x + 1, x + 2, x + 3, sum of the numbers in the middle is equal to that of 
those at the extremities.

Hope you have a good time solving the problemset.

*/

int main() {

    ll n;
    cin >> n;

    // if sum is odd its not possible
    if ( n*(n+1)/2 %2 ) {
        cout << "NO" ;
        return 0;
    }

    if (n == 3){
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << endl;
        cout << 3 ;
        return 0;
    }

    vector<int> set1, set2;
    int j = 0;

    if (n%4 != 0) 
        j = 3;
    else 
        j = 4;

    int start;

    if (n%4 == 0){
        set1.push_back(1);
        set1.push_back(4);
        
        set2.push_back(2);
        set2.push_back(3);

        start = 5;
    }
    else{
        set1.push_back(1);
        set1.push_back(2);

        set2.push_back(3);
        start = 4;
    }

    for(int i = start; i <= n; i += 4) {
        set1.push_back(i);
        
        set2.push_back(i+1);
        set2.push_back(i+2);

        set1.push_back(i+3);
    }

    cout << "YES" << endl;
    cout << set1.size() << endl;

    for(int i = 0; i < (int)set1.size(); i++){
        cout << set1[i] << " ";
    }

    cout << endl;

    cout << set2.size() << endl;
    for(int i = 0; i < (int)set2.size(); i++) {
        cout << set2[i] << " ";
    }

}




/*

brute force logic

void solve(ll n) {
    ll temp = n * (n + 1) / 2);
    if (temp % 2 == 1) {
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;

    ll target = temp/2;
    ll sum = 0;
    ll i = n;

    unordered_set<ll> s;
    s.reserve(n); // to reserve space for n elements

    while(sum < target) {
        s.insert(i);
        sum += i;
        i--;
    }

    if (sum > target) {

        sum -= (i + 1);

        assert(sum < target);

        s.erase(s.find(i+1));

        s.insert(target-sum);
    }

    cout << s.size() << "\n";

    for(auto element: s) {
        cout << element << " ";
    }
    cout << endl;

    cout << n - s.size() << endl;

    for(int j = 1; j <= n; j++) {
        if (s.find(j) == s.end()) {
            cout << j << " ";
        }
    }
}
        


*/
    
