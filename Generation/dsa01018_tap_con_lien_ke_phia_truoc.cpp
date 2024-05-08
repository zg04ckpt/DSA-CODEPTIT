#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[1001], n, k;

void prev()
{
    int i = k;
    while(i && a[i]-a[i-1]==1) i--;

    if(i > 0)
    {
        a[i]--;
        for(int j=i+1; j<=k; ++j)
            a[j] = n-k+j;
    }
    else 
    {
        for(int i=1; i<=k; ++i)
            a[i] = n-k+i;
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1; i<=k; ++i) cin>>a[i];

        prev();

        for(int i=1; i<=k; ++i) cout<<a[i]<<" ";
        cout<<"\n";
    }
}

//DSA with C++ | CODEPTIT | Quay lui - Nhánh cận | 