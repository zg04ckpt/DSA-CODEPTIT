#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while(n--)
        {
            ll e; cin>>e;
            pq.push(e);
        }

        ll ans = 0;
        while(pq.size() > 1)
        {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ans += a+b;
            pq.push(a+b);
        }

        cout<<ans<<"\n";
    }
}