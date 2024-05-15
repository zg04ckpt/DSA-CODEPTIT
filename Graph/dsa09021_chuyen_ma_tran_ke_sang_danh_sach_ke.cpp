#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> adj[n+1];
    
    for(int u=1; u<=n; ++u)
    for(int v=1; v<=n; ++v)
    {
        int e; cin>>e;
        if(e) adj[u].push_back(v);
    }

    for(int u=1; u<=n; ++u)
    {
        for(int v : adj[u])
            cout<<v<<" ";
        cout<<"\n";
    }
}