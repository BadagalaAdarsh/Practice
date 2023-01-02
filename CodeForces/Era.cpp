#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void solve() {
    
    int n;
    cin >> n;
    
    int array[n];
    for(int i = 0; i < n; i++) cin >> array[i];
    
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        answer = array[i] > (i+1) ? max(answer, array[i] - (i + 1)) : answer;
    }

    cout << answer << endl;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int test;
    cin >> test;
    
    while(test--){
        solve();
    }
}
