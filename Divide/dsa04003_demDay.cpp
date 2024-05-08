#include<bits/stdc++.h>
#define ll long long

using namespace std;

//2^(n-1)

ll m = 123456789;

ll calc(ll n)
{
    if(n == 1) return 2;
    ll x = calc(n/2);
    x = (x*x)%m;
    if(n%2) return (x*2)%m;
    return x;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        cout<<calc(n-1)<<"\n";
    }
}