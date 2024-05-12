#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
a + b
+ a b
a b +
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<string> st;
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                st.push("("+ a + s[i] + b + ")");
            }
            else
            {
                st.push(string(1, s[i]));
            }
        }

        cout<<st.top()<<"\n";
    }
}