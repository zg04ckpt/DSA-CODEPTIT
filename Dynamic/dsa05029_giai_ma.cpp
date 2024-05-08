#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i]: số cách giải mã khi bản tin kết thúc 
tại s[i]

d[i] = 0;
1. dùng 1 kí tự => d[i] += d[i-1];
2. dùng 2 kí tự => d[i] += d[i-2];
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int n = s.size();
        s = " " + s;

        int d[n+1] = {};
        d[0] = 1;
        for(int i=1; i<=n; ++i)
        {
            if(s[i]!='0') d[i] += d[i-1];
            if(i<2) continue;
            if(s[i-1]=='1' || s[i-1]=='2'&&s[i]<='6')
                d[i] += d[i-2];
        }

        cout<<d[n]<<"\n";
    }
}