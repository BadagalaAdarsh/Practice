#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    // for 1 based indexing
    vector<vector<bool>> adj_matrix(nodes+1, vector<bool>(nodes+1));

    for(int i = 0; i < edges; i++) {
        int u,v ;
        cin >> u >> v;

        adj_matrix[u][v] = true;
        adj_matrix[v][u] = true;
    }
}