#include<bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)


void solve(){
    int n, k;
    cin >> n >> k;
    map<int, pair<int, int>>m;
    forn(i, n){
        int u;
        cin >> u;
        if(!m.count(u)) {
            m[u].first = i;
            m[u].second = i;
        }
        else m[u].second = i;
    }
    forn(i, k){
        int a, b;
        cin >> a >> b;
        if(!m.count(a) or !m.count(b) or m[a].first > m[b].second) {
            cout << "NO\n"; //equals = 0 = wrong
        }
        else cout << "YES\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
