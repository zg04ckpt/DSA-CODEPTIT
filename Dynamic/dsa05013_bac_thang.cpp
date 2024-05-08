#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i]: số cách bước đến bậc i
d[i] có k cách bước:
- d[i-1]
- d[i-2]
- d[i-3]
....
- d[i-k]
*/

const int mod = 1e9+7;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        int d[n+1] = {};
        d[0] = 1;
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=k; ++j)
        {
            if(i-j < 0) break;
            d[i] = (d[i]+d[i-j])%mod;
        }

        cout<<d[n]<<"\n";
    }
}