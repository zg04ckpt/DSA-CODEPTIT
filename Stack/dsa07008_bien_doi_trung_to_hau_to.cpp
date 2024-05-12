#include<bits/stdc++.h>
#define ll long long

using namespace std;

int check(char c)
{
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<char> st;
        string res = "";
        for(char c : s)
        {
            if(c == '(')
            {
                st.push(c);
            }
            else if(c == ')')
            {
                while(st.size() && st.top()!='(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(check(c))
            {
                while(st.size() && check(st.top()) >= check(c))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
            else
            {
                res += c;
            }
        }

        while(st.size())
        {
            res += st.top();
            st.pop();
        }

        cout<<res<<"\n";
    }
}