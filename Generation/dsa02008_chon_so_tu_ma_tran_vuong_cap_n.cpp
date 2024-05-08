#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[11][11], n, k, x[11];
bool checkColumn[11];
vector<vector<int>> ans;

void add()
{
    vector<int> copy(x+1, x+n+1);
    ans.push_back(copy);
}

void tryAt(int i, int sum)
{
    for(int j=1; j<=n; ++j)
    {
        if(checkColumn[j]) continue;
        x[i] = j;
        checkColumn[j] = 1;

        if(i == n && sum+a[i][j] == k) add();
        if(i < n) tryAt(i+1, sum+a[i][j]);

        checkColumn[j] = 0;
    }
}

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>a[i][j];
    
    tryAt(1, 0);

    cout<<ans.size()<<"\n";
    for(vector<int> &v : ans)
    {
        for(int &i : v) cout<<i<<" ";
        cout<<"\n";
    }
}