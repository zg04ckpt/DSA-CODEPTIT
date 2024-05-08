#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        ll a[n], b[n];
        for(ll &i : a) cin>>i;
        for(ll &i : b) cin>>i;

        sort(a, a+n);
        sort(b, b+n, greater<ll>());

        ll ans = 0;
        for(int i=0; i<n; ++i)
            ans += a[i]*b[i];
        
        cout<<ans<<"\n";
    }
}