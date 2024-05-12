#include<bits/stdc++.h>
#define ll long long

using namespace std;

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
        
        int d[n+1][m+1];
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(i==1 && j==1)
                d[i][j] = a[i][j];
            else if(i == 1)
                d[i][j] = d[i][j-1] + a[i][j];
            else if(j == 1)
                d[i][j] = d[i-1][j] + a[i][j];
            else
                d[i][j] = min({
                    d[i-1][j],
                    d[i-1][j-1],
                    d[i][j-1]
                }) + a[i][j];
        }

        cout<<d[n][m]<<"\n";
    }
}