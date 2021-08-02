#include<bits/stdc++.h>
#define endl "\n"
using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long q;
	cin >> n >> q;

	vector<vector<char>> grid(n, vector<char>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/

	vector<vector<long long>> dp(n+1, vector<long long>(n+1));

	//copy the same first;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
			if (grid[i-1][j-1] == '*'){
				dp[i][j] = 1;
			}
		}
	}

	// sum of top row
	for(int i = 1; i <= n; i++){
		dp[0][i] += dp[0][i-1];
		dp[i][0] += dp[i-1][0];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	
	/*
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	while(q--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		long long curr = dp[x2][y2];
		long long up = dp[x2][y1-1];
		long long left = dp[x1-1][y2];
		long long diag = dp[x1-1][y1-1];
		cout << curr - up - left + diag << endl;
	}
}
