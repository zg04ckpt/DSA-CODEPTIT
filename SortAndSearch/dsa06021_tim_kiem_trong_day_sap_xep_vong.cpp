#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n, x; cin>>n>>x;
        int a[n];
        for(int &i : a) cin>>i;

        int j=1;
        while(j<n && a[j]>a[j-1]) j++;

        int *it = lower_bound(a, a+j, x);
        if(it == a+j || *it != x)
            it = lower_bound(a+j, a+n, x);
        
        cout<<it-a+1<<"\n";
    }
}