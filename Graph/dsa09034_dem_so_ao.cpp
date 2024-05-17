#include<bits/stdc++.h>
#define ll long long

using namespace std;

int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m;
string a[101];

void dfs(int i, int j)
{
    if(i<1 || i>n || j<1 || j>m) return;
    if(a[i][j] == '.') return;

    a[i][j] = '.';
    for(int k=0; k<8; k++)
        dfs(i+di[k], j+dj[k]);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        a[i] = " " + a[i];
    }

    int cnt = 0;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    {
        if(a[i][j] == 'W')
        {
            cnt++;
            dfs(i, j);
        }
    }

    cout<<cnt;
}