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

int binpow(int x, int y)
{
 	int z = 1;
 	while(y)
 	{
 	 	if(y & 1) z = mul(z, x);
 	 	x = mul(x, x);
 	 	y >>= 1;
 	}
 	return z;
}

vector<int> evaluate(int n, int choice_mask)
{
 	int cur_place = n / 2 + 1;
 	int cur_bit = n - 2;
 	vector<int> p(n);
 	vector<int> c(n);
 	for(int i = 0; i < n; i++)
 		c[i] = i;
 	while(c.size() != 1)
 	{
 		vector<int> nc;
 	 	for(int i = 0; i < c.size(); i += 2)
 	 	{
 	 	 	if(choice_mask & (1 << cur_bit))
 	 	 	{
 	 	 		p[c[i]] = cur_place;
 	 	 		nc.push_back(c[i + 1]);
 	 	 	}
 	 	 	else
 	 	 	{
 	 	 		p[c[i + 1]] = cur_place;
 	 	 		nc.push_back(c[i]);
 	 	 	}
 	 	 	cur_bit--;
 	 	}
 	 	c = nc;
 	 	cur_place /= 2;
  		cur_place++;
	}
	p[c[0]] = 1;
	return p;
}

vector<int> adjust(int n, vector<int> p, bool winning)
{
	for(int i = 0; i < n; i++)
	{
		if(p[i] == 1)
		{
		 	if(!winning) p[i]++;	
		}
		else
		 	p[i] = p[i] * 2 - 1;
	}
	return p;
}	

int get_hash(int n, vector<int> p, int A, bool partial = false, bool winning = false, int shift = 0)
{
	if(partial)
		p = adjust(n, p, winning);
 	int res = 0;
 	for(int i = 0; i < n; i++)
 		res = add(res, mul(add(i + 1, shift), binpow(A, p[i])));
 	return res;
}

int main()
{
 	int k, A, h;
 	cin >> k >> A >> h;
 	if(k <= 4)
 	{
 		for(int i = 0; i < (1 << ((1 << k) - 1)); i++)
 		{             
 			vector<int> p = evaluate(1 << k, i);
 			if(get_hash(1 << k, p, A) == h)
 			{
 		 		for(auto x : p) cout << x << " ";
 		 		cout << endl;
 		 		return 0;
 			}
 		}
 	}
 	else
 	{
 		int mask_left = -1;
 		int mask_right = -1;
 		bool left_win = false;
 		for(int c = 0; c < 2; c++)
 		{
 		 	map<int, int> left_map;
 		 	for(int i = 0; i < (1 << 16); i++)
 		 	{
 		 	 	vector<int> p = evaluate(16, i);
 		 	 	int left_hash = get_hash(16, p, A, true, c == 0, 0);
 		 	 	left_map[left_hash] = i;	
 		 	}
 		 	for(int i = 0; i < (1 << 16); i++)
 		 	{
 		 	 	vector<int> p = evaluate(16, i);
 		 	 	int right_hash = get_hash(16, p, A, true, c == 1, 16);
 		 	 	int left_hash = add(h, MOD - right_hash);
 		 	 	if(left_map.count(left_hash))
 		 	 	{
 		 	 	 	mask_left = left_map[left_hash];
 		 	 	 	mask_right = i;
 		 	 	 	left_win = (c == 0);
 		 	 	}
 		 	}
 	 	}
 	 	if(mask_left != -1)
 		{
 	 		vector<int> ans_left = evaluate(16, mask_left);
 	 		vector<int> ans_right = evaluate(16, mask_right);
 	 		ans_left = adjust(16, ans_left, left_win);
 	 		ans_right = adjust(16, ans_right, !left_win);
 	 		for(auto x : ans_left)
 	 			cout << x << " ";
 	   		for(auto x : ans_right)
 	   			cout << x << " ";
 	   		return 0;
 		}        
 	}
 	cout << -1 << endl;
 	return 0;
}
