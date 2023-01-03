#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj_list[nodes+1];

    for(int i = 0; i < edges; i++) {
        int u,v ;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // for weighter graphs
    vector<pair<int,int>> list[nodes + 1];
    for(int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        list[u].push_back({v, weight});
        list[v].push_back({u, weight});
    }

}