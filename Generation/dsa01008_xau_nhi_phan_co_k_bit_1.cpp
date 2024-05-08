#include<bits/stdc++.h>
#define ll long long

using namespace std;

int b[17], n, k;

void print()
{
    for(int i=1; i<=n; ++i) cout<<b[i];
    cout<<"\n";
}

void tryAt(int i, int cnt)
{
    for(int j=0; j<=1; ++j)
    {
        b[i] = j;
        if(i==n && cnt+j == k) print();
        if(i < n) tryAt(i+1, cnt+j);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        tryAt(1, 0);
    }
}