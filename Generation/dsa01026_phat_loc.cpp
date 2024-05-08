#include<bits/stdc++.h>
#define ll long long

using namespace std;

int b[17], n;

void print()
{
    for(int i=1; i<=n; ++i)
    {
        if(b[i] == 0) cout<<6;
        else cout<<8;
    }
    cout<<"\n";
}

void tryAt(int i)
{
    if(i == 1)
    {
        b[i] = 1;
        tryAt(i+1);
        return;
    }

    if(i == n)
    {
        if(!b[i-1] && !b[i-2] && !b[i-3])
            return;

        b[i] = 0;
        print();
        return;
    }

    for(int j=0; j<=1; ++j)
    {
        if(j && b[i-1]) continue;
        if(!j && !b[i-1] && !b[i-2] && !b[i-3]) continue;
        b[i] = j;
        tryAt(i+1);
    }
}

int main()
{
    cin>>n;
    tryAt(1);
}