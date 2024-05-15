#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
id, min
id : thứ tự duyệt
min: đỉnh có thứ tựu thấp nhất có thể đến

mình đến 1 đỉnh -> id++ = min

khi quay lại: 
1> cập nhật min[u] = min(min[u], min[v])
2. kt nếu min[v] > id[u] -> cạnh cầu
*/

vector<int> adj[1001];
int n,m, id[1001], mi[1001], cnt;
vector<pair<int,int>> ans;

void dfs(int u, int par)
{
    id[u] = mi[u] = cnt++;
    for(int v : adj[u])
    {
        if(v == par) continue;
        if(id[v]) mi[u] = min(mi[u], mi[v]);
        else
        {
            dfs(v, u);
            mi[u] = min(mi[u], mi[v]);
            if(mi[v] > id[u])
            {
                if(u < v)
                    ans.push_back({u, v});
                else
                    ans.push_back({v, u});
            }
        }
    }
}

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

        cnt = 1; 
        dfs(1, 0);

        sort(ans.begin(), ans.end());
        for(auto p : ans)
            cout<<p.first<<" "<<p.second<<" ";
        cout<<"\n";

        for(int i=1; i<=n; ++i)
        {
            adj[i].clear();
            id[i] = mi[i] = 0;
        }
        ans.clear();
    }
}