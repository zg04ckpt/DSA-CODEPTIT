#include<bits/stdc++.h>
#define ll long long

using namespace std;

int m = 1e9+7;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int &i : a) cin>>i;
        sort(a, a+n);

        ll sum = 0;
        for(int i=0; i<n; i++)
            sum = (sum + a[i]*i)%m;
        
        cout<<sum<<"\n";
    }
}