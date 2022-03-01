#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int a, b, c;
	cin >> a >> b >> c;
	
	int one = a + b * c;
	int two = a * (b + c);
	int three = a * b * c;
	int four = (a + b) * c;
	int five = a + b + c;
	
	cout << max( {one,two,three, four,five} ) << endl;
}
