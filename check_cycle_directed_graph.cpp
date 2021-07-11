#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool cycle(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& dfsvis) {
    visited[node] = true;
    dfsvis[node] = true;

    for(int it: adj[node] ){
        if (!visited[it]){
            if (cycle(it, adj, visited, dfsvis)){
                return true;
            }
        }
        else if (dfsvis[it]){
            return true;
        }
    }

    dfsvis[node] = false;
    return false;
}

bool is_cycle(int nodes, int edges, vector<int> adj[]) {

    vector<bool> visited(nodes + 1), dfsvis(nodes+1);

    for(int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            // if any thing returns true return true
            if( cycle(i, adj, visited, dfsvis)) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];
    for(int i = 0; i < edges; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    cout << is_cycle(nodes, edges, adj) << endl;
}