#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
1 = 1
12 + 2 = 1*10 + 2*2 = 14
123 + 23 + 3 = 14*10 + 3*3 = 149
1234 + 234 + 34 + 4 = 149*10 + 4*4
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int n = s.size();
        s = " " + s;

        ll d[n+1] = {};
        ll sum = 0;
        for(int i=1; i<=n; ++i)
        {
            d[i] = d[i-1]*10 + (s[i]-'0')*i;
            sum += d[i];
        }

        cout<<sum<<"\n";
    }
}