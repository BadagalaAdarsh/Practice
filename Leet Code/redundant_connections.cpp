#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int findparent(int node, vector<int>& parent) {
    while(parent[node] != node) {
        node = parent[node];
    }
    
    return node;
}

void union_both(int i , int j, vector<int>& parent) {
    int iroot = findparent(i, parent);
    int jroot = findparent(j, parent);
    
    if (iroot != jroot) {
        parent[jroot] = iroot;
    }
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    
    vector<int> parent(n+1);
    
    for(int i = 0; i < n+1; i++) {
        parent[i] = i;
    }
    
    for(auto i: edges) {
        if(findparent(i[0], parent) == findparent(i[1], parent)) {
            return {i[0], i[1]};
        }
        union_both(i[0], i[1], parent);
    }
    
    // assuming all the cases are true the code never reaches the below return statement
    return {0, 0};
    
}

// rest of the main function

