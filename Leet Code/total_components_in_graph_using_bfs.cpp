#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int totalcomponents(int nodes, int edges, vector<int> adj[]) {

	vector<bool> visited(nodes + 1);
	int answer = 0;

	for(int i = 1; i <= nodes; i++) {

		if (!visited[i]){
			answer++;
			visited[i] = true;
			queue<int> q;
			q.push(i);

			while(!q.empty()){
				int node = q.front();
				q.pop();

				for(int x: adj[node]){
					if(!visited[x]){ 
						visited[x] = true;
						q.push(x);
					}
				}
			}
		}
	}
	return answer;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nodes, edges;
	cin >> nodes >> edges;

	vector<int> adj[nodes + 1];
	for(int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(v);
	}

	cout << totalcomponents(nodes, edges, adj) << endl;
}