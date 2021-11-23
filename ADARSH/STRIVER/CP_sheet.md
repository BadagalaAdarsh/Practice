
# Linear Search

## [Maximum Sum](https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/maximum-sum-4-f8d12458/)

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	long long sum = 0;
	int count = 0;

	int mx = -2e9;

	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		if (x >= 0) {
			sum += 1LL * x;
			count++;
		} 
		mx = max(mx, x);
		
	}

	if(count) cout << sum << " " << count << endl;
	else cout << mx << " " << 1 << endl;
}
```