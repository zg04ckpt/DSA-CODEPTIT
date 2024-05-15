#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
bool check[1001];
int n, m;

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

        int cnt = 0;
        for(int u=1; u<=n; ++u)
        {
            if(!check[u])
            {
                cnt++;
                dfs(u);
            }
        }

        cout<<cnt<<"\n";

        for(int u=1; u<=n; ++u)
        {
            adj[u].clear();
            check[u] = 0;
        }
    }
}