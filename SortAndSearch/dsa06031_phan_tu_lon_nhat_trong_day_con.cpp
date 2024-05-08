#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        int a[n];
        for(int &i : a) cin>>i;

        multiset<int> w;
        for(int i=0; i<k; ++i)
            w.insert(a[i]);
        cout<<*w.rbegin()<<" ";

        for(int i=k; i<n; ++i)
        {
            auto it = w.find(a[i-k]);
            w.erase(it);
            w.insert(a[i]);
            cout<<*w.rbegin()<<" ";
        }

        cout<<"\n";
    }
}