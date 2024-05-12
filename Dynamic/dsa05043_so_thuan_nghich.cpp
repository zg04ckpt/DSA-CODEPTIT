#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int n = s.size();
        s = " " + s;

        int ans = 0, l, r;
        for(int i=1; i<=n; ++i)
        {
            l = i-1;
            r = i+1;
            while(l>=1 && r<=n && s[l]==s[r])
            {
                l--;
                r++;
            }
            ans = max(ans, r-l-1);

            l = i-1;
            r = i;
            while(l>=1 && r<=n && s[l]==s[r])
            {
                l--;
                r++;
            }
            ans = max(ans, r-l-1);
        }

        cout<<ans<<"\n";
    }
}