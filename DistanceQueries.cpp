#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX_N = 200001;
const int LOG = 20;
int up[MAX_N][LOG];
int depth[MAX_N];
vector<int> edges[MAX_N];

void dfs(int a, int parent) {

    for(int b: edges[a]){ 
        
        if(b == parent) {
            continue;
        }
        depth[b] = depth[a] + 1;
        up[b][0] = a;

        for(int j = 1; j < LOG; j++) {
            up[b][j] = up[ up[b][j-1] ][j-1];
        }
        dfs(b, a);
    }
}

int get_lca(int a, int b) {

    if (depth[a] < depth[b]){
        swap(a,b);
    }

    int k = depth[a] - depth[b];
    for(int j = LOG -1; j >= 0; j--) {
        if (k & (1 << j)){
            a = up[a][j];
        }
    }

    if (a == b) {
        return a;
    }

    for(int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, -1);

    while(q--) {
        int a, b;
        cin >> a >> b;

        int lca = get_lca(a,b);
        int answer = depth[a] - depth[lca] + depth[b] - depth[lca];
        cout << answer << endl;
    }

}
