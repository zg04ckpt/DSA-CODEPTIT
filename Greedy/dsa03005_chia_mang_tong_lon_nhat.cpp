#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
1 -> sắp xếp
2 -> k với n-k, hoặc n-k với k
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        int a[n];
        for(int &i : a) cin>>i;

        sort(a, a+n);

        int ans = 0;
        if(k < n-k)
        {
            for(int i=0; i<k; ++i) ans -= a[i];
            for(int i=k; i<n; ++i) ans += a[i];
        }
        else
        {
            for(int i=0; i<n-k; ++i) ans -= a[i];
            for(int i=n-k; i<n; ++i) ans += a[i];
        }

        cout<<ans<<"\n";
    }
}