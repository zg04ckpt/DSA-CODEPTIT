#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[5001], n;

bool find()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            ll ab = a[i]*a[i] + a[j]*a[j];
            ll c = sqrt(ab);
            if(c*c == ab)
            {
                ll *it = lower_bound(a+j, a+n, c);
                if(it!=a+n && *it==c)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; ++i) cin>>a[i];
        
        sort(a, a+n);

        if(find()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}