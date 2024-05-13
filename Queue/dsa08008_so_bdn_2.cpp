#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        queue<ll> q;
        q.push(1);
        while(q.front() % n)
        {
            ll f = q.front(); q.pop();
            q.push(f*10);
            q.push(f*10 + 1);
        }
        cout<<q.front()<<"\n";
    }
}