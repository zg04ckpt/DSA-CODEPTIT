#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool valid(int state)
{
    for(int i=0; i<4; i++)
        if((state>>i&1) && (state>>(i+1)&1))
            return false;
    return true;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin >> n;
        vector<vector<int>> a(4, vector<int>(n));
        for(int i=0; i<4; i++)
            for(int j=0; j<n; j++)
                cin >> a[i][j];

        vector<vector<int>> dp(n, vector<int>(16, 0));
        for(int state=0; state<16; state++)
            if(valid(state))
                for(int i=0; i<4; i++)
                    if(state>>i&1)
                        dp[0][state] += a[i][0];

        for(int i=1; i<n; i++)
            for(int state=0; state<16; state++)
                if(valid(state))
                {
                    int sum = 0;
                    for(int j=0; j<4; j++)
                        if(state>>j&1)
                            sum += a[j][i];
                    for(int prevState=0; prevState<16; prevState++)
                        if((state & prevState) == 0)
                            dp[i][state] = max(dp[i][state], dp[i-1][prevState] + sum);
                }

        cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
    }
}