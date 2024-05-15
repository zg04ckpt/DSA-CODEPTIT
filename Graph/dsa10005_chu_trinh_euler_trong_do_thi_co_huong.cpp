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
        int deg1[n+1] = {};
        int deg2[n+1] = {};
        while(m--)
        {
            cin>>u>>v;
            deg1[u]++;
            deg2[v]++;
        }

        bool ok = 1;
        for(int i=1; i<=n; ++i)
        {
            if(deg1[i] != deg2[i])
            {
                ok = 0;
                break;
            }
        }

        cout<<ok<<"\n";
    }
}