#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        ll a[n];
        for(ll &i : a) cin>>i;

        ll sum = 0;
        int l = 0, r = 0;
        bool ok = 0;
        while(r < n)
        {
            sum += a[r];
            while(l<r && sum>k)
            {
                sum -= a[l];
                l++;
            }

            if(sum == k)
            {
                ok = 1;
                break;
            }

            r++;
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}