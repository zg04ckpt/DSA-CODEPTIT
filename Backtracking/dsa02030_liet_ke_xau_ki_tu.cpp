#include<bits/stdc++.h>
#define ll long long

using namespace std;

int x[27], n, k;

void print()
{
    for(int i=1; i<=k; ++i) 
        cout<<char('A'+x[i]-1);
    cout<<"\n";
}

void tryAt(int i, int pre)
{
    for(int j=pre; j<=n; ++j)
    {
        x[i] = j;
        if(i == k) print();
        else tryAt(i+1, j);
    }
}

int main()
{
    char c; cin>>c>>k;
    n = c-'A'+1;
    tryAt(1, 1);
}