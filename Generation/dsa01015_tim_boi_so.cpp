#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        queue<ll> q;
        q.push(9);
        while(q.front()%n)
        {
            ll f = q.front();
            q.pop();

            q.push(f*10);
            q.push(f*10+9);
        }
        cout<<q.front()<<"\n";
    }
}