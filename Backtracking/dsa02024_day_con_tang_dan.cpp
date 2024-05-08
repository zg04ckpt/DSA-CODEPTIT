#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[21], n, x[21];
vector<string> ans;

void add(int m)
{
    string s = "";
    for(int i=1; i<=m; ++i) 
        s += to_string(x[i])+ " ";
    ans.push_back(s);
}

void tryAt(int i, int pre)
{
    for(int j=pre+1; j<=n; ++j)
    {
        if(a[j] <= x[i-1]) continue;
        x[i] = a[j];
        if(i != 1) add(i);
        if(i < n) tryAt(i+1, j);
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];

    tryAt(1, 0);

    sort(ans.begin(), ans.end());
    for(string &s : ans) cout<<s<<"\n";
}