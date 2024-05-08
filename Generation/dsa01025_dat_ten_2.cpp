#include<bits/stdc++.h>
#define ll long long

using namespace std;

int x[17], n, k;

void print()
{
    for(int i=1; i<=k; ++i)
        cout<<char('A'+x[i]-1);
    cout<<"\n";
}

void tryAt(int i, int pre)
{
    for(int j = pre+1; j<=n-k+i; ++j)
    {
        x[i] = j;
        if(i == k) print();
        else tryAt(i+1, j);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        tryAt(1, 0);
    }
}