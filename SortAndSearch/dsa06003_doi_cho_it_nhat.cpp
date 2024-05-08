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

        int ans = 0;
        for(int i=0; i<n; ++i)
        {
            int* it = min_element(a+i, a+n);
            if(it != a+i)
            {
                ans++;
                swap(a[i], a[it-a]);
            }
        }

        cout<<ans<<"\n";
    } 
}