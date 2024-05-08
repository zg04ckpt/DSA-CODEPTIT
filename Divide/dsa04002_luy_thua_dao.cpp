#include<bits/stdc++.h>
#define ll long long

using namespace std;

//123 -> 123^321
// a^b -> a^(b/2) * a^(b/2)

ll m = 1e9+7;

ll reverse(ll n)
{
    ll res = 0;
    while(n)
    {
        res = res*10 + n%10;
        n /= 10;
    }
    return res;
}

ll calc(ll n, ll k)
{
    if(k == 1) return n%m;
    ll x = calc(n, k/2);
    x = (x*x)%m;
    if(k%2) return (x*n)%m;
    return x;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        cout<<calc(n, reverse(n))<<"\n";
    }
}