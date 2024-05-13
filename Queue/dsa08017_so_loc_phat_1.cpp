#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        queue<string> q;
        q.push("6");
        q.push("8");
        stack<string> st;
        while(q.front().size() <= n)
        {
            string f = q.front(); q.pop();
            st.push(f);
            q.push(f + "6");
            q.push(f + "8");
        }

        while(st.size())
        {
            cout<<st.top()<<" ";
            st.pop();
        }

        cout<<"\n";
    }
}