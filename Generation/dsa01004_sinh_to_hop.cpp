#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[16], n, k;

bool next()
{
    int i = k; 
    while(a[i] == n-k+i) --i;

    if(i != 0)
    {
        a[i]++;
        for(int j=i+1; j<=k; ++j)
            a[j] = a[j-1]+1;
        return 1;
    }
    return 0;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        
        for(int i=1; i<=k; ++i) a[i] = i;

        do 
        {
            for(int i=1; i<=k; ++i) cout<<a[i];
            cout<<" ";
        }
        while(next());

        cout<<"\n";
    }
}