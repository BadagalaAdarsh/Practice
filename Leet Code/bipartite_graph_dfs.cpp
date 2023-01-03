#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool dfs_bipartite(int node, vector<int> adj[], vector<int>& color) {

    for(auto it: adj[node]) {
        if ( color[it] == -1) {
            color[it] = 1 - color[node];
            if (!dfs_bipartite(it, adj, color)) {
                return false;
            }
        }
        else if (color[it] == color[node] ) {
            return false;
        }
    }
    return true;
}


bool check_bipartite(int nodes, int edges, vector<int> adj[] ) {

    vector<int> color(nodes + 1, -1);

    for(int i = 1; i <= nodes; i++) {
        if (color[i] == -1) {
            color[i] = 1;
            if ( !dfs_bipartite(i, adj, color)) {
                return false;
            }
        }
    }
    return true ;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << check_bipartite(nodes, edges, adj) << endl;
}
