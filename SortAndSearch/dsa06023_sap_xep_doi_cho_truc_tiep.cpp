#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n; cin>>n;
    int a[n];
    for(int &i : a) cin>>i;

    for(int i=0; i<n-1; ++i)
    {
        for(int j=i+1; j<n; ++j)
            if(a[j]<a[i])
                swap(a[i], a[j]);
        cout<<"Buoc "<<i+1<<": ";
        for(int i : a) cout<<i<<" ";
        cout<<"\n";
    }
}