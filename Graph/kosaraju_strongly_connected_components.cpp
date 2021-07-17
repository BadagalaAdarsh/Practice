// this algorithms is used to find the strongly connected components in the directed graph
// strongly connected component is a component where if we start from any node we can reach 
// any other node in that component

// kosaraju's algorithm has mainly three parts
// for sort the graph in topological manner
// which means do dfs for every node and once the dfs for that node is completed push it into stack

// next step is to transpose the graph which means all the edges will get reveresed
// this is done so that unneccesary traversals of nodes can be avoided while doing the dfs

// next do the dfs according to the finishing time on the trasnposed graph


#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void dfs(int node, stack<int>& s, vector<bool>& visited, vector<int> adj[]) {
    visited[node] = true;

    for(auto it: adj[node]) {
        if (!visited[it]) {
            dfs(it, s, visited, adj);
        }
    }
    s.push(node);
}

void revdfs(int node, vector<bool>& visited, vector<int> transpose[] ) {
    cout << node << " ";
    visited[node] = true;

    for(auto it: transpose[node] ) {
        if (!visited[it] ) {
            revdfs(it ,visited, transpose);
        }
    }
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
    }

    stack<int> s;
    vector<bool> visited(nodes);
    
    for(int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i, s, visited, adj);
        }
    }

    vector<int> transpose[nodes];

    for(int i = 0; i < nodes; i++) {
        visited[i] = false;
        for(auto it: adj[i] ) {
            transpose[it].push_back(i);
        }
    }

    while ( !s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node] ) {
            cout << "strongly connected components are" << endl;
            revdfs(node, visited, transpose);
            cout << endl;
        }
    }
}