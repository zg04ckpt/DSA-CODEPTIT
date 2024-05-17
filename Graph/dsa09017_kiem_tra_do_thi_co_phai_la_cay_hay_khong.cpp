#include<bits/stdc++.h>
#define ll long long

using namespace std;

int par[1001], n;

void init()
{
    for(int i=1; i<=n; ++i)
        par[i] = i;
}

int rootOf(int u)
{
    if(par[u] == u) return u;
    return par[u] = rootOf(par[u]);
}

bool merge(int u, int v)
{
    u = rootOf(u);
    v = rootOf(v);
    if(u == v) return 0;
    par[v] = u;
    return 1;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        init();
        bool ok = 1;
        for(int i=1; i<=n-1; ++i)
        {
            int u,v; cin>>u>>v;
            if(ok && !merge(u, v))
                ok = 0;
        }

        cout<<(ok? "YES\n":"NO\n");
    }
}