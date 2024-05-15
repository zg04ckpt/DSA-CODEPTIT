#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n,m;
bool check[1001];

void dfs(int u)
{
    check[u] = 1;
    for(int v : adj[u])
    {
        if(!check[v])
            dfs(v);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        while(m--)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int q; cin>>q;
        while(q--)
        {
            int x,y; cin>>x>>y;
            memset(check, 0, sizeof check);
            dfs(x);
            if(check[y]) cout<<"YES\n";
            else cout<<"NO\n";
        }

        for(int i=1; i<=n; ++i)
            adj[i].clear();
    }
}