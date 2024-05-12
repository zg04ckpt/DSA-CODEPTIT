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
        
        int ans[n];
        stack<pair<int,int>> st;
        for(int i=0; i<n; ++i)
        {
            while(st.size() && st.top().first<=a[i])
                st.pop();
            
            if(st.empty()) 
                ans[i] = i+1;
            else
                ans[i] = i-st.top().second;
            
            st.push({a[i], i});
        }

        for(int i=0; i<n; ++i)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
}