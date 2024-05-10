#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i][j]: kích thước hv max từ 0,0 -> i,j
*/

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
        
        int d[n+1][m+1] = {};
        int ans = 0;
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(a[i][j] == 0) continue;
            d[i][j] = min({
                d[i-1][j],
                d[i-1][j-1],
                d[i][j-1]
            }) + 1;

            ans = max(ans, d[i][j]);
        }

        cout<<ans<<"\n";
    }
}