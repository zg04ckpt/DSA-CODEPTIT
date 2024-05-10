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

        int d[n];
        for(int i=0; i<n; ++i)
        {
            d[i] = a[i];
            for(int j=0; j<i; ++j)
            {
                if(a[i] > a[j])
                    d[i] = max(d[i], d[j]+a[i]);
            }
        }

        cout<<*max_element(d, d+n)<<"\n";
    }
}