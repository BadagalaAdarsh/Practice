#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void findtoposort(int node, vector<bool>& visited, stack<int>& s, vector<pair<int,int>> adj[]){

    visited[node] = true;
    for(pair<int,int> it: adj[node]){

        if ( !visited[it.first]){
            findtoposort(it.first, visited, s, adj);
        }
    }
    s.push(node);
}

void shortestPath(int nodes, int edges, vector<pair<int,int>> adj[] ){

    vector<bool> visited(nodes);
    stack<int> s;

    for(int i = 0; i < nodes; i++) {
        if ( !visited[i] ){
            findtoposort(i, visited, s, adj);
        }
    }

    vector<int> dist(nodes, INT_MAX);
    // assuming source node is 0
    // can be changed as per the problem

    int src = 0;
    dist[src] = 0;

    while( !s.empty()) {
        int node = s.top();
        s.pop();

        if( dist[node] != INT_MAX) {
            for(auto it: adj[node] ) {
                if( dist[node] + it.second < dist[it.first] ) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for(int i = 0; i < nodes; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF" << " ";
        }
        else {
            cout << dist[i] << " ";
        }
    }
} 
 

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    vector<pair<int,int>> adj[nodes];

    for(int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].emplace_back(v,weight);
    }

    shortestPath(nodes, edges, adj);     
}