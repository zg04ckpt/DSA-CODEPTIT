#include<bits/stdc++.h>
#define ll long long

using namespace std;

int x[11], n;
bool check[11];

void print()
{
    for(int i=1; i<=n; ++i) cout<<x[i];
    cout<<"\n";
}

void tryAt(int i, int pre)
{
    for(int j=1; j<=n; ++j)
    {
        if((pre>0 && abs(pre-j)==1) || check[j]) continue;
        x[i] = j;
        check[j] = 1;

        if(i==n) print();
        else tryAt(i+1, j);

        check[j] = 0;
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        tryAt(1, 0);

        memset(check, 0, sizeof check);
    }
}