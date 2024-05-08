#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[9][9], ans;
bool c[9], c1[18], c2[18];

void tryAt(int i, int score)
{
    for(int j=1; j<=8; ++j)
    {
        if(c[j] || c1[i-j+8] || c2[i+j-1]) continue;
        c[j] = c1[i-j+8] = c2[i+j-1] = 1;

        if(i==8 && score+a[i][j]>ans) 
            ans = score+a[i][j];
        if(i < 8) tryAt(i+1, score+a[i][j]);

        c[j] = c1[i-j+8] = c2[i+j-1] = 0;
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        for(int i=1; i<=8; ++i)
            for(int j=1; j<=8; ++j)
                cin>>a[i][j];
        
        ans = 0;
        tryAt(1, 0);

        cout<<ans<<"\n";
    }
}