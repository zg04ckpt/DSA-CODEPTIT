#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n, m, color[1001];
bool ok;

void dfs(int u, int c)
{
    if(!ok) return;
    color[u] = c;
    for(int v : adj[u])
    {
        if(color[v] == -1)
            dfs(v, 1-c);
        else if(color[v] == color[u])
        {
            ok = 0;
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

        ok = 1;
        for(int u=1; u<=n; ++u)
        {
            memset(color, -1, sizeof color);
            dfs(u, 0);
            if(!ok) break;
        }

        cout<<(ok? "YES\n":"NO\n");

        for(int i=1; i<=n; ++i)
            adj[i].clear();
    }
}