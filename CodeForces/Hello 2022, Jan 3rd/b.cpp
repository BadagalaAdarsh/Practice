#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

struct numbers{
	
	int left;
	int right;
	int cost;

};


void solve() {
	
	int n; 
	cin >> n;
	
	vector<numbers> array;
	
	for(int i = 0; i < n; i++) {
		
		numbers temp;
		cin >> temp.left >> temp.right >> temp.cost;

		
		array.push_back(temp);
	}
	
	for(int i = 0; i < n; i++) {
		cout << array[i].left << " " << array[i].right << " " << array[i].cost << endl;
	}
}
	
	


int main() {
	
	int test;
	cin >> test;
	
	
	while(test--) {
		
		solve();
		
	}
	
}
