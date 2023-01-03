#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

int main() {

    ll n;
    cin >> n;

    ll answer = 1;
    ll power = 2;

    // binomial exponential to calculate power
    while(n) {
        if (n%2 == 1) 
            answer = ( (answer % MOD) * (power % MOD))% MOD;
        

        n = n >> 1;
        power = ((power%MOD) * (power%MOD) % MOD);
    }

        
    cout << answer;
}