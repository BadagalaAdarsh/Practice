#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nodes, edges;
	cin >> nodes >> edges;
	
	vector<pair<int,int>> adj[nodes];
	
	for(int i = 0; i < edges; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		
		adj[u].emplace_back(v, wt);
		adj[v].emplace_back(u, wt);
	}
	
	int parent[nodes];
	int cost[nodes];
	bool mstset[nodes];
	
	for(int i = 0; i < nodes; i++) {
		cost[i] = INT_MAX;
		mstset[i] = false;
		parent[i] = -1;
	}
	
	// as we are starting from node 0 cost of node 0 is 0
	cost[0] = 0;
	
	// as we will have n - 1 edges in the minimum spanning tree
	// for loop is only upto n - 1
	
	for(int count = 0; count < nodes - 1; count++) {
		
		int mini = INT_MAX, u;
		
		for(int v = 0; v < nodes; v++) {
			// node is not a part of mst and cost is less than the current one
			if ( mstset[v] == false && cost[v] < mini ) {
				mini = cost[v], u = v;
			}
		}
		
		mstset[u] = true;
		
		for(auto it: adj[u]) {
			int v = it.first;
			int wt = it.second;
			
			if ( mstset[v] == false && wt < cost[v] ) {
				parent[v] = u, cost[v] = wt;
			}
		}
	}
	
	for(int i = 1; i < nodes; i++) {
		cout << parent[i] << "-" << i << endl;
	}
} 
