#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m,p; cin>>n>>m>>p;
        ll a[n], b[m], c[p];
        for(ll &i : a) cin>>i;
        for(ll &i : b) cin>>i;
        for(ll &i : c) cin>>i;

        int i,j,k; i=j=k=0;
        bool ok = 0;
        while(i<n && j<m && k<p)
        {
            if(a[i]==b[j] && b[j]==c[k])
            {
                cout<<a[i]<<" ";
                ok = 1;
                i++; j++; k++;
            }
            else
            {
                ll mi = min({a[i], b[j], c[k]});
                if(a[i] == mi) i++;
                if(b[j] == mi) j++;
                if(c[k] == mi) k++;
            }
        }

        if(!ok) cout<<-1;
        cout<<"\n";
    }
}