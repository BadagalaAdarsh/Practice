#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, ans[N];

void recurse(int r) {
	if (r < 0) return;
	int s = sqrt(2*r); s *= s;
	int l = s - r; recurse(l - 1);
	for (; l <= r; l++, r--) {
		ans[l] = r; ans[r] = l;
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cin >> n; recurse(n - 1);
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}
