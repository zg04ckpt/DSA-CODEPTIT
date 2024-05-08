#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        set<int> st;
        while(n--)
        {
            int e; cin>>e;
            st.insert(e);
        }

        int cnt = *st.rbegin() - *st.begin() + 1;
        cout << cnt-st.size()<<"\n";
    }
}