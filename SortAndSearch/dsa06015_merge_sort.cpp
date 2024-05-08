#include<bits/stdc++.h>
#define ll long long

using namespace std;

void merge(int a[], int l, int m, int r)
{
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i,j,k;
    i = j = 0;
    k = l;
    while(i<x.size() && j<y.size())
    {
        if(x[i] < y[j]) a[k++] = x[i++];
        else a[k++] = y[j++];
    }
    while(i<x.size()) a[k++] = x[i++];
    while(j<y.size()) a[k++] = y[j++];
}

void split(int a[], int l, int r)
{
    if(l >= r) return;
    int m = (l+r)/2;
    split(a, l, m);
    split(a, m+1, r);
    merge(a, l, m, r);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int &i : a) cin>>i;
        split(a, 0, n-1);
        for(int i : a) cout<<i<<" ";
        cout<<"\n";
    }
}