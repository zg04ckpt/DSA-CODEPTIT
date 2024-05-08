#include<bits/stdc++.h>
#define ll long long

using namespace std;

int find(ll a[], ll b[], int n)
{
    int l = 0, r = n-2;
    int res = -1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(a[m] != b[m])
        {
            res = m+1;
            r = m-1;
        }
        else l = m+1;
    }
    return res;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        ll a[n], b[n-1];
        for(ll &i : a) cin>>i;
        for(ll &i : b) cin>>i;
        cout<<find(a, b, n)<<"\n";
    }
}