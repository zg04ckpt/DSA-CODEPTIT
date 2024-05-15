#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n,m,s,e, par[1001];
vector<int> adj[1001];
bool check[1001];

void dfs(int u)
{
    check[u] = 1;
    for(int v : adj[u])
    {
        if(!check[v])
        {
            par[v] = u;
            dfs(v);
        }
    }
}

void path()
{
    if(!check[e])
    {
        cout<<"-1\n";
        return;
    }

    vector<int> ans;
    while(e != s)
    {
        ans.push_back(e);
        e = par[e];
    }
    ans.push_back(e);

    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>s>>e;
        int u,v;
        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        dfs(s);
        path();

        for(int i=1; i<=n; ++i)
        {
            adj[i].clear();
            check[i] = par[i] = 0;
        }
    }
}