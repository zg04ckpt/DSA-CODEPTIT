#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> adj1[1001], adj2[1001];
int n, m, cnt1, cnt2;
bool check[1001];

void dfs1(int u)
{
    cnt1++;
    check[u] = 1;
    for(int v : adj1[u])
    {
        if(!check[v])
            dfs1(v);
    }
}

void dfs2(int u)
{
    cnt2++;
    check[u] = 1;
    for(int v : adj2[u])
    {
        if(!check[v])
            dfs2(v);
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
            adj1[u].push_back(v);
            adj2[v].push_back(u);
        }

        cnt1 = cnt2 = 0;
        dfs1(1);
        if(cnt1 != n) cout<<"NO\n";
        else
        {
            memset(check, 0, sizeof check);
            dfs2(1);
            if(cnt2 != n) cout<<"NO\n";
            cout<<"YES\n";
        }

        for(int i=1; i<=n; ++i)
        {
            adj1[i].clear();
            adj2[i].clear();
            check[i] = 0;
        }
    }
}