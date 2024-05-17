#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n, m, c, color[1001];
bool ok;

bool check(int u, int i)
{
    for(int v : adj[u])
    {
        if(color[v] == i)
            return 0;
    }
    return 1;
}

void tryAt(int u)
{
    if(ok) return;
    for(int i=1; i<=c; ++i)
    {
        if(check(u, i))
        {
            color[u] = i;
            if(u == n)
            {
                ok = 1;
                return;
            }
            else tryAt(u+1);
            color[u] = 0;
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>c;
        while(m--)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ok = 0;
        tryAt(1);
        
        cout<<(ok? "YES\n":"NO\n");

        for(int i=1; i<=n; ++i)
            adj[i].clear();
    }
}