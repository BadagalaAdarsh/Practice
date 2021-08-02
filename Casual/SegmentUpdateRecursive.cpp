#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<long long> tree;

long long int f(int node, int node_low, int node_high, int query_low, int query_high) {
    
    if(query_low <= node_low && node_high <= query_high){
	return tree[node];
    }

    if(node_high < query_low || query_high < node_low ) {
	return 0;
    }

    int last_in_left = (node_low + node_high) / 2;
    return f(2 * node, node_low, last_in_left, query_low, query_high)
	+  f(2 * node + 1, last_in_left + 1, node_high, query_low, query_high);
}

void change(int node, int node_low, int node_high, int query_low, int query_high, int v) { // recursive version
    if( query_low <= node_low && node_high <= query_high) {
	tree[node] = v;
	return ;
    }

    if (node_high < query_low || query_high < node_low ) {
	return ;
    }

    int last_in_left = (node_low + node_high) / 2;
    change(2*node, node_low, last_in_left, query_low, query_high, v);
    change(2*node+1, last_in_left + 1, node_high, query_low, query_high, v);
    tree[node] = tree[2*node] + tree[2*node+1];
}

/*
void update(int i, int v, int n){
    tree[n+i] = v;
    for(int j = (n+i)/2; j >= 1; j/=2 ) {
	tree[j] = tree[2*j] + tree[2*j+1];
    }
}
*/

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];

    // while n is not a power of 2 
    while(__builtin_popcount(n) != 1 ) {
	array.push_back(0);
	n++;
    }

    tree.resize(2 * n);
    // fill tree in last as they are just the leaf nodes
    for(int i = 0; i < n; i++) {
	tree[n + i] = array[i];
    }
    // go from last unfilled position to 1
    for(int i = n - 1; i > 0; i--) {
	tree[i] = tree[2*i] + tree[2 * i + 1];
    } 
    
    while(q--){
	int type;
	cin >> type;

	if(type == 1) { // update
	    int i,v;
	    cin >> i >> v;
	    i--;
	    change(1, 0, n-1, i, i, v);
	}
	else { // sum query
	    int a, b;
	    cin >> a >> b;
	    a--;
	    b--;

	    cout << f(1, 0, n-1, a, b) << endl;
	}
    }
} 
