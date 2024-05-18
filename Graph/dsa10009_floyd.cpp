#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,m; cin>>n>>m;

    int d[n+1][n+1];
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
    {
        if(i == j) d[i][j] = 0;
        else d[i][j] = 1e9;
    }

    int u,v,w;
    while(m--)
    {
        cin>>u>>v>>w;
        d[u][v] = w;
        d[v][u] = w;
    }

    for(int k=1; k<=n; ++k)
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
    {
        if(d[i][j] > d[i][k]+d[k][j])
            d[i][j] = d[i][k]+d[k][j];
    }

    int q; cin>>q;
    while(q--)
    {
        cin>>u>>v;
        cout<<d[u][v]<<"\n";
    }
}