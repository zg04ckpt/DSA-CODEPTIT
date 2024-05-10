#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        if(k > n) cout<<"0\n";
        else if(k == n) cout<<"1\n";
        else
        {
            ll res = 1;
            for(int i=n; i>=n-k+1; --i)
                res = (res*i) % mod;
            cout<<res<<"\n";
        }
    }
}