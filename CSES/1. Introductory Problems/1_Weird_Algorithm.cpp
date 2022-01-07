#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ll n;
    cin >> n;

    cout << n;

    while( n > 1) {
        if(n%2 == 0)
            n /= 2;
        else
            n = 3*n + 1;
        cout << " " << n;
    }
}