#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[pre][u]: chi phí nhỏ nhất xuất phát từ tp u
với trạng thái trước đó là pre
pre = số int có gt ~ chuỗi bit np là tt của các
tp đã chọn

*/

int c[16][16], n, d[(1<<15)+1][16];

int calc(int pre, int u)
{
    if(pre == (1<<n)-1)
        return 0;
    
    if(d[pre][u] != -1)
        return d[pre][u];

    int mi = 1e9;
    int cur = 1<<n;
    for(int v=1; v<=n; ++v)
    {
        cur = cur>>1;
        if((pre&cur) != 0) continue;
        mi = min(
            mi,
            c[u][v] + calc(pre|cur, v)
        );
    }

    d[pre][u] = mi;
    return mi;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>c[i][j];
        
        memset(d, -1, sizeof d);
        int ans = 1e9;
        for(int i=1; i<=n; ++i)
            ans = min(ans, calc(0, i));

        cout<<ans<<'\n';
    }
}