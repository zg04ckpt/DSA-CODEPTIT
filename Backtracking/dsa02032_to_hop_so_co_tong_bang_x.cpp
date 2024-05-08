#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[25], X[25], n, x;
vector<vector<int>> ans;

void add(int m)
{
    vector<int> cop(X+1, X+m+1);
    ans.push_back(cop);
}

void tryAt(int i, int pre, int sum)
{
    for(int j=pre; j<=n; ++j)
    {
        if(sum+a[j] > x) continue;
        X[i] = a[j];
        if(sum+a[j] == x) add(i);
        else tryAt(i+1, j, sum+a[j]);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(int i=1; i<=n; ++i) cin>>a[i];
        tryAt(1, 1, 0);
        if(ans.empty()) cout<<"-1\n";
        else
        {
            cout<<ans.size()<<" ";
            for(vector<int> &v : ans)
            {
                cout<<"{";
                for(int i=0; i<v.size()-1; ++i)
                    cout<<v[i]<<" ";
                cout<<v.back()<<"} ";
            }
            cout<<"\n";
        }

        ans.clear();
    }
}