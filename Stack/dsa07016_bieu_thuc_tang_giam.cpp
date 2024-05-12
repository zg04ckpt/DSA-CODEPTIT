#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<string> st;
        int cnt = 2;
        st.push("1");
        for(char c : s)
        {
            if(c == 'I')
                st.push(to_string(cnt));
            else
            {
                string t = st.top(); st.pop();
                t = to_string(cnt) + t;
                st.push(t);
            }
            cnt++;
        }

        string ans = "";
        while(st.size())
        {
            ans = st.top() + ans;
            st.pop();
        }

        cout<<ans<<"\n";
    }
}