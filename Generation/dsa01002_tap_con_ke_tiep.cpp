#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[1001], n, k;

void next()
{
    int i = k;
    while(a[i] == n-k+i) --i;

    if(i != 0)
    {
        a[i]++;
        for(int j=i+1; j<=k; ++j)
        {
            a[j] = a[j-1]+1;
        }
    }
    else
    {
        for(int j=1; j<=k; ++j)
            a[j] = j;
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1; i<=k; ++i) cin>>a[i];

        next();

        for(int i=1; i<=k; ++i) cout<<a[i]<<" ";
        cout<<"\n";
    }
}