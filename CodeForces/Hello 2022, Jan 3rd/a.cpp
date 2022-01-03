#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isOk(vector<string>&board, int curRow, int curCol, int n) {
	
	int up = curRow - 1;
	
	while(up >= 0) {
		
		if(board[up][curCol] == 'R') 
			return false;
			
		up--;
	}
	
	int down = curRow + 1;
	
	while(down < n) {
		
		if(board[down][curCol] == 'R') 
			return false;
			
		down++;
	}
	
	int right = curCol + 1;
	
	while(right < n) {
		
		if(board[curRow][right] == 'R') 
			return false;
			
		right++;
	}
	
	int left = curCol - 1;
	
	while(left >= 0) {
		
		if(board[curRow][left] == 'R') {
			return false;
		}
		
		left--;
	}
	
	return true;
	
}
		


bool Krooks(vector<string>& board, int n, int k, int row, int col) {
	
	if(k == 0) {
		return true;
	}
	
	if(row >= n) {
		return false;
	}
	
	for(int i = row; i < n; i ++){
		for(int j = col; j < n; j++) {
			
			if(board[i][j] == '.') {
				
				if(isOk(board , i, j, n)) {
					
					board[i][j] = 'R';
					
					if (Krooks(board, n, k-1, row + 2, col + 2)){
						return true;
					}
					
					board[i][j] = '.';
				}
			}
		}
	}
	
	return false;
	
}
				
	
	

void solve() {
	
	int n, k;
	cin >> n >> k;
	
	if(n == 1 && k == 1) {
		cout << "R" << endl;
		return;
	}
	
	
	if (n == k || k > n || n - k < n/2 ) {
		cout << -1 << endl;
		return;
	}
	
	
	vector<string> board(n);
	
	for(int i = 0; i < n; i++){
		string temp = "";
		for(int j = 0; j < n; j++) {
			temp += '.';
		}
		
		board[i] = temp;
	}
	
	
	bool answer = Krooks(board, n, k, 0, 0);
	
	if(answer) {
		for(int i = 0; i < n; i ++) {
			cout << board[i] << endl;
		}
		
		return;
	}
	
	cout << -1 << endl;
}
	


int main() {
	
	int test;
	cin >> test;
	
	while(test--) {
		
		solve();
		
	}
}
		
		
