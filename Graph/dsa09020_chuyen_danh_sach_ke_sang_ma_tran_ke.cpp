#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n; cin>>n;
    int a[n+1][n+1] = {};

    string s; int v;
    cin.ignore();
    for(int u=1; u<=n; ++u)
    {
        getline(cin, s);
        stringstream ss(s);
        while(ss>>v)
            a[u][v] = 1;
    }

    for(int u=1; u<=n; ++u)
    {
        for(int v=1; v<=n; ++v)
            cout<<a[u][v]<<" ";
        cout<<"\n";
    }
}