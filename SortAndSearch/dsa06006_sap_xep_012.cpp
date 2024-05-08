#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int c0, c1, c2;
        c0 = c1 = c2 = 0;
        while(n--)
        {
            int e; cin>>e;
            if(e == 0) c0++;
            else if(e == 1) c1++;
            else c2++;
        }

        while(c0--) cout<<0<<" ";
        while(c1--) cout<<1<<" ";
        while(c2--) cout<<2<<" ";

        cout<<"\n";
    }
}