#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[100001];
bool check[100001];
int n, m, cnt;

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

        bool ok = 1;
        for(int u=1; u<=n; ++u)
        {
            memset(check, 0, sizeof check);
            cnt = 0;
            dfs(u);
            if(cnt != n)
            {
                ok = 0;
                break;
            }
        }

        cout<<(ok? "YES\n":"NO\n");

        for(int u=1; u<=n; ++u)
        {
            adj[u].clear();
            check[u] = 0;
        }
    }
}