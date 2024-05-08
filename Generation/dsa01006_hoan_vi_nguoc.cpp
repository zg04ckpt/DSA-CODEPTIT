#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s = "";
        for(int i=1; i<=n; ++i)
        {
            s += to_string(i);
        }

        vector<string> ans;
        do ans.push_back(s);
        while(next_permutation(s.begin(), s.end()));

        for(int i=ans.size()-1; i>=0; i--)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}