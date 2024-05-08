#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n; cin>>n;
    int a[n];
    for(int &i : a) cin>>i;

    bool ok = 0;
    int cnt = 1;
    while(!ok)
    {
        ok = 1;
        for(int i=0; i<n-1; i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i], a[i+1]);
                ok = 0;
            }
        }
        if(!ok)
        {
            cout<<"Buoc "<<cnt++<<": ";
            for(int j : a) cout<<j<<" ";
            cout<<"\n";
        }
    }
}