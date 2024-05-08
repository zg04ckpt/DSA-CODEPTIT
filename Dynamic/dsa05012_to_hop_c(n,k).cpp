#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
c(n,k)
k = 0 || n == k => c(n,k) = 1
=> c(n,k) = c(n-1, k) + c(n-1,k-1)
*/

ll mod = 1e9+7;
ll c[1001][1001];

int main()
{
    for(int i=0; i<=1000; ++i)
    for(int j=0; j<=i; ++j)
    {
        if(j==0 || i==j) c[i][j] = 1;
        else
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
    }

    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        cout<<c[n][k]<<"\n";
    }
}