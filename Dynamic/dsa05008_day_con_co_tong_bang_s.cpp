#include<bits/stdc++.h>
#define ll long long

using namespace std;

//dp[i] : mảng A có tồn tại tập con có tổng i

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,s; cin>>n>>s;
        int a[n];
        for(int &i : a) cin>>i;

        bool dp[s+1] = {};
        dp[0] = 1;
        for(int i=0; i<n; ++i)
        for(int j=s; j>=a[i]; j--)
        {
            if(!dp[j])
                dp[j] = dp[j-a[i]];
        }

        if(dp[s]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}