#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool check_cycle(int node, int parent, vector<int> adj[], vector<bool>& visited) {

    visited[node] = true;
    
    for(auto it: adj[node]){
        if ( !visited[it] ) {
            if( check_cycle( it, node, adj, visited)) return true;
        }
        // if visited node is not parent then there is a cycle in the graph
        else if ( it != parent) {
            return true;
        }
    }

    return false;
}

bool detect_cycle(int nodes, int edges, vector<int> adj[]) {

    vector<bool> visited(nodes + 1);

    for(int i = 1; i <= nodes; i++) {
        if (!visited[i] ) {
            if (check_cycle(i, -1, adj, visited ) ) {
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

    for(int i = 0 ; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << detect_cycle(nodes, edges, adj ) << endl;
}