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

        int ma[n];
        ma[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(a[i] > ma[i+1]) ma[i] = a[i];
            else ma[i] = ma[i+1];
        }

        int j = 0, ans = 0;
        for(int i=0; i<n-1; ++i)
        {
            while(j<n && a[i]<ma[j]) j++;
            ans = max(ans, j-i-1);
        }

        if(ans == 0) cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
}