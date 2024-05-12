#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i][j]: độ dài xâu đx dài nhất từ i -> j
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int n = s.size();
        s = " " + s;

        int d[n+1][n+1];
        for(int i=1; i<=n; ++i)
            d[i][i] = 1;

        for(int len=2; len<=n; ++len)
        for(int i=1; i+len-1<=n; i++)
        {
            int j = i+len-1;
            if(s[i] == s[j])
            {
                if(len == 2)
                    d[i][j] = 2;
                else
                    d[i][j] = d[i+1][j-1] + 2;
            }
            else
                d[i][j] = max(
                    d[i+1][j],
                    d[i][j-1]
                );
        }

        cout<<n-d[1][n]<<"\n";
    }
}