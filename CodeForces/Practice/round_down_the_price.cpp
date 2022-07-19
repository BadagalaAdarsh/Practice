#include<bits/stdc++.h>
using namespace std;

void solve() {
    
    long long base = 1;
    long long num;
    cin >> num;
    
    while(base <= num){
        base *= 10;
    }
    base /= 10;
    
    cout << num - base << endl;
}

int main() {
    
    int test;
    cin >> test;
    
    while(test--) {
        solve();
    }
}
