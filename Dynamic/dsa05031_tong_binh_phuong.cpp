#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        
        int d[n+1];
        for(int i=0; i<=n; ++i)
        {
            d[i] = i;
            for(int j=1; j*j<=i; ++j)
                d[i] = min(d[i], d[i-j*j]+1);
        }

        cout<<d[n]<<"\n";
    }
}