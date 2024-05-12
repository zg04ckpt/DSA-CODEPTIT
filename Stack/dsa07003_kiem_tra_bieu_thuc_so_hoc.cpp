#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool check(string &s)
{
    stack<char> st;
    for(char c : s)
    {
        if(c>='a' && c<='z') continue;
        if(c != ')') st.push(c);
        else
        {
            if(st.empty() || st.top()=='(')
                return 0;
            
            while(st.size() && st.top()!='(')
                st.pop();
            
            if(st.empty()) return 0;
            st.pop();
        }
    }

    return 1;
}

int main()
{
    int t; cin>>t;
    cin.ignore();
    while(t--)
    {
        string s; getline(cin, s);
        if(check(s)) cout<<"No\n";
        else cout<<"Yes\n";
    }
}

/*
3
((a+b))
(a + (b)/c)
(a + b*(c-d))
*/