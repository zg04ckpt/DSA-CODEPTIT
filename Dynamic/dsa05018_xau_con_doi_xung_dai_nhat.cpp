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

        int l, r, ans = 0;
        for(int i=0; i<n; ++i)
        {
            l = i-1;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            ans = max(ans, r-l-1);

            l = i-1;
            r = i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            ans = max(ans, r-l-1);
        } 

        cout<<ans<<"\n";
    }
}