#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
	
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;

	while(test--) {

		int n;
		cin >> n;

		vector<bool> primes(n+1 ,true);
		primes[0] = false;
		primes[1] = false;

		for(int i = 2; i * i <= n ; i++) {

			if (primes[i]){
				for(int j = i*2; j < n; j += i ) {
					primes[j] = false;
				}
			}

		}

		for(int i = 0; i < n+1; i++) {
			if (primes[i]) {
				cout << i << " ";
			}
		}
	}
}
