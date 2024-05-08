#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, B[20];
bool isOdd;

bool next()
{
    int i = n;
    while(B[i] == 1)
    {
        B[i] = 0;
        i--;
    }

    if(i != 0)
    {
        B[i] = 1;
        return 1;
    }
    return 0;
}

void print()
{
    if(!isOdd)
    {
        for(int i=1; i<=n; ++i) cout<<B[i]<<" ";
        for(int i=n; i>=1; --i) cout<<B[i]<<" ";
    }
    else
    {
        for(int i=1; i<=n; ++i) cout<<B[i]<<" ";
        cout<<0<<" ";
        for(int i=n; i>=1; --i) cout<<B[i]<<" ";
        
        cout<<"\n";

        for(int i=1; i<=n; ++i) cout<<B[i]<<" ";
        cout<<1<<" ";
        for(int i=n; i>=1; --i) cout<<B[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    cin>>n;
    isOdd = n%2;
    n /= 2;

    do print();
    while(next());
}