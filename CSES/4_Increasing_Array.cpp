#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n;
    cin >> n;

    int maxSoFar = 0;
    ll ans = 0;

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        maxSoFar = max(x, maxSoFar);
        ans += maxSoFar - x;
    }

    cout << ans ;
}