#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool binSearch(int a[], int n, int v)
{
    int l = 0, r = n-1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(a[m] == v) return 1;
        else if(a[m] < v) l = m+1;
        else r = m-1;
    }
    return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,x; cin>>n>>x;
        int a[n];
        for(int &i : a) cin>>i;

        if(binSearch(a, n, x)) cout<<1<<"\n";
        else cout<<"-1\n";
    }
}