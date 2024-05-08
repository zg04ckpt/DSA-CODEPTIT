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

        int dp[n]; dp[0] = 1;
        for(int i=1; i<n; ++i)
        {
            dp[i] = 1;
            for(int j=0; j<i; j++)
            {
                if(a[i] >= a[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        cout<<n-*max_element(dp, dp+n)<<"\n";
    }
}