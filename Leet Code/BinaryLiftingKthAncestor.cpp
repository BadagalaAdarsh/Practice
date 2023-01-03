#include<bits/stdc++.h>
using namespace std;

class TreeAncestor{

    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent){
        LOG  = 0;
        while( (1 << LOG) <= n){
            LOG++;
        }

        up = vector<vector<int>>(n, vector<int>(LOG));
        depth = vector<int>(n);
        parent[0] = 0;

        for(int v = 0; v < n; v++){
            up[v][0] = parent[v];

            if(v !=  0){
                depth[v] = depth[parent[v]] + 1;
            }
            for(int j = 1; j < LOG; j++){
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }

    int getKthAncestor(int node, int k){
        if (depth[node] < k){
            return -1;
        }

        for(int j = 0; j < LOG; j++){
            if (k & (1 << j)){
                node = up[node][j];
            }
        }
        return node;
    }
};

int main(){
    int test;
    cin >> test;

    while(test--){
        // rest of the code to call the function and take the input
    }
}