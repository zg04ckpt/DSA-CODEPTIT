#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i][j]: số bc it nhất bd xâu str1 độ dài i ->
str2 độ dài j

abcd
abcd
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

        int d[n+1][m+1] = {};
        for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
        {
            if(i == 0)
                d[i][j] = j;
            else if(j == 0)
                d[i][j] = i;
            else if(s1[i] == s2[j])
                d[i][j] = d[i-1][j-1];
            else
                d[i][j] = min({
                    d[i-1][j],
                    d[i][j-1],
                    d[i-1][j-1]
                }) + 1;
        }

        cout<<d[n][m]<<"\n";
    }
}