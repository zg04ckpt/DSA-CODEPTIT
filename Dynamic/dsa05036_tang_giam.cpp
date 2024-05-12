#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        double a[n], b[n];
        for(int i=0; i<n; ++i)
            cin>>a[i]>>b[i];

        int d[n];
        for(int i=0; i<n; ++i)
        {
            d[i] = 1;
            for(int j=0; j<i; ++j)
            {
                if(a[i]>a[j] && b[i]<b[j])
                    d[i] = max(d[i], d[j]+1);
            }
        }

        cout<<*max_element(d, d+n)<<"\n"; 
    }
}