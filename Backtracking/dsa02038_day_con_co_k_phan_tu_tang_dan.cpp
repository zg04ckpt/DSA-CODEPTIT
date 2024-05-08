#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[16], x[16], n, k;

void print()
{
    for(int i=1; i<=k; ++i)
        cout<<x[i]<<" ";
    cout<<"\n";
}

void tryAt(int i, int pre)
{
    for(int j=pre+1; j<=n; ++j)
    {
        x[i] = a[j];
        if(i == k) print();
        else tryAt(i+1, j);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1; i<=n; ++i) cin>>a[i];
        sort(a+1, a+n+1);
        tryAt(1, 0);
    }
}