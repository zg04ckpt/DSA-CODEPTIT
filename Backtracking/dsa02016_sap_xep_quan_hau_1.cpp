#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, cnt;
bool column[11], cheoChinh[20], cheoPhu[20];

void tryAt(int i)
{
    for(int j=1; j<=n; ++j)
    {
        if(column[j]||cheoChinh[i-j+n]||cheoPhu[i+j-1])
            continue;
        
        column[j] = cheoChinh[i-j+n] = cheoPhu[i+j-1] = 1;
        
        if(i == n) cnt++;
        else tryAt(i+1);

        column[j] = cheoChinh[i-j+n] = cheoPhu[i+j-1] = 0;
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;

        cnt = 0;
        tryAt(1);

        cout<<cnt<<"\n";

        memset(column, 0, sizeof column);
        memset(cheoChinh, 0, sizeof cheoChinh);
        memset(cheoPhu, 0, sizeof cheoPhu);
    }
}