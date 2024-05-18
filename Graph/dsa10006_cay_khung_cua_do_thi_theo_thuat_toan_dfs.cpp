#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n, m, s;
bool check[1001];
vector<pair<int,int>> ans;

void dfs(int u)
{
    check[u] = 1;
    for(int v : adj[u])
    {
        if(!check[v])
        {
            ans.push_back({u, v});
            dfs(v);
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>s;
        while(m--)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(s);
        if(ans.size() != n-1)
            cout<<"-1\n";
        else
        {
            for(auto p : ans)
                cout<<p.first<<" "<<p.second<<"\n";
        }

        for(int i=1; i<=n; ++i)
        {
            adj[i].clear();
            check[i] = 0;
        }
        ans.clear();
    }
}