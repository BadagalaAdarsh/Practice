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
	int a, b;
	cin >> a >> b;
	a--;
	b--;

	cout << f(1, 0, n - 1, a, b) << endl;
    }
}
