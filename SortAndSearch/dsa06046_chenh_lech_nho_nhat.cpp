#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int &i : a) cin>>i;

        sort(a, a+n);

        int ans = 1e9;
        for(int i=1; i<n; ++i)
            ans = min(ans, a[i]-a[i-1]);

        cout<<ans<<"\n";
    }
}