#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> shortestPath(int nodes, int edges, vector<int> adj[] ) {

    vector<int> dist(nodes, INT_MAX);
    queue<int> q;

    // assuming source as node 0
    int src = 0;
    dist[src] = 0;

    q.push(src);

    while( !q.empty() ) {
        int node = q.front();
        q.pop();

        for(auto it: adj[node]) {
            if ( dist[node] + 1 < dist[it] ) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    return dist;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes];

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> answer = shortestPath(nodes, edges, adj);

    // answer contains shortest distance for every node from 0
    // here i have assumed source node as 0 node

    for(auto it: answer) {
        cout << it << " ";
    }
}
