#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, k, a[1001], b[1001], cnt;

void print(int m)
{
    for(int i=1; i<=m; ++i)
    {
        if(b[i]) cout<<a[i]<<" ";
    }
    cout<<"\n";
    cnt++;
}

void tryAt(int i, int preSum)
{
    for(int j=0; j<=1; ++j)
    {
        b[i] = j;
        if(preSum + a[i]*j == k) print(i);
        else if(i < n) tryAt(i+1, preSum + a[i]*j);
    }
}

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; ++i) cin>>a[i];
    tryAt(1, 0);
    cout<<cnt;
}