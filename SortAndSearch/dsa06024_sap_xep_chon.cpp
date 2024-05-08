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
        int *it = min_element(a+i, a+n);
        swap(a[i], a[it-a]);
        cout<<"Buoc "<<i+1<<": ";
        for(int j : a) cout<<j<<" ";
        cout<<"\n";
    }
}