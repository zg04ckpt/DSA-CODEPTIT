#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int inf = 1e9;

int n, m, s;
vector<pii> adj[1001];
int d[1001];

void dijkstra()
{
    for(int i=1; i<=n; ++i)
        d[i] = inf;
    d[s] = 0;

    //{d[v], v}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(pq.size())
    {
        int u = pq.top().second;
        pq.pop();

        for(pii p : adj[u])
        {
            int w = p.first;
            int v = p.second;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }

    for(int i=1; i<=n; ++i)
        cout<<d[i]<<" ";
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>s;
        while(m--)
        {
            int u,v,w; cin>>u>>v>>w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        dijkstra();
        cout<<"\n";

        for(int i=1; i<=n; ++i)
            adj[i].clear();
    }
}