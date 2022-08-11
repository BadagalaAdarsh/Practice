#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(c=ch(),f=1;c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>void write(T x){
	static char q[65];int cnt=0;
	if(x<0)pc('-'),x=-x;
	q[++cnt]=x%10,x/=10;
	while(x)
		q[++cnt]=x%10,x/=10;
	while(cnt)pc(q[cnt--]+'0');
}
const int maxn=100005;
int a[maxn];
int main(){
	int T;read(T);
	while(T--){
		int n;read(n);
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=n-1;i>=1;--i){
			int pre=a[i+1],ok=false;
			for(int j=i;j>=1;--j){
				ok=(a[j]==0);
				pre-=(a[j]=pre-a[j]);
				if(ok){
					sort(a+j,a+i+1);
					break;
				}
			}
			if(!ok)
				sort(a+1,a+i+1);
		}
		write(a[1]),pc('\n');
	}
	return 0;
}
