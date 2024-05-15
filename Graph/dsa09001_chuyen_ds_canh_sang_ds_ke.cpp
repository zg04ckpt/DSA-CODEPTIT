#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj[1001];
int n, m;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int u,v;
        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1; i<=n; ++i)
        {
            cout<<i<<": ";
            for(int v : adj[i])
                cout<<v<<" ";
            cout<<"\n";
        }

        for(int i=1; i<=n; ++i)
            adj[i].clear();
    }
}