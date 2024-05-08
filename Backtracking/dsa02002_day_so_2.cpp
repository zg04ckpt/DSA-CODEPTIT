#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[11];
vector<string> ans;

void add(int m)
{
    string s = "[";
    for(int i=1; i<m; i++) 
        s += to_string(a[i])+" ";
    s += to_string(a[m])+"]";
    ans.push_back(s);
}

void tryAt(int n)
{
    add(n);
    for(int i=1; i<n; ++i) a[i] += a[i+1];
    if(n-1) tryAt(n-1);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        tryAt(n);

        for(int i=ans.size()-1; i>=0; i--)
            cout<<ans[i]<<" ";
        cout<<"\n";

        ans.clear();
    }
}