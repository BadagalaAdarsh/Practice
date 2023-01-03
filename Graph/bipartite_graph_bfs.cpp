// bipartite graph is a graph which can be coloured using only two colors such that no two 
// adjacent sides are having the same color

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool bipartite(int src, vector<int> adj[], vector<int>& color) {

    queue<int> q;
    q.push(src);

    color[src] = 1;

    while( !q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it: adj[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node] ){
                return false;
            }
        }
    }
    
    return true;
}

bool is_bipartitie(int nodes, int edges, vector<int> adj[] ) {

    vector<int> color(nodes + 1, -1 );

    for(int i = 1; i <= nodes; i++) {
        if (color[i] == -1) {
            if( !bipartite(i, adj, color)) {
                return false;
            }
        }
    }
    return true;

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

    cout << is_bipartitie(nodes, edges, adj) << endl;
}