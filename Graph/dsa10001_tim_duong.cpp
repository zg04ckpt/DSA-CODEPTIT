#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

string a[501];
int n, m, cnt[501][501];

bool canMove(int i, int j)
{
    if(i<1 || i>n || j<1 || j>m) return 0;
    if(a[i][j] == '*') return 0;
    if(cnt[i][j] != -1) return 0;
    return 1;
}

bool bfs(pii s)
{
    queue<pii> q;
    q.push(s);
    cnt[s.first][s.second] = 0;
    while(q.size())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(cnt[i][j] > 2) return 0;

        int i0, j0;
        for(int k=0; k<4; ++k)
        {
            i0 = i+di[k];
            j0 = j+dj[k];
            while(canMove(i0, j0))
            {
                if(a[i0][j0] == 'T') return 1;
                q.push({i0, j0});
                cnt[i0][j0] = cnt[i][j]+1;

                i0 += di[k];
                j0 += dj[k];
            }
        }
    }
}

bool find()
{
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    {
        if(a[i][j] == 'S')
            return bfs({i, j});
    }
    return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i];
            a[i] = " " + a[i];
        }

        memset(cnt, -1, sizeof cnt);
        cout<<(find()? "YES\n":"NO\n");
    }
}