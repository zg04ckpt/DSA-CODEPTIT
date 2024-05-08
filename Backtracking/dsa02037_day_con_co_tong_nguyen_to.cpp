#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[16], x[16], n;
vector<vector<int>> ans;

bool isPrime(int n)
{
    for(int i=2; i<=sqrt(n); ++i)
        if(n%i == 0) return 0;
    return n>1;
}



void add(int m)
{
    vector<int> cop(x+1, x+m+1);
    ans.push_back(cop);
}

void tryAt(int i, int pre, int sum)
{
    for(int j=pre+1; j<=n; ++j)
    {
        x[i] = a[j];
        if(isPrime(sum+a[j])) add(i);
        if(i < n) tryAt(i+1, j, sum+a[j]);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        sort(a+1, a+n+1, greater<int>());

        tryAt(1, 0, 0);

        sort(ans.begin(), ans.end());
        for(vector<int> &v : ans)
        {
            for(int &i : v) cout<<i<<" ";
            cout<<"\n";
        }

        ans.clear();
    }
}