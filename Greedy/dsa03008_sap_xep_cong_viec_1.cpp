#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        pair<int, int> a[n];
        for(int i=0; i<n; ++i) cin>>a[i].second;
        for(int i=0; i<n; ++i) cin>>a[i].first;

        sort(a, a+n);

        int ans = 0, end = 0;
        for(int i=0; i<n; ++i)
        {
            if(a[i].second >= end)
            {
                ans++;
                end = a[i].first;
            }
        }

        cout<<ans<<'\n';
    }
}