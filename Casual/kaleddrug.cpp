#include<bits/stdc++.h>
using namespace std;

int calculate(vector<int> lavender,vector<int> mint)
{
    int s=0,i;
    bool d=0;
    
    sort(lavender.begin(),lavender.end());
    sort(mint.begin(),mint.end());
    
    for(i=0;i<lavender.size();i++)
    {
        int x=lavender[i];
        if(d)s+=2*x;
        else 
        {
            s+=x;d=1;
        }
    }
    for(i=mint.size()-1;i>=0;i--)
    {
        int x=mint[i];
        if(d)
        {
            s+=2*x;d=0;
        }
        else s+=x;
    }
    // cout<<s<<" ";
    return s;
}

int solve(int n, vector<int>type, vector<int>power)
{
    vector<int>lavender,mint;
    long i,c=1,mod=1e9+7,s;
    for(i=0;i<n;i++)
    {
        if(type[i])lavender.push_back(power[i]);
        else mint.push_back(power[i]);
        
        s=calculate(lavender,mint);
        c=(c%mod * s%mod)%mod;
    }
    return c;
}

int MaxiumDrugStrength(int n, vector<int>type, vector<int>power)
{
    return solve(n,type,power);
}