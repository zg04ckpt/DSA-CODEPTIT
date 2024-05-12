#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<pair<int,int>> st;
        st.push({')', -1});
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i]==')' && st.top().first=='(')
                st.pop();
            else
                st.push({s[i], i});
        }

        int n = s.size();
        int ans = 0;
        while(st.size())
        {
            ans += n-st.top().second-1;
            n = st.top().second;
            st.pop();
        }

        cout<<ans<<'\n';
    }
}