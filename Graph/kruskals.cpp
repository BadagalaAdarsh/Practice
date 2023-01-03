#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// user define structure to store the node
struct node {
    int u;
    int v;
    int wt;

    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

// used for sorting based on the weights
bool comp(node a, node b) {
    return a.wt < b.wt;
}

int findparent(int u, vector<int>& parent) {
    if(u == parent[u]) return u;
    return findparent(parent[u], parent);
}

void make_union(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findparent(u, parent);
    v = findparent(v, parent);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // for kruskals algorithm i am not using adjacency list 
    // for storing the data i am going to use another data structure
    // as we need to sort the edges based on weight it may be difficult for us
    // to do that using the adjacency list

    // i am going to use the disjoint set operations here
    // find parent and rank one to implement the kruskals algorithm

    int nodes, edges;
    cin >> nodes >> edges;

    vector<node> adj;

    for(int i = 0; i < edges; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj.emplace_back(u, v, wt);
    }

    // sorting the adj vector based on the weights
    sort(adj.begin(), adj.end(), comp);

    // parent vector for storing the parent
    vector<int> parent(nodes);

    // initializing  them such that parent of i is i itself
    for(int i = 0; i < nodes; i++) 
        parent[i] = i;

    // rank array which store the rank of the current node which is the max level of the node
    vector<int> rank(nodes, 0 );

    int cost = 0; // used to store the final cost of the mst (minimum spanning tree) that is formed at the end
    vector<pair<int, int>> mst;

    for(auto it: adj) {
        if (findparent(it.v, parent) != findparent(it.u, parent)) {
            cost += it.wt;
            mst.emplace_back(it.u, it.v);
            make_union(it.u, it.v, parent, rank);
        }
    }

    cout << "final cost of the mst is" << cost << endl;

    cout << "final mst tree is " << endl;
    for(auto it: mst) cout << it.first << "--" << it.second << endl;
}