#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        int a[n], b[m];
        for(int &i : a) cin>>i;
        for(int &i : b) cin>>i;

        int i, j;
        i = j = 0;
        vector<int> u;
        while(i<n && j<m)
        {
            if(a[i] < b[j]) cout<<a[i++]<<" ";
            else if(a[i] > b[j]) cout<<b[j++]<<" ";
            else
            {
                cout<<a[i]<<" ";
                u.push_back(a[i]);
                i++; j++;
            }
        }
        while(i < n) cout<<a[i++]<<" ";
        while(j < m) cout<<b[j++]<<" ";

        cout<<"\n";
        for(int &i : u) cout<<i<<" ";
        cout<<"\n"; 
    }
}