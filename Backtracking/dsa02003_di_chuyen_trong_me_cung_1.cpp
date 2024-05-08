#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[11][11], n;
bool ok;

void tryAt(int i, int j, string x)
{
    if(!a[i][j]) return;

    if(i==n && j==n)
    {
        cout<<x<<" ";
        ok = 1;
        return;
    }
    
    if(i != n) tryAt(i+1, j, x + 'D');
    if(j != n) tryAt(i, j+1, x + 'R');
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                cin>>a[i][j];
        
        ok = 0;
        tryAt(1, 1, "");

        if(!ok) cout<<"-1";
        cout<<"\n";
    }
}