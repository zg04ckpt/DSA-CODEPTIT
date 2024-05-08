#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        int a[n], b[m];
        for(int &i : a) cin>>i;
        for(int &i : b) cin>>i;

        int c[n+m-1] = {};
        for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            c[i+j] += a[i]*b[j];
        
        for(int i : c) cout<<i<<" ";
        cout<<"\n";
    }
}