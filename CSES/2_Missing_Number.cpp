#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {

    ll n, sum = 0;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }

    cout << n*(n+1)/2 - sum ;
}