#include<bits/stdc++.h>
#define ll long long

using namespace std;

int B[11], n;

void print()
{
    for(int i=1; i<=n; ++i) cout<<char(B[i]+'A');
    cout<<" ";
}

void tryAt(int i)
{
    for(int j=0; j<=1; ++j)
    {
        B[i] = j;
        if(i == n) print();
        else tryAt(i+1);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        tryAt(1);
        cout<<"\n";
    }
}