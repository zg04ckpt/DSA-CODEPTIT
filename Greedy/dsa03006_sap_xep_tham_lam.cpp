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

        int l,r;
        if(a[0] > a[n-1]) swap(a[0], a[n-1]);
        l = 1, r = n-2;
        while(l < r)
        {
            if(a[l] > a[r]) swap(a[l], a[r]);
            if(a[l-1]>a[l] || a[r]>a[r+1])
                break;
            l++; r--;
        }

        if(l < r) cout<<"No\n";
        else cout<<"Yes\n";
    }
}