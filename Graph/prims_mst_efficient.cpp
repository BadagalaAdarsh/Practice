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
	}
	
	cost[0] = 0;
	parent[0] = -1;
	
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	pq.emplace(0, 0);
	
	for(int count = 0; count < nodes - 1; count++ ) {
		
		int u = pq.top().second;
		pq.pop();
		
		mstset[u] = true;
		
		for(auto it: adj[u]){
			int v = it.first;
			int wt = it.second;
			
			if (mstset[v] == false && wt < cost[v]) {
				parent[v] = u;
				cost[v] = wt;
				pq.emplace( cost[v], v);
			}
		}
	}
	
	for(int i = 1; i < nodes; i++) {
		cout << parent[i] << "-" << i << endl;
	}
}
