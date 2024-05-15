#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, s, e, par[1001];
vector<int> adj[1001];
bool check[1001];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    check[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop();
        for(int v : adj[u])
        {
            if(check[v]) continue;
            q.push(v);
            par[v] = u;
            check[v] = 1;
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
        while(m--)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
        }

        bfs(s);
        path();

        for(int i=1; i<=n; i++)
        {
            adj[i].clear();
            check[i] = par[i] = 0;
        }
    }
}