#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<char> st;
        int ans = 0;

        for(char c : s)
        {
            if(c == '(') st.push(c);
            else
            {
                if(st.empty())
                {
                    ans++;
                    st.push('(');
                }
                else
                    st.pop();
            }
        }
        cout<<ans + st.size()/2<<"\n";
    }
}