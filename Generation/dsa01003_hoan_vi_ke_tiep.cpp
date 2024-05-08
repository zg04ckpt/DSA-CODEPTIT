#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; ++i) cin>>a[i];

        if(next_permutation(a, a+n))
        {
            for(int i=0; i<n; ++i) cout<<a[i]<<" ";
        }
        else
        {
            for(int i=0; i<n; ++i) cout<<i+1<<" ";
        }

        cout<<"\n";
    }
}