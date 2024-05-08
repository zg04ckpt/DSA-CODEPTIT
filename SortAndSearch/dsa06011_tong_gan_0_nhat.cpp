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
        for(int &i : a) cin>>i;
        
        int ans = 1e9;
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j)
            {
                if(abs(a[i]+a[j]) < abs(ans))
                    ans = a[i]+a[j];
            }
        
        cout<<ans<<"\n";
    }
}