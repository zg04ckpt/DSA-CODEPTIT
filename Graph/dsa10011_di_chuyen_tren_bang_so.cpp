#include<bits/stdc++.h>
#define ll long long
#define t3 pair<int, pair<int,int>>

using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int n, m, a[501][501], c[501][501];

void dijkstra()
{
    c[1][1] = a[1][1];
    priority_queue<t3, vector<t3>, greater<t3>> pq;
    pq.push({c[1][1], {1, 1}});
    while(pq.size())
    {
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        for(int k=0; k<4; ++k)
        {
            int i0 = i+di[k];
            int j0 = j+dj[k];
            if(i0<1 || i0>n || j0<1 || j0>m) continue;
            if(c[i0][j0] > c[i][j]+a[i0][j0])
            {
                c[i0][j0] = c[i][j]+a[i0][j0];
                pq.push({c[i0][j0], {i0, j0}});
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
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            cin>>a[i][j];
            c[i][j] = 1e9;
        }

        dijkstra();
        cout<<c[n][m]<<"\n";
    }
}