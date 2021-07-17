#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool is_cycle(int nodes, int edges, vector<int> adj[]) {
    // if we cannot generate a topological sort using BFS or khans algorithm then
    // the graph will surely have a cycle
    // so we just need to modify the khans algorithm a bit to detect a cycle

    vector<int> indegree(nodes);
    queue<int> q;

    for(int i = 0; i < nodes; i++) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }

    for(int i = 0; i < nodes; i++) {
        if (indegree[i] == 0){
            q.push(i);
        }
    }

    // maintain counter for no of nodes popped
    // if there are no cycle then all the nodes are pushed and popped out of queue
    // then count should be equal to no of nodes 

    int count = 0;
    while(!q.empty()){

        int node = q.front();
        q.pop();
        count++;

        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if (count == nodes) return false; // no cycle
    return true;
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

    cout << is_cycle(nodes, edges, adj) << endl;

}