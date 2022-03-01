// https://codeforces.com/problemset/problem/546/A

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int k,n,w;
	cin >> k >> n >> w;
	
	// sum of first w natural numbers is needed;
	int total = (w * (w + 1))/2;
	
	int totalPrice = total * k;
	
	if(n > totalPrice)
	{
		cout << 0 << endl;
		return 0;
	}
	
	int neededMoney = totalPrice - n;
	
	cout << neededMoney << endl;
	
}
