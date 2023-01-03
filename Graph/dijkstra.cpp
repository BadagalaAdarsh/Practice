#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void shortestpath(int nodes, vector<pair<int,int>> adj[]) {
    
    vector<int> dist(nodes, INT_MAX);
    //priority_queue<pair<int,int>> q; // queue (min heap) dist, node as it should be ordered 
                                     // based on the distance not on the node
    // if we use above priority queue then we need to use -1 before inserting and using the value inorder to make it
    // min heap because by default priority queue in cpp is max heap
    // below syntax can be used to create the priority queue by default

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    // assuming source as 0
    int src = 0;
    dist[src] = 0;

    q.emplace(0, src);

    while( !q.empty() ) {
        int currnode = q.top().second;

        q.pop();

        vector<pair<int,int>>::iterator it;
        for(it = adj[currnode].begin(); it != adj[currnode].end(); it++) {
            // above loop can also be written as
            // for(auto it: adj[currnode]) {
                // int nextnode = it.first;
                // int nextdist = it.second;
            //}
            
            int nextnode = it->first;
            int nextdist = it->second;

            if( dist[nextnode] > dist[currnode] + nextdist ) {
                dist[nextnode] = dist[currnode] + nextdist;
                q.emplace(dist[nextnode], nextnode);
            }
        }
    }
    
    cout << "distance from source to every other node in the graph : " << endl;
    cout << src << " ";

    for(int i = 0; i < nodes; i++) {
        cout << dist[i] << " ";
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
        adj[v].emplace_back(u, weight);
    }

    shortestpath(nodes, adj);
}