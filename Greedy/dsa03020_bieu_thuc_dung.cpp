#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;

        stack<int> st;
        int ans = 0;
        int cnt = 0; //đếm sl ngoặc dúng đã xóa giữa 2 ngoặc ko hợp lệ
        for(char c : s)
        {
            if(st.empty())
            {
                cnt = 0;
                st.push(c);
            }
            else if(st.top()=='[' && c==']')
            {
                st.pop();
                cnt += 2;
            }
            else if(st.top()==']' && c=='[')
            {
                ans += st.size() + cnt;
                st.pop();
            }
            else st.push(c);
        }

        cout<<ans<<"\n";
    }
}