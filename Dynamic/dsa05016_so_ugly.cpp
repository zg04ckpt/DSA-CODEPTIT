#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll d[10005];

void init()
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    map<ll, bool> check;
    pq.push(1);
    check[1] = 1;
    while(check.size() < 10000)
    {
        ll mi = pq.top(); pq.pop();
        if(!check[mi*2])
        {
            pq.push(mi*2);
            check[mi*2] = 1;
        }

        if(!check[mi*3])
        {
            pq.push(mi*3);
            check[mi*3] = 1;
        }

        if(!check[mi*5])
        {
            pq.push(mi*5);
            check[mi*5] = 1;
        }
    }

    int c = 1;
    for(auto p : check)
        d[c++] = p.first;
}

int main()
{
    init();
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        cout<<d[n]<<"\n";
    }
}