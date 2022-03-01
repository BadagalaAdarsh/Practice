#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n, k;
	cin >> n >> k;
	
	int totalMinutes = 240;
	int travelTime = k;
	int remainingTime = totalMinutes - travelTime;
	
	int currTime = 0;
	int problems = 0;
	for(int i = 1; i <= n; i++) {
		
		if(currTime + (5 * i) > remainingTime)
			break;
			
		problems++;
		currTime += (5 * i);
	}
	
	cout << problems << endl;
}
		
