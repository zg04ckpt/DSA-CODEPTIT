#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i][j]: số các số t/m có i chữ số 
& kết thúc bằng j
*/

const ll mod = 1e9+7;
ll d[101][10];

void init()
{
    for(int j=0; j<=9; ++j)
        d[1][j] = 1;
    
    for(int i=2; i<=100; ++i)
    for(int j=0; j<=9; ++j)
    for(int k=0; k<=j; ++k)
        d[i][j] = (d[i][j] + d[i-1][k]) % mod;
}

int main()
{
    init();
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        ll sum = 0;
        for(int j=0; j<=9; ++j)
            sum = (sum + d[n][j]) % mod;
        
        cout<<sum<<"\n";
    }
}