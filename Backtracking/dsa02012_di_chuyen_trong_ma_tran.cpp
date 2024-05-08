#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[101][101], n, m, cnt;

void tryAt(int i, int j)
{
    if(i==n && j==m)
    {
        cnt++;
        return;
    }

    if(i != n) tryAt(i+1, j);
    if(j != m) tryAt(i, j+1);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                cin>>a[i][j];
        
        cnt = 0;
        tryAt(1, 1);

        cout<<cnt<<"\n";
    }
}