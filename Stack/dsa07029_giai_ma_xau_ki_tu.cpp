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
        int i = s.size()-1;
        while(i >= 0)
        {
            if(s[i] == ']')
            {
                st.push("]");
                i--;
            }
            else if(isalpha(s[i]))
            {
                st.push(string(1, s[i]));
                i--;
            }
            else if(s[i] == '[')
            {
                string sub = "";
                while(st.top() != "]")
                {
                    sub += st.top();
                    st.pop();
                }
                st.pop();
                st.push(sub);
                i--;
            }
            else
            {
                int end = i;
                while(i>=0 && isdigit(s[i])) i--;
                int num = stoi(s.substr(i+1, end-i));
                string temp = "";
                while(num--) temp += st.top();
                st.pop();
                st.push(temp);
            }
        }

        while(st.size())
        {
            cout<<st.top();
            st.pop();
        }
        cout<<"\n";
    }
}