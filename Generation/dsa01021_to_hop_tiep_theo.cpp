#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[40], n, k;

bool next()
{
    int i = k;
    while(a[i] == n-k+i) i--;

    if(i > 0)
    {
        a[i]++;
        for(int j=i+1; j<=k; ++j)
            a[j] = a[j-1]+1;
        return 1;
    }
    return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        bool check[50] = {};
        for(int i=1; i<=k; ++i) 
        {
            cin>>a[i];
            check[a[i]] = 1;
        }

        if(next())
        {
            int ans = 0;
            for(int i = 1; i<=k; ++i)
            {
                if(check[a[i]] == 0) ans++;
            }
            cout<<ans<<"\n";
        }
        else cout<<k<<"\n";
    }
}