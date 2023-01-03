#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool cycle(int i, vector<bool>& visited, vector<int> adj[]) {

    queue<pair<int,int>> q;

    visited[i] = true;
    q.push({i, -1});

    while(!q.empty()) {
        pair<int,int> node = q.front();
        q.pop();

        for(auto it: adj[node.first]){

            if(!visited[it]){
                visited[it] = true;
                q.push({it, node.first});
            }

            else if (node.second != it){
                return true;
            }
        }
    }
    return false;
}


bool is_cycle(int nodes, int edges, vector<int> adj[]){

    vector<bool> visited(nodes + 1);

    for(int i = 1 ; i < nodes; i++) {
        if(cycle(i, visited, adj)) {
            return true;
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
        int u, v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << is_cycle(nodes, edges, adj) << endl;
}