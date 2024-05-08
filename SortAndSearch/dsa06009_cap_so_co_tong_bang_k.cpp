#include<bits/stdc++.h>
#define ll long long

using namespace std;

int count(int a[], int l, int r, int value)
{
    int *it1 = lower_bound(a+l, a+r, value);
    int *it2 = upper_bound(a+l, a+r, value);
    return it2-it1;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        int a[n];
        for(int &i : a) cin>>i;

        sort(a, a+n);

        int ans = 0;
        for(int i=0; i<n-1; i++)
             ans += count(a, i+1, n, k-a[i]);
        
        cout<<ans<<"\n";
    }
}