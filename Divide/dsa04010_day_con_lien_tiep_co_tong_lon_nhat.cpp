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

        int ans = 0, sum = 0;
        for(int i=0; i<n; ++i)
        {
            sum = max(sum+a[i], a[i]);
            ans = max(ans, sum);
        }

        cout<<ans<<"\n";
    }
}