#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[9][9], n;
bool ok;

void tryAt(int i, int j, string s)
{
    if(!a[i][j]) return;
    if(i==n && j==n)
    {
        cout<<s<<" ";
        ok = 1;
        return;
    }

    a[i][j] = 0;

    if(i != n) tryAt(i+1, j, s+'D');
    if(j != 1) tryAt(i, j-1, s+'L');
    if(j != n) tryAt(i, j+1, s+'R');
    if(i != 1) tryAt(i-1, j, s+'U');

    a[i][j] = 1;
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