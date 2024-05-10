#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m,p; cin>>n>>m>>p;
        string a,b,c; cin>>a>>b>>c;

        a = " "+a;
        b = " "+b;
        c = " "+c;

        int d[n+1][m+1][p+1] = {};
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        for(int k=1; k<=p; ++k)
        {
            if(a[i]==b[j] && b[j]==c[k])
                d[i][j][k] = d[i-1][j-1][k-1] + 1;
            else
                d[i][j][k] = max({
                    d[i-1][j][k],
                    d[i][j-1][k],
                    d[i][j][k-1],
                });
        }

        cout<<d[n][m][p]<<"\n";
    }
}