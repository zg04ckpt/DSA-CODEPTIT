#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

struct Matrix{
    ll a[11][11] = {}, n;

    void init()
    {
        for(int i=1; i<=n; ++i)
            a[i][i] = 1;
    }

    Matrix operator*(Matrix o)
    {
        Matrix res; res.n = n;
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
        for(int k=1; k<=n; ++k)
        {
            res.a[i][j] += (a[i][k] * o.a[k][j]) % mod;
            res.a[i][j] %= mod;
        }
        return res;
    }
};

ll calc(Matrix a, int k)
{
    Matrix res; 
    res.n = a.n;
    res.init();

    while(k)
    {
        if(k%2) res = res*a;
        k /= 2;
        a = a*a;
    }

    ll sum = 0;
    for(int i=1; i<=res.n; ++i)
        sum = (sum+res.a[i][res.n])%mod;
    
    return sum;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        Matrix a; a.n = n;
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>a.a[i][j];
        
        cout<<calc(a, k)<<"\n";
    }
}