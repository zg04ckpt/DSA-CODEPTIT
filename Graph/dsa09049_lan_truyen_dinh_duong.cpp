#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> child[200001];
ll value[200001];
int n;

int dfs(int u)
{
    value[u] = 1;
    int siz = 0;
    for(int v : child[u])
    {
        siz += dfs(v);
        value[u] += value[v];
    }
    value[u] += siz;
    return siz+1;
}

int main()
{
    cin>>n;
    for(int i=2; i<=n; ++i)
    {
        int p; cin>>p;
        child[p].push_back(i);
    }

    dfs(1);

    for(int i=1; i<=n; ++i)
        cout<<value[i]<<" ";
}