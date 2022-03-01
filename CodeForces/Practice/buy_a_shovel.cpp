#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int price, change;
	cin >> price >> change;
	
	int totalShovels = 0;
	
	for(int i = 1; ; i++) {
		
		int currPrice = price * i;
		totalShovels++;
		if(currPrice % 10 == change || currPrice % 10 == 0)
			break;
	}
	
	cout << totalShovels << endl;
}
