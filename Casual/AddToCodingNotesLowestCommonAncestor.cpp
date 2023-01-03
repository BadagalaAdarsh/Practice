#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX_N = 10000;
const int LOG = 20;
vector<int> children[MAX_N]; // look closely at the syntax it used to represent the 
                             // array of vectors instead of vector of vectors
// here children.push_back is not possible because it is array
// but childer[i].push_back is possible becaues it is a vector
// understand that it array of vectors not vector of vectors
int up[MAX_N][LOG];
int depth[MAX_N];

void dfs(int a) {

    for(int b: children[a]){
        up[b][0] = a;
        depth[b] = depth[a] + 1;
        for(int j = 1; j < LOG; j++) {
            up[b][j] = up[ up[b][j-1] ][j-1];
        }
        dfs(b);
    }
}

int get_lca(int a, int b) {

    if (depth[a] < depth[b]){
        swap(a,b);
    }

    // instead of moving by 1 to make depth equal
    // use binary lifting to move faster
    // for this we need by how many steps we need to move

    int k = depth[a] - depth[b];
    for(int  j = LOG - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }

    if (a == b) {
        return a; // this is because at last we return parent of either which will be wrong
                 // this is the case when both are on the same branch
    }

    for(int j = LOG - 1; j >= 0; j--) {
        // this part always leaves us at the children of lowest common ancestor
        // as we are moving in reverse order of 2 powers it makes our node move closer to the lca
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0]; // we can do the same with up[b][0]
    
}


int get_lca_linear(int a,int b) {

    if ( depth[a] < depth[b]) {
        swap(a,b);
    }

    while(depth[a] > depth[b]){
        // moving up by one position till both are having the same depth
        a = up[a][0];
    }

    while (a != b) {
        a = up[a][0];
        b = up[b][0];
    }

    return a; 
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int v = 0; v < n; v++) {
        // read children of v
        int cnt;
        cin >> cnt;

        for(int i = 0; i < cnt; i++) {
            int c;
            cin >> c;
            children[v].push_back(c);
        }

    }

    dfs(0);

    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << endl;
    }
}