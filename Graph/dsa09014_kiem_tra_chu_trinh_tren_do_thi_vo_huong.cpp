#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n, m;
bool check[1001], ok;

void dfs(int u, int par)
{
    if(ok) return;
    check[u] = 1;
    for(int v : adj[u])
    {
        if(!check[v])
            dfs(v, u);
        else if(v != par)
        {
            ok = 1;
            return;
        }
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

        ok = 0;
        for(int u=1; u<=n; ++u)
        {
            memset(check, 0, sizeof check);
            dfs(u, 0);
            if(ok) break;
        }

        cout<<(ok? "YES\n":"NO\n");

        for(int u=1; u<=n; ++u)
            adj[u].clear();
    }
}