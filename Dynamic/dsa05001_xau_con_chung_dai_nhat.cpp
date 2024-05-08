#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
dp[i][j] = độ dài xâu con chung của 2 xâu
kết thúc tại i và j
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s1,s2; cin>>s1>>s2;

        int n = s1.size();
        int m = s2.size();

        s1 = " " + s1;
        s2 = " " + s2;

        int dp[n+1][m+1] = {};
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(s1[i] == s2[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(
                    dp[i][j-1],
                    dp[i-1][j]
                );
            }
        }

        cout<<dp[n][m]<<"\n";
    }
}