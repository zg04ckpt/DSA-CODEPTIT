#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<string> ans;

        ans.push_back("0");
        ans.push_back("1");

        for(int i=2; i<=n; ++i)
        {
            for(int j=ans.size()-1; j>=0; --j)
            {
                ans.push_back("1" + ans[j]);
                ans[j] = "0" + ans[j];
            }
        }

        for(string &s : ans) cout<<s<<" ";
        cout<<"\n";
    }
}