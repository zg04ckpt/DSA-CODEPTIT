#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i]: tài sản troomj được khi qua nhà thứ i

1. nó sẽ trộm nhà thứ i ->
d[i] = c[i] + d[i-2];

2. nó sẽ không trộm nhà thứ i
d[i] = d[i-1];
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n+1];
        for(int i=1; i<=n; ++i) cin>>a[i];

        ll d[n+1] = {};
        d[1] = a[1];
        for(int i=2; i<=n; ++i)
        {
            d[i] = max(
                d[i-1],
                a[i] + d[i-2]
            );
        }

        cout<<d[n]<<"\n";
    }
}