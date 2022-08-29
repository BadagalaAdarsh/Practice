#include <bits/stdc++.h>
 
#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
typedef long double ld;
typedef long long ll;
 
using namespace std;
 
mt19937 rnd(143);
 
const int inf = 1e10;
const int M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> color(n, -1);
    deque<int> q;
    for(int i = 0; i < k; ++i){
        int x;
        cin >> x;
        color[--x] = 0;
        q.push_back(x);
    }
    color[0] = 1;
    q.push_back(0);
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(int u: g[v]){
            if(color[u] == -1){
                color[u] = color[v];
                q.push_back(u);
            }
        }
    }
    for(int v = 1; v < n; ++v){
        if(g[v].size() == 1 && color[v] == 1){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}
 
bool multi = true;
 
signed main() {
    int t = 1;
    if (multi) {
        cin >> t;
    }
    for (; t != 0; --t) {
        solve();
        cout << "\n";
    }
    return 0;
}
