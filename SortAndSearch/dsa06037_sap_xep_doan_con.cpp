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
        for(int &i : a) cin>>i;

        int l[n]; l[0] = a[0]; //tìm max 0->i
        for(int i=1; i<n; ++i)
        {
            if(a[i] > l[i-1]) l[i] = a[i];
            else l[i] = l[i-1];
        }

        int r[n]; r[n-1] = a[n-1]; //tim min i->n-1
        for(int i=n-2; i>=0; i--)
        {
            if(a[i] < r[i+1]) r[i] = a[i];
            else r[i] = r[i+1];
        }

        vector<int> ans;
        for(int i=0; i<n-1; ++i)
        {
            if(l[i] <= r[i+1])
                ans.push_back(i+1);
        }

        cout<<ans.size()<<"\n";
        for(int &v : ans) cout<<v<<" ";
        cout<<"\n";
    }
}