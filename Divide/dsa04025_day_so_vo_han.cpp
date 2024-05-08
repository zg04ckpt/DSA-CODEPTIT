#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

struct Matrix{
    ll a[3][3] = {};

    void init()
    {
        a[1][1] = a[2][2] = 1;
    }

    Matrix operator*(Matrix o)
    {
        Matrix res;
        for(int i=1; i<=2; ++i)
        for(int j=1; j<=2; ++j)
        for(int k=1; k<=2; ++k)
        {
            res.a[i][j] += (a[i][k] * o.a[k][j])%mod;
            res.a[i][j] %= mod;
        }
        return res;
    }
};

ll calc(ll n)
{
    Matrix f;
    f.a[1][1] = f.a[1][2] = f.a[2][1] = 1;
    Matrix res; res.init();

    while(n)
    {
        if(n%2) res = res*f;
        n /= 2;
        f = f*f;
    }

    return res.a[1][2];
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        cout<<calc(n)<<'\n';
    }
}