#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	set<int> elements;
	
	while(n--) {
		
		int number;
		cin >> number;
		
		if (elements.find(number) == elements.end()) 
			elements.insert(number);
	}
	
	cout << elements.size() ;
}
