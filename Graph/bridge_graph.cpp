// bridges in a graph are defined as the edges whose removal results in breaking of graph into
// 2 or more components
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void dfs(int node, int parent, vector<bool>&visited, vector<int>& in_time, vector<int>& low_time, int& timer, vector<int> adj[]) {

    visited[node] = true;
    in_time[node] = low_time[node] = timer++;
    
    for(auto it: adj[node]) {
        if (it == parent) continue;

        if( !visited[it]) {
            dfs(it, node, visited, in_time, low_time, timer, adj);
            low_time[node] = min(low_time[node], low_time[it]);

            if(low_time[it] > in_time[node]) {
                cout << "these are the part of the bridge";
                cout << node << "--" << it << endl;
            }
        }
        else {
            low_time[node] = min(low_time[node] , in_time[it]);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes,edges;
    cin >> nodes >> edges;

    vector<int> adj[edges];

    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> in_time(nodes, -1);
    vector<int> low_time(nodes, -1);
    vector<bool> visited(nodes);

    int timer = 0;

    // running dfs assuming that there are multiple components in the graph
    for(int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, in_time, low_time, timer, adj);
        }
    }