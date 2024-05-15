#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        int u,v;
        int deg[1001] = {};
        while(m--)
        {
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }

        int cnt = 0;
        for(int i=1; i<=n; ++i)
            cnt += deg[i]%2;
        
        if(cnt==0) cout<<"2\n";
        else if(cnt==2) cout<<"1\n";
        else cout<<"0\n";
    }
}