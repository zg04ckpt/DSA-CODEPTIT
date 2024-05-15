#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        vector<int> adj[n+1];
        int u,v;
        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        for(int u=1; u<=n; ++u)
        {
            cout<<u<<": ";
            for(int v : adj[u])
                cout<<v<<" ";
            cout<<"\n";
        }
    }
}

