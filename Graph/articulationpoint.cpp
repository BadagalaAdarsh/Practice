// articulation points are the nodes on whose removal the graph changes to 2 or more components
// or the points which make the a single graph to multiple graph
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void dfs(int node, int parent, vector<bool>& visited, vector<int>& in_time, vector<int>& low_time, int &timer, vector<int> adj[], vector<int>& isarticulation) {

    visited[node] = true;
    in_time[node] = low_time[node] = timer++;

    int child = 0;

    for(auto it: adj[node] ) {
        if (it == parent) continue;

        if ( !visited[it] ) {
            dfs(it, node, visited, in_time, low_time, timer, adj, isarticulation);
            low_time[node] = min(low_time[node], low_time[it]);

            if (low_time[it] >= in_time[it] && parent == -1) {
                isarticulation[node] = 1;
            }
            child++;
        }
        else {
            low_time[node] = min(low_time[node], in_time[it]);
        }
    }

    if ( parent == -1 && child > 1) {
        isarticulation[node] = 1;
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
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> in_time(nodes, -1);
    vector<int> low_time(nodes, -1);
    vector<bool> visited(nodes); // default value is false;
    vector<int> isarticulation(nodes, 0);

    int timer = 0;

    for(int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, in_time, low_time, timer, adj, isarticulation);
        }
    }

    for(int i = 0; i < nodes; i++) {
        if (isarticulation[i] == 1) cout << i << endl;
    }
    return 0;
    
}
