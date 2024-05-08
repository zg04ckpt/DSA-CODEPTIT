#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int ans = 0, i = 0;
        while(n)
        {
            while(n >= a[i])
            {
                ans++;
                n -= a[i];
            }
            i++;
        }
        cout<<ans<<"\n";
    }
}