#include<bits/stdc++.h>
using namespace std;
 
void solve() {
    
    int n;
    cin >> n;
    
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];
    
    for(int i = 1; i < n; i++) {
        if(array[i] % array[0] != 0){
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}
 
int main() {
    
    int test;
    cin >> test;
    
    while(test--){
        solve();
    }
}
