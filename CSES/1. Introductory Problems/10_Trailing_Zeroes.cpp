#include<bits/stdc++.h>
#define ll long long

using namespace std; 

int main() {

    ll n;
    cin >> n;

    ll ans = 0;

    for(ll i = 5; i <= n; i *= 5) {
        ans += n/i;
    }

    /*
        other logic is
        while(n >= 5) {
            ans += n/5;
            n /= 5;
        }
    */

    cout << ans;
}