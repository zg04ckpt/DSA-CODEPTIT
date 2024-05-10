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

        int l[n], r[n];
        for(int i=0; i<n; ++i)
        {
            l[i] = a[i];
            for(int j=0; j<i; ++j)
            {
                if(a[i] > a[j])
                    l[i] = max(l[i], l[j]+a[i]);
            }
        }

        for(int i=n-1; i>=0; --i)
        {
            r[i] = a[i];
            for(int j=n-1; j>i; --j)
            {
                if(a[i] > a[j])
                    r[i] = max(r[i], r[j]+a[i]);
            }
        }

        int ans = 0;
        for(int i=0; i<n; ++i)
            ans = max(ans, l[i]+r[i]-a[i]);
        
        cout<<ans<<"\n";
    }
}