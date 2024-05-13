#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll cnt = 0;
        queue<ll> q;
        q.push(1);
        while(q.front() <= n)
        {
            ll f = q.front(); q.pop();
            cnt++;
            q.push(f*10);
            q.push(f*10 + 1);
        }

        cout<<cnt<<"\n";
    }
}