#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n, m;
bool check[1001], ok;

void tryAt(int u, int cnt)
{
    if(ok) return;
    for(int v : adj[u])
    {
        if(check[v]) continue;
        if(cnt+1 == n)
        {
            ok = 1;
            return;
        }
        check[v] = 1;
        tryAt(v, cnt+1);
        check[v] = 0;
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
            check[u] = 1;
            tryAt(u, 1);
            if(ok) break;
        }
        cout<<ok<<"\n";

        for(int i=1; i<=n; ++i)
            adj[i].clear();
    }
}