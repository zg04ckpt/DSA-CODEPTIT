#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n; cin>>n;
    int a[n];
    for(int &i : a) cin>>i;
    multiset<int> st;

    for(int i=0; i<n; ++i)
    {
        st.insert(a[i]);
        cout<<"Buoc "<<i<<": ";
        for(int j : st) cout<<j<<" ";
        cout<<"\n";
    }
}