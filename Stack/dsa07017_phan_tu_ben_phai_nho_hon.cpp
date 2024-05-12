#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; ++i) 
            cin>>a[i];

        stack<int> st;
        int mi[n];
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && st.top()>=a[i])
                st.pop();
            
            if(st.empty()) mi[i] = -1;
            else mi[i] = st.top();

            st.push(a[i]);
        }

        stack<pair<int,int>> st2;
        int ans[n];
        for(int i=n-1; i>=0; i--)
        {
            while(st2.size() && st2.top().first<=a[i])
                st2.pop();
            
            if(st2.empty()) ans[i] = -1;
            else ans[i] = st2.top().second;

            st2.push({a[i], mi[i]});
        }

        for(int i=0; i<n; ++i) 
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
}