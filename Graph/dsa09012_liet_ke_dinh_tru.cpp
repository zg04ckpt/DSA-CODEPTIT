#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int id[1001], mi[1001], n, m, cnt, childOfRoot;
bool check[1001];

void dfs(int u, int par)
{
    id[u] = mi[u] = cnt++;
    for(int v : adj[u])
    {
        if(v == par) continue;
        if(id[v]) 
            mi[u] = min(mi[u], id[v]);
        else
        {
            if(u == 1)
                childOfRoot++;

            dfs(v, u);
            mi[u] = min(mi[u], mi[v]);

            if(mi[v] >= id[u])
                check[u] = 1;
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

        cnt = 1;
        childOfRoot = 0;
        dfs(1, 0);
        if(childOfRoot > 1)
            check[1] = 1;
        else
            check[1] = 0;

        for(int i=1; i<=n; ++i)
        {
            if(check[i])
                cout<<i<<" ";
        }
        cout<<"\n";

        for(int i=1; i<=n; ++i)
        {
            mi[i] = id[i] = check[i] = 0;
            adj[i].clear();
        }
    }
}