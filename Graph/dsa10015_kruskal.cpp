#include<bits/stdc++.h>
#define ll long long
#define E pair<int, pair<int,int>>

using namespace std;

int n, m, par[101];
vector<E> edges;

void init()
{
    for(int i=1; i<=n; ++i)
        par[i] = i;
}

int rootOf(int u)
{
    if(u == par[u])
        return u;
    return par[u] = rootOf(par[u]);
}

bool merge(int u, int v)
{
    u = rootOf(u);
    v = rootOf(v);
    if(u == v) return 0;
    par[v] = u;
    return 1;
}

void kruskal()
{
    int dH = 0, cnt = 0;
    for(E e : edges)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if(merge(u, v))
        {
            dH += w;
            cnt++;
            if(cnt == n-1)
                break;
        }
    }

    cout<<dH<<"\n";
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({w, {u, v}});
        }
        init();
        sort(edges.begin(), edges.end());
        kruskal();
        edges.clear();
    }
}