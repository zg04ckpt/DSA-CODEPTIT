#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        ll a[n];
        for(int i=0; i<n; ++i)
            cin>>a[i];
        
        int l[n];
        stack<pair<ll,int>> st1;
        for(int i=0; i<n; ++i)
        {
            while(st1.size() && st1.top().first>=a[i])
                st1.pop();
            
            if(st1.empty()) l[i] = -1;
            else l[i] = st1.top().second;

            st1.push({a[i], i});
        }

        int r[n];
        stack<pair<ll,int>> st2;
        for(int i=n-1; i>=0; --i)
        {
            while(st2.size() && st2.top().first>=a[i])
                st2.pop();
            
            if(st2.empty()) r[i] = n;
            else r[i] = st2.top().second;

            st2.push({a[i], i});
        }

        ll ans = 0;
        for(int i=0; i<n; ++i)
            ans = max(ans, a[i]*(r[i]-l[i]-1));
        
        cout<<ans<<"\n";
    }
}