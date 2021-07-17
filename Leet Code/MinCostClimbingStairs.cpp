#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int minCost(vector<int>& cost) {
    int n = cost.size();

    if (n < 3) {
        return *min_element(cost.begin(), cost.end());
    }

    vector<int> array(n+1);
    
    array[0] = cost[0];
    array[1] = cost[1];

    for(int i = 2; i < n; i++) array[i] = cost[i] + min(array[i-1], array[i-2]);

    array[n] = min(array[n-1],array[n-2]);
    return array[n];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test;
    cin >> test;

    while(test--) {
        int n;
        cin >> n;

        vector<int> cost(n);
        for(int i = 0; i < n; i++) cin >> cost[i];

        cout << minCost(cost) << endl;
    }
}