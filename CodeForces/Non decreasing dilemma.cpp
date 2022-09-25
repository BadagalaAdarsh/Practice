#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 2e5+5;
int a[N], k;
ll seg[N*4][4], ans;
 
/**
 
Notes:
 
0: The total number of non-decreasing subarrays in this segment which are are not subarrays of the longest prefix/suffix of non-decreasing subarrays.
1: Length of longest non-decreasing prefix of this segment.
2: Length of longest non-decreasing suffix of this segment.
3: Denotes if this entire segment is nondecreasing (0/1).
 
**/ 
 
ll f(int x)
{
    return (1LL*x*(x+1))/2;
}
 
void calc(int i, int l, int r)
{
    int m=l+(r-l)/2;
    if (seg[i*2+1][3]&&seg[i*2+2][3])
    {
        if (a[m]>a[m+1])
        {
            seg[i][0]=0;
            seg[i][1]=(r-l)/2+1;
            seg[i][2]=r-l-(r-l)/2;
            seg[i][3]=0;
        }
        else
        {
            seg[i][0]=0;
            seg[i][1]=0;
            seg[i][2]=0;
            seg[i][3]=1;
        }
    }
    else if (seg[i*2+1][3])
    {
        if (a[m]>a[m+1])
        {
            seg[i][0]=seg[i*2+2][0]+f(seg[i*2+2][1]);
            seg[i][1]=(r-l)/2+1;
            seg[i][2]=seg[i*2+2][2];
            seg[i][3]=0;
        }
        else
        {
            seg[i][0]=seg[i*2+2][0];
            seg[i][1]=(r-l)/2+1+seg[i*2+2][1];
            seg[i][2]=seg[i*2+2][2];
            seg[i][3]=0;
        }
    }
    else if (seg[i*2+2][3])
    {
        if (a[m]>a[m+1])
        {
            seg[i][0]=seg[i*2+1][0]+f(seg[i*2+1][2]);
            seg[i][1]=seg[i*2+1][1];
            seg[i][2]=r-l-(r-l)/2;
            seg[i][3]=0;
        }
        else
        {
            seg[i][0]=seg[i*2+1][0];
            seg[i][1]=seg[i*2+1][1];
            seg[i][2]=r-l-(r-l)/2+seg[i*2+1][2];
            seg[i][3]=0;
        }
    }
    else
    {
        if (a[m]>a[m+1])
        {
            seg[i][0]=seg[i*2+1][0]+seg[i*2+2][0]+f(seg[i*2+1][2])+f(seg[i*2+2][1]);
            seg[i][1]=seg[i*2+1][1];
            seg[i][2]=seg[i*2+2][2];
            seg[i][3]=0;
        }
        else
        {
            seg[i][0]=seg[i*2+1][0]+seg[i*2+2][0]+f(seg[i*2+1][2]+seg[i*2+2][1]);
            seg[i][1]=seg[i*2+1][1];
            seg[i][2]=seg[i*2+2][2];
            seg[i][3]=0;
        }
    }
}
 
void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>a[l];
        seg[i][3]=1;
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    calc(i,l,r);
}
 
void update(int i, int l, int r, int x, int y)
{
    if (l==r)
    {
        a[x]=y;
        return;
    }
    if (x<=l+(r-l)/2)
        update(i*2+1,l,l+(r-l)/2,x,y);
    else
        update(i*2+2,l+(r-l)/2+1,r,x,y);
    calc(i,l,r);
}
 
void query(int i, int l, int r, int qL, int qR)
{
    if (r<qL||qR<l)
        return;
    if (qL<=l&&r<=qR)
    {
        if (seg[i][3])
        {
            if (a[l-1]>a[l])
            {
                ans+=f(k);
                k=r-l+1;
            }
            else
                k+=r-l+1;
        }
        else
        {
            if (a[l-1]>a[l])
                ans+=seg[i][0]+f(k)+f(seg[i][1]);
            else
                ans+=seg[i][0]+f(k+seg[i][1]);
            k=seg[i][2];
        }
        return;
    }
    query(i*2+1,l,l+(r-l)/2,qL,qR);
    query(i*2+2,l+(r-l)/2+1,r,qL,qR);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,l,r;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>t>>l>>r;
        if (t==1)
            update(0,1,n,l,r);
        else
        {
            ans=k=0;
            query(0,1,n,l,r);
            cout<<ans+f(k)<<"\n";
        }
    }
    return 0;
}
