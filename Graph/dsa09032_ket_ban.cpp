#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<int, vector<int>> adj;
int n, m, cnt;
map<int, bool> check;

void dfs(int u)
{
    cnt++;
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

        int ans = 0;
        for(int u=1; u<=n; ++u)
        {
            if(!check[u])
            {
                cnt = 0;
                dfs(u);
                ans = max(ans, cnt);
            }
        }

        cout<<ans<<"\n";

        adj.clear();
        check.clear();
    }
}