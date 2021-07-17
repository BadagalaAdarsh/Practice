/*
pseudo code for binary lifting
int up[N][LOG] for n vertices we have upto logarithm (actually log of depth for simplicity lets say log of n)
up[v][j] tells us the 2^j th ancestor of v
 
for vertices = 0...N-1
    up[v][0] = parent[v] (v's first parent)
    for j = 0....LOG-1
        up[v][j] = up[ up[v][j-1] ][j-1] 

        dont forget to check this link https://www.youtube.com/watch?v=oib-XsjFa-M&t=9m0s
*/

#include<bits/stdc++.h>
using namespace std;

class TreeAncestor{
    vector<vector<int>> up; //to store parents
    vector<int> depth;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;

        while( (1 << LOG) <= n) {
            LOG++;
        }

        up = vector<vector<int>> (n, vector<int>(LOG));
        depth = vector<int>(n);

        parent[0] = 0;
        
        for(int v = 0; v < n; v++) {
            up[v][0] = parent[v];

            if (v!=0){
                depth[v] = depth[ parent[v] ] + 1;    
            }

            for(int j = 1; j < LOG; j++) {
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }

    int getKthAncestor(int node, int k) {

        if (k > depth[node]){
            return -1;
        }

        for(int j = 0; j < LOG; j++){
            if (k & (1 << j)) {
                node = up[node][j];
            }
        }

        return node;
    }
};


