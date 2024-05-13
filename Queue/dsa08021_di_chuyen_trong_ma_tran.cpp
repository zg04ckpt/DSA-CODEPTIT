#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct A {
    int x,y,step;
};

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        int a[n+1][m+1];
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            cin>>a[i][j];

        queue<A> q;
        q.push({1, 1, 0});
        int ans = -1;
        while(q.size())
        {
            A f = q.front(); q.pop();
            if(f.x==n && f.y==m)
            {
                ans = f.step;
                break;
            }

            if(a[f.x][f.y] == 0) 
                continue;
            
            int y0 = f.y + a[f.x][f.y];
            int x0 = f.x + a[f.x][f.y];
            if(y0 <= m)
                q.push({f.x, y0, f.step+1});
            if(x0 <= n)
                q.push({x0, f.y, f.step+1});
            
            a[f.x][f.y] = 0;
        }

        cout<<ans<<"\n";
    }
}