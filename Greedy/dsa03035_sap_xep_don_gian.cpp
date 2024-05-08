#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n; cin>>n;
    int a[n];
    for(int &i : a) cin>>i;

    int dp[n+1] = {};
    for(int i : a) dp[i] = dp[i-1]+1;

    cout<<n-*max_element(dp+1, dp+n+1);
}