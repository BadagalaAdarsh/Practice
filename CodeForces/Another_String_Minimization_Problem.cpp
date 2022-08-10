#include <bits/stdc++.h>

#define debug(...) fprintf(stderr ,__VA_ARGS__)
#define __FILE(x)\
	freopen(#x".in" ,"r" ,stdin);\
	freopen(#x".out" ,"w" ,stdout)
#define LL long long

const int MX = 5e5 + 23;
const LL MOD = 998244353;

int read(){
	char k = getchar(); int x = 0;
	while(k < '0' || k > '9') k = getchar();
	while(k >= '0' && k <= '9') x = x * 10 + k - '0' ,k = getchar();
	return x;
}

int n ,a[MX] ,q ,choose[MX];
bool check(int mid){
	for(int i = 1 ; i <= n ; ++i) choose[i] = 0;
	int iq = q;
	for(int i = 1 ; i < mid ; ++i)
		if(a[i] <= iq) choose[i] = 1;
	for(int i = mid ; i <= n ; ++i){
		choose[i] = 1;
		if(iq == 0) return 0;
		if(a[i] > iq) --iq;
		
	}
	if(iq < 0) return 0;
	return 1;
}

void solve(){
	n = read() ,q = read();
	for(int i = 1 ; i <= n ; ++i)
		a[i] = read();
	int l = 1 ,r = n ,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	// [r + 1 ,n] is selected
	check(r + 1);
	for(int i = 1 ; i <= n ; ++i)
		printf("%d" ,choose[i]);
	puts("");
}

int main(){
	int T = read();
	for(int i = 1 ; i <= T ; ++i){
		solve();
	}
	return 0;
}
