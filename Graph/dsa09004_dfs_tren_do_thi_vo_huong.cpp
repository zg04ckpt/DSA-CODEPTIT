#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n,m,s;
bool check[1001];

void dfs(int u)
{
    check[u] = 1;
    cout<<u<<" ";
    for(int v : adj[u])
    {
        if(check[v]) continue;
        dfs(v);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>s;
        int u,v;
        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(s);
        cout<<"\n";

        for(int i=1; i<=n; ++i)
        {
            check[i] = 0;
            adj[i].clear();
        }
    }
}