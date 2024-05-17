#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
bool check[1001];
int q[101], n, m, k;

void dfs(int u)
{
    check[u] = 1;
    for(int v : adj[u])
    {
        if(!check[v])
            dfs(v);
    }
}

bool isValid()
{
    for(int i=1; i<=k; ++i)
    {
        if(!check[q[i]])
            return 0;
    }
    return 1;
}

int main()
{
    cin>>k>>n>>m;
    for(int i=1; i<=k; ++i)
        cin>>q[i];
    
    while(m--)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    int ans = 0;
    for(int i=1; i<=n; ++i)
    {
        memset(check, 0, sizeof check);
        dfs(i);
        if(isValid())
            ans++;
    }

    cout<<ans;
}