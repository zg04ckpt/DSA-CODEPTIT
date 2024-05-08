#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll cnt;

void merge(ll a[], int l, int m, int r)
{
    vector<ll> x(a+l, a+m+1);
    vector<ll> y(a+m+1, a+r+1);
    int i = 0;
    int j = 0;
    int k = l;
    while(i<x.size() && j<y.size())
    {
        if(x[i] > y[j])
        {
            a[k++] = y[j++];
            cnt += x.size()-i;
        }
        else a[k++] = x[i++];
    }
    while(i<x.size()) a[k++] = x[i++];
    while(j<y.size()) a[k++] = y[j++];
}

void merge_sort(ll a[], int l, int r)
{
    if(l >= r) return;
    int m = (l+r)/2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    merge(a, l, m, r);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        ll a[n];
        for(ll &i : a) cin>>i;

        cnt = 0;
        merge_sort(a, 0, n-1);

        cout<<cnt<<"\n";
    }
}