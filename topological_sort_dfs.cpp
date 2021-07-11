#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void findtoposort(int node, vector<bool>& visited, vector<int> adj[], stack<int>& s) {

    visited[node] = true;
    for(auto it: adj[node]) {
        if ( !visited[node]) {
            findtoposort(it, visited, adj, s);
        }
    }
    s.push(node);
}

vector<int> toposort(int nodes, int edges, vector<int> adj[]) {
    stack<int> s;
    vector<bool> visited(nodes + 1);
    
    for(int i = 1; i <= nodes; i++) {
        if ( !visited[i]) {
            findtoposort(i, visited, adj, s);
        }
    }
    vector<int> answer;
    while( !s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    return answer;
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
    }

    vector<int> answer;
    answer = toposort(nodes,edges, adj);

    for(auto i: answer) {
        cout << i << " ";
    }
}