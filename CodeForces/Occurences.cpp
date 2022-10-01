#include <bits/stdc++.h>     

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
 	x += y;
 	while(x >= MOD) x -= MOD;
 	while(x < 0) x += MOD;
 	return x;
}

int mul(int x, int y)
{
 	return (x * 1ll * y) % MOD;
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<int>> A(n);
	vector<int> bad_num(k);
	for(int i = 0; i < n; i++)
	{
		int c;
		scanf("%d", &c);
		A[i].resize(c);
		for(int j = 0; j < c; j++)
		{
			scanf("%d", &A[i][j]); 	
			A[i][j]--;
		}
	}

	for(int i = 0; i < n; i++)
	{
	 	if(set<int>(A[i].begin(), A[i].end()).size() != A[i].size())
	 	{
	 	 	for(auto x : A[i])
	 	 		bad_num[x] = 1;
	 	}
	}
	vector<vector<int>> nxt(k);
	vector<vector<int>> prv(k);
	for(int i = 0; i < n; i++)
		for(int j = 0; j + 1 < A[i].size(); j++)
		{
		 	nxt[A[i][j]].push_back(A[i][j + 1]);
		 	prv[A[i][j + 1]].push_back(A[i][j]);
		}

	for(int i = 0; i < k; i++)
	{
	    sort(nxt[i].begin(), nxt[i].end());
	    sort(prv[i].begin(), prv[i].end());
	 	nxt[i].erase(unique(nxt[i].begin(), nxt[i].end()), nxt[i].end());
	 	prv[i].erase(unique(prv[i].begin(), prv[i].end()), prv[i].end());
	}

	vector<int> used(k, 0);
	vector<int> cnt(k + 1, 0);
	for(int i = 0; i < k; i++)
	{
		if(used[i]) continue;
	 	queue<int> q;
	 	vector<int> comp;
	 	q.push(i);
	 	used[i] = 1;
	 	while(!q.empty())
	 	{
	 		int z = q.front();
	 		q.pop();
	 		comp.push_back(z);
	 	 	for(auto x : nxt[z])
	 	 		if(!used[x])
	 	 		{
	 	 		 	used[x] = 1;
	 	 		 	q.push(x);
	 	 		}
	 	 	for(auto x : prv[z])
	 	 		if(!used[x])
	 	 		{
	 	 		 	used[x] = 1;
	 	 		 	q.push(x);
	 	 		}
	 	}
	 	bool bad = false;
	 	int cnt_beg = 0;
	 	for(auto x : comp)
	 	{
	 	 	if(prv[x].empty())
	 	 		cnt_beg++;
	 	 	if(prv[x].size() > 1 || nxt[x].size() > 1 || bad_num[x])
	 	 		bad = true;
	 	}
	 	bad |= (cnt_beg == 0);
	 	if(!bad)
	 		cnt[comp.size()]++;
	}
	vector<int> nonzero;
	for(int i = 1; i <= k; i++)
		if(cnt[i] > 0)
			nonzero.push_back(i);
	vector<int> dp(m + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= m; i++)
		for(auto x : nonzero)
		 	if(x <= i)
		 		dp[i] = add(dp[i], mul(cnt[x], dp[i - x]));

	printf("%d\n", dp[m]);
	return 0;
}
