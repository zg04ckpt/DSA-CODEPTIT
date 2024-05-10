#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n+1];
        for(int i=1; i<=n; ++i)
            cin>>a[i];

        int d[n+1] = {};
        d[1] = a[1];
        for(int i=2; i<=n; ++i)
            d[i] = max(d[i-1], a[i]+d[i-2]);
        
        cout<<d[n]<<"\n";
    }
}