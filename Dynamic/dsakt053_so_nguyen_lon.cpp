#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string a,b; cin>>a>>b;

        int n = a.size();
        int m = b.size();
        a = " " + a;
        b = " " + b;

        int d[n+1][m+1] = {};
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(a[i]==b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max(
                    d[i-1][j],
                    d[i][j-1]
                );
        }

        cout<<d[n][m]<<"\n";
    }
}