#include<bits/stdc++.h>
#define ll long long
#define t4 tuple<int,int,int,int>

using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

map<t4, bool> wall;
int n, k, m, cnt;
bool check[101][101], arr[101][101];

bool canMove(int a, int b, int c, int d)
{
    if(c<1 || c>n || d<1 ||d>n) return 0;
    if(wall[{a, b, c, d}]) return 0;
    if(check[c][d]) return 0;
    return 1;
}

void tryAt(int i, int j)
{
    cnt += arr[i][j];
    check[i][j] = 1;
    for(int x=0; x<4; ++x)
    {
        if(canMove(i, j, i+di[x], j+dj[x]))
            tryAt(i+di[x], j+dj[x]);
    }
}

int main()
{
    cin>>n>>k>>m;
    int a,b,c,d;
    while(m--)
    {
        cin>>a>>b>>c>>d;
        wall[{a, b, c, d}] = 1;
        wall[{c, d, a, b}] = 1;
    }

    for(int i=1; i<=k; ++i)
    {
        cin>>a>>b;
        arr[a][b] = 1;
    }

    vector<int> v;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
    {
        if(!check[i][j])
        {
            cnt = 0;
            tryAt(i, j);
            v.push_back(cnt);
        }
    }

    int sum = 0;
    for(int i : v) sum += i;

    int ans = sum*(sum-1)/2;
    for(int i : v) ans -= i*(i-1)/2;

    cout<<ans<<"\n";
}