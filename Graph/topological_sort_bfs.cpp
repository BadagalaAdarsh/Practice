#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> toposort(int nodes, int edges, vector<int> adj[]) {

    queue<int> q;
    vector<int> indegree(nodes);

    // calculating and storing in degree of the graph
    for(int i = 0; i < nodes; i++) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }

    // pushing the nodes which are having indegree 0 to queue
    for(int i = 0; i < nodes; i++) {
        if (indegree[i] == 0 ) {
            q.push(i);
        }
    }

    vector<int> answer;
    while( !q.empty()) {
        int node = q.front();
        q.pop();

        answer.push_back(node);
        for(auto it: adj[node]) {
            indegree[it]--;

            if(indegree[it] == 0) {
                q.push(it);
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

    vector<int> adj[nodes];

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> answer;
    answer = toposort(nodes, edges, adj);

    for(int i : answer) {
        cout << i << " ";
    }
}