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

        int l[n]; l[0] = a[0];
        for(int i=1; i<n; ++i) 
            l[i] = l[i-1]+a[i];

        int r[n]; r[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--)
            r[i] = r[i+1]+a[i];

        bool ok = 0;
        for(int i=0; i<n; ++i)
        {
            if(l[i] == r[i])
            {
                cout<<i+1;
                ok = 1;
                break;
            }
        }

        if(!ok) cout<<-1;
        cout<<"\n";
    }
}