#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        int a[n];
        for(int &i : a) cin>>i;

        sort(a, a+n);
        ll ans = 0;
        for(int i=0; i<n-1; ++i)
        {
            int *it = lower_bound(a+i+1, a+n, k+a[i]);
            ans += it-(a+i+1);
        }

        cout<<ans<<"\n";
    }
}