#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll m = 1e9+7;

//a^b -> (a^2)^(b/2) => log(b)

ll calc(ll n, ll k)
{
    ll res = 1;
    while(k)
    {
        if(k%2) res = (res*n)%m;
        k /= 2;
        n = (n*n)%m;
    }
    return res;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        cout<<calc(n, k)<<"\n";
    }
}