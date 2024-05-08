#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[v]: là giá lớn nhất có thể mang theo với 
thể tích là v

w[i], c[i]
d[v] = d[v-w[i]] + c[i];

*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,v; cin>>n>>v;
        int w[n+1], c[n+1];
        for(int i=1; i<=n; ++i) cin>>w[i];
        for(int i=1; i<=n; ++i) cin>>c[i];

        int d[v+1] = {};
        for(int i=1; i<=n; ++i)
        for(int j=v; j>=w[i]; j--)
            d[j] = max(d[j], d[j-w[i]]+c[i]);
    
        cout<<d[v]<<"\n";
    }
}