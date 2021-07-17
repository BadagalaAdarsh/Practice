#include<bits/stdc++.h>
#define endl "\n"
using namespace std;


// this is the brute approach
int findparent(int node, int parent[]) {
    if (node == parent[node]) {
        return node;
    }

    // recursively calling the same function by passing parent of current node 
    // to find the ultimate parent
    return findparent(parent[node], parent);
}


// path compressed format where say we have graph such that 1 - 2 - 3
// brute approach will first find parent of 3 which is 2 and then 2 is passed again to the function
// which will return 1 and again function is called by 1 now as node 1 and parent of 1 is same we finally return 1 as 
// ultimate parent of 3 but if the tree is long and we need to call the parent of 3 number of times then this is slow
// we can speed this updating the parent of 3 as 1 once we find the ultimate parent once
//  now the tree looks like this
//      1
//     / \
//    2   3
// this algo is implemented in the below function

int findparentpathcompressed(int node, int parent[] ) {
    if (node == parent[node]) {
        return node;
    }

    return parent[node] = findparentpathcompressed(parent[node], parent);
}

void make_union(int u, int v, int parent[], int rank[] ) {
    // find parent of both
    u = findparentpathcompressed(u, parent);
    v = findparentpathcompressed(v, parent);

    //  compare rank and add the new node to the node with smaller rank
    // if the rank is ame we can add to any one
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[v] < rank[u] ) {
        parent[v] = u;
    }

    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes;
    cin >> nodes;

    int parent[nodes];
    int rank[nodes];

    // initially rank of every node is 0 and parent of each node is the node itself
    for(int i = 0; i < nodes; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // call the respective above function based on the question

    // example check is two nodes belong to same component or not
    int u, v;
    cin >> u >> v;
    if ( findparent(u, parent) != findparent(v, parent)) { // do not use the parent array as it may not give the ultimate parent always in the 
                                         // first call
        cout << "different components" << endl;
    }
    else {
        cout << "same component" << endl;
    }
}
