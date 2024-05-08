#include<bits/stdc++.h>
#define ll long long

using namespace std;

int find(ll a[], ll n, ll x)
{
    int l = 0, r = n-1;
    int res = -1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(a[m] <= x)
        {
            res = m+1;
            l = m+1;
        }
        else r = m-1;
    }

    return res;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n,x; cin>>n>>x;
        ll a[n];
        for(ll &i : a) cin>>i;
        cout<<find(a, n, x)<<"\n";
    }
}